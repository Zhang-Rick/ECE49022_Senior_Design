/*****************************************************************************
* | File        :   SD_Card_APP.cpp
* | Author      :   Waveshare team
* | Function    :   Read the BMP file in the SD card and parse it
* | Info        :
*----------------
* | This version:   V1.0
* | Date        :   2018-01-11
* | Info        :   Basic version
*
******************************************************************************/
#include "SD_Card_APP.h"
#include "Debug.h"
#include "ff.h"
#include "ff_gen_drv.h"
#include "user_diskio.h"
#include "stdlib.h"

//char* pDirectoryFiles[MAX_BMP_FILES];
extern char USERPath[4];   /* USER logical drive path */
extern FATFS USERFatFS;    /* File system object for USER logical drive */
extern FIL USERFile;       /* File object for USER */
FILINFO USERFileInfo;
DIR USERDirectory;

/******************************************************************************
function:	Mount SD card
parameter:
Info:
    If the initialization fails, stop the game until the
    initialization is successful
******************************************************************************/
uint8_t SDCard_Init(void)
{
    FRESULT f_res;
//    uint32_t counter = 0;

    if(FATFS_LinkDriver(&USER_Driver, USERPath) == 0) {
        /* 1.Initialize the SD mounted */
        if(BSP_SD_Init() != MSD_OK) {
            DEBUG("SD card initialization failed, check if SD card is inserted.\r\n");
            return 0;
        } else {
            DEBUG("SD card initialization successful..\r\n");
        }

        /* 2.Check the mounted device */
        f_res = f_mount(&USERFatFS, (TCHAR const*)"/", 1);
        if(f_res != FR_OK) {
            DEBUG("SD card mount file system failed ,error code :(%d)\r\n",f_res);
            return 0;
        } else {
            DEBUG("SD card mount file system success!! \r\n");
            /* Initialize the Directory Files pointers (heap) */
//            for (counter = 0; counter < MAX_BMP_FILES; counter++) {
//                pDirectoryFiles[counter] = malloc(11);
//            }
        }
    } else {
        DEBUG("FATFS_LinkDriver error\r\n");
					return 0;
    }

    /* 3.Enter the directory */
    f_res = f_opendir(&USERDirectory, "/");
    if((f_res != FR_OK)) {
        if(f_res == FR_NO_FILESYSTEM) {
            /* Display message: SD card not FAT formated */
            DEBUG("SD card not FAT formated\r\n");
        } else {
            /* Display message: Fail to open directory */
            DEBUG("Fail to open directory\r\n");
        }
        DEBUG("SD card mount file system failed ,error code :(%d)\r\n",f_res);
        return 0;
    } else {
        DEBUG("file open \r\n");
    }
		return 1;
}

/******************************************************************************
function:	Read BMP image data to SPIRAM
parameter:
    BmpName : BMP picture name,
    Xstart : x starting position
    Ystart: Y starting position
Info:
    If the initialization fails, stop the game until the initialization is successful
******************************************************************************/
void SDCard_ReadBMP(const char *BmpName, UWORD Xstart, UWORD Ystart)
{
    FIL bmpfile;
    UINT BytesRead;
    UBYTE BMP_Headinfo[sizeof(BMP_HEADER)];//52
    BMP_HEADER* pbmpheader = (BMP_HEADER*)BMP_Headinfo;

    /* 1.Open file read file header */
    if(f_open(&bmpfile, BmpName, FA_READ) == FR_OK) {
        DEBUG("open bmp file: %s\r\n", BmpName);
    } else {
        DEBUG("No file found: %s\r\n", BmpName);
        return;
    }
    f_read(&bmpfile, BMP_Headinfo, sizeof(BMP_HEADER), &BytesRead);

    if(pbmpheader->B == 0x4D && pbmpheader->M == 0x42) { //0x4d42
        DEBUG("the file is not bmp\r\n");
        return;
    }
    DEBUG("file size =  %d \r\n", pbmpheader->fsize);
    DEBUG("file offset =  %d \r\n", pbmpheader->offset);

    /* 2.Get BMP file data pointer */
    f_lseek(&bmpfile, pbmpheader->offset);

    UWORD X, Y;
    UWORD Image_Width_Byte = (pbmpheader->BMP_Width % 8 == 0)? (pbmpheader->BMP_Width / 8): (pbmpheader->BMP_Width / 8 + 1);
    UWORD Bmp_Width_Byte = (Image_Width_Byte % 4 == 0) ? Image_Width_Byte: ((Image_Width_Byte / 4 + 1) * 4);

    UBYTE ReadBuff[1] = {0};

    /* 3.Write data into RAM */
    for(Y = Ystart; Y < pbmpheader->BMP_Height; Y++) {//Total display column
        for(X = Xstart / 8; X < Bmp_Width_Byte; X++) {//Show a line in the line
            f_read(&bmpfile, ReadBuff, 1, (UINT *)&BytesRead);
            if(X < Image_Width_Byte) { //bmp
                if(Paint_Image.Image_Color == IMAGE_COLOR_POSITIVE) {
                    SPIRAM_WR_Byte(X + (pbmpheader->BMP_Height - Y - 1) * Image_Width_Byte + Paint_Image.Image_Offset, ReadBuff[0]);
                } else {
                    SPIRAM_WR_Byte(X + (pbmpheader->BMP_Height - Y - 1) * Image_Width_Byte + Paint_Image.Image_Offset, ~ReadBuff[0]);
                }
            }
        }
    }

    f_close(&bmpfile);

}
