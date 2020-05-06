/*****************************************************************************
* | File        :   EPD_SDCard.h
* | Author      :   Waveshare Team
* | Function    :   Show SDcard BMP picto e-paper
* | Info        :
*   Image scanning
*      Please use progressive scanning to generate images or fonts
*----------------
* | This version:   V1.0
* | Date        :   2018-01-11
* | Info        :   Basic version
*
******************************************************************************/
#ifndef __SD_CARD_APP_H__
#define __SD_CARD_APP_H__

#include "DEV_Config.h"
#include "GUI_Paint.h"

#define  MAX_BMP_FILES  25

#pragma pack(1) /* Mandatory to remove any padding */
typedef struct {
    UBYTE  B;
    UBYTE  M;
    UDOUBLE fsize;
    UWORD res1;
    UWORD res2;
    UDOUBLE offset;
    UDOUBLE Bit_Pixel;
    UDOUBLE BMP_Width;
    UDOUBLE BMP_Height;
    UWORD planes;
    UWORD bpp;
    UDOUBLE ctype;
    UDOUBLE dsize;
    UDOUBLE hppm;
    UDOUBLE vppm;
    UDOUBLE colorsused;
    UDOUBLE colorreq;
} BMP_HEADER;
//extern BMP_HEADER *BMP_Header;

uint8_t SDCard_Init(void);
void SDCard_ReadBMP(const char *BmpName, UWORD Xstart, UWORD Ystart);

#endif


