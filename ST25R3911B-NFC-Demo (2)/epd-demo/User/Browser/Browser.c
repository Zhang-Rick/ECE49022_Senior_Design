#include "Browser.h"

DIR dir;
FILINFO fileinfo;	//File information
FRESULT res;
char filename[20][50];		//	File num,File name lenght
int browser_cursor=0,browser_paper=0;	//Browser pages
char* pstr;
char 	type[20];		//File Type
uint8_t file_sel=0;		//Selected files	
uint8_t key_flag=0;
uint8_t	Interface_flag=0;
uint8_t file_num=0;
uint8_t fail_num=0;
uint8_t size_flag=0;
extern uint8_t flag_300ms;
/* Back Flag*/
extern uint8_t doBack_flag;  
#if _USE_LFN
    char lfn[20];           
#endif
void Browser_paper_clean_half(void)
{	uint8_t i=0,j=0;
	for(i=0;i<128;i++)
	{
		for(j=0;j<48;j++)
		{
				ssd1306_draw_point(i,j, 0);
		}
	}
}
void Browser_paper_clean_full(void)
{	uint8_t i=0,j=0;
	for(i=0;i<128;i++)
	{
		for(j=0;j<64;j++)
		{
				ssd1306_draw_point(i,j, 0);
		}
	}
}
unsigned char	Browser_save_fileame(unsigned char* path)
{
	uint8_t num=0;
	res=f_opendir(&dir,(const TCHAR*)path);
	
		#if _USE_LFN
						fileinfo.lfname=lfn;
						fileinfo.lfsize = sizeof(lfn);
		#endif	
		if (res == FR_OK) 
		{	
			printf("\r\n"); 
			while(1)
			{
				res = f_readdir(&dir, &fileinfo);                   //Read a file in the directory
				if (res != FR_OK || fileinfo.fname[0] == 0) break;  //Exit if there is an error or if it reaches the end
				pstr=strrchr(*fileinfo.lfname ? fileinfo.lfname : fileinfo.fname,'.');				
				if(pstr==NULL)continue;				//Skip without suffix names
				pstr++;
				strcpy(type,pstr);
				if(strcasecmp(pstr,"BMP")==0)
				{
					strcpy(filename[num],*fileinfo.lfname ? fileinfo.lfname : fileinfo.fname);
					printf("<%d>:  ", num);//Print the path	
					printf("%s\r\n",  filename[num]);//Print file name	 
					num++;
				}
			} 
		 }
		return num;  	//Return file number
}
void Browser_display(void)
{	
	/********************Read key value******************/		
	key_flag=ReadKey();
	if(Interface_flag==0)
	{	
		/********************Display Function Options*****************/
		Browser_paper_clean_full();
		if(browser_cursor==0)
			ssd1306_display_string(0, 13,"NFC Test Demo", 12, 0);
		else 
			ssd1306_display_string(0, 13,"NFC Test Demo", 12, 1);
		if(browser_cursor==1)
			ssd1306_display_string(0, 25,"Update E-paper Demo", 12, 0);
		else 
			ssd1306_display_string(0, 25,"Update E-paper Demo", 12, 1);
		/********************Display basic interface******/
		ssd1306_display_string(0, 0,"Select Demo", 12, 1);
		ssd1306_draw_line(0,11,128,0);
		ssd1306_draw_bitmap(0, 48, c_chFont1608[95], 8, 16);
		ssd1306_display_string(10, 50,"UP", 12, 1);
		ssd1306_draw_bitmap(28, 48, c_chFont1608[96], 8, 16);
		ssd1306_display_string(38, 50,"DOWN", 12, 1);
		ssd1306_draw_bitmap(63, 52, c_chFont1608[97], 16, 8);
		ssd1306_display_string(77, 50,"BACK", 12, 1);
		ssd1306_draw_bitmap(102, 52, c_chFont1608[98], 16, 8);
		ssd1306_display_string(116, 52,"OK", 12, 1);
		ssd1306_draw_line(0,48,128,0);
		ssd1306_refresh_gram();
				/********************Key handler******/
		if(key_flag!=0)
			{		
				if(key_flag==1)					//Up
				{	browser_cursor--;
					if(browser_cursor<0)
					{		browser_cursor=1;
					}
				}
				else if(key_flag==2)					//Down
				{	browser_cursor++;
					if(browser_cursor>1)
					{
						browser_cursor=0;
					}
				}
				if(key_flag==4)
				{
					if(browser_cursor==0)
					{		
						Browser_paper_clean_full();
						ssd1306_display_string(20,24,"NFC reding test", 12, 1);
						ssd1306_draw_line(0,11,128,0);
						ssd1306_draw_bitmap(18, 52, c_chFont1608[97], 16, 8);
						ssd1306_display_string(32, 50,"BACK", 12, 1);
						ssd1306_draw_bitmap(63, 48, c_chFont1608[95], 8, 16);
						ssd1306_display_string(74, 50,"WakeUP", 12, 1);
						ssd1306_draw_line(0,48,128,0);
						ssd1306_refresh_gram();
						while(1)
						{	
							rfalWorker();
							demoCycle();				//Enter NFC Test Demo
							if(doBack_flag==1)
							{
								doBack_flag=0;
								break;
							}
						}
					}
					else if(browser_cursor==1)
						Interface_flag++;							//Next interface
					browser_cursor=0;
				}
		}
	}
	else if(Interface_flag==1)
	{
		/********************Display E-paper Size Options*****************/
		Browser_paper_clean_full();
		if(browser_cursor==0)
			ssd1306_display_string(10, 13,"2.13 inch e-paper", 12, 0);
		else if(browser_cursor!=3)
			ssd1306_display_string(10, 13,"2.13 inch e-paper", 12, 1);
		if(browser_cursor==1)
			ssd1306_display_string(10, 25,"2.9  inch e-paper", 12, 0);
		else if(browser_cursor!=3)
			ssd1306_display_string(10, 25,"2.9  inch e-paper", 12, 1);
		if(browser_cursor==2)
			ssd1306_display_string(10, 37,"4.2  inch e-paper", 12, 0);
		else if(browser_cursor!=3)
			ssd1306_display_string(10, 37,"4.2  inch e-paper", 12, 1);
		if(browser_cursor==3)
			ssd1306_display_string(10, 13,"7.5  inch e-paper", 12, 0);
		/********************Display basic interface******/
		ssd1306_display_string(0, 0,"Select E-paper Size", 12, 1);
		ssd1306_draw_line(0,11,128,0);
		ssd1306_draw_bitmap(0, 48, c_chFont1608[95], 8, 16);
		ssd1306_display_string(10, 50,"UP", 12, 1);
		ssd1306_draw_bitmap(28, 48, c_chFont1608[96], 8, 16);
		ssd1306_display_string(38, 50,"DOWN", 12, 1);
		ssd1306_draw_bitmap(63, 52, c_chFont1608[97], 16, 8);
		ssd1306_display_string(77, 50,"BACK", 12, 1);
		ssd1306_draw_bitmap(102, 52, c_chFont1608[98], 16, 8);
		ssd1306_display_string(116, 52,"OK", 12, 1);
		ssd1306_draw_line(0,48,128,0);
		ssd1306_refresh_gram();
		/********************Key handler******/
		if(key_flag!=0)
			{		
				if(key_flag==1)					//Up
				{	browser_cursor--;
					if(browser_cursor<0)
					{		browser_cursor=3;
					}
				}
				else if(key_flag==2)					//Down
				{	browser_cursor++;
					if(browser_cursor>3)
					{
						browser_cursor=0;
					}
				}
				else if(key_flag==3)					//Down
				{
					browser_cursor=0;
					Interface_flag--;							//Next interface
				}
				if(key_flag==4)
				{
					Interface_flag++;							//Next interface
					size_flag=browser_cursor;			//Selected E-paper Size
					browser_cursor=0;
				}
		}
	}
	else if(Interface_flag==2)
	{	
		/********************Display file*****************/	

		Browser_paper_clean_full();
		file_sel=browser_paper*3+browser_cursor;
		if(browser_cursor==0)
			ssd1306_display_string(10, 13,filename[browser_paper*3], 12, 0);
		else
			ssd1306_display_string(10, 13,filename[browser_paper*3], 12, 1);
		if(browser_cursor==1)
			ssd1306_display_string(10, 25,filename[browser_paper*3+1], 12, 0);
		else
			ssd1306_display_string(10, 25,filename[browser_paper*3+1], 12, 1);
		if(browser_cursor==2)
			ssd1306_display_string(10, 37,filename[browser_paper*3+2], 12, 0);
		else
			ssd1306_display_string(10, 37,filename[browser_paper*3+2], 12, 1);
		/********************Display basic interface******/
		ssd1306_display_string(0, 0,"Select BMP Picture", 12, 1);
		ssd1306_draw_line(0,11,128,0);
		ssd1306_draw_bitmap(0, 48, c_chFont1608[95], 8, 16);
		ssd1306_display_string(10, 50,"UP", 12, 1);
		ssd1306_draw_bitmap(28, 48, c_chFont1608[96], 8, 16);
		ssd1306_display_string(38, 50,"DOWN", 12, 1);
		ssd1306_draw_bitmap(63, 52, c_chFont1608[97], 16, 8);
		ssd1306_display_string(77, 50,"BACK", 12, 1);
		ssd1306_draw_bitmap(102, 52, c_chFont1608[98], 16, 8);
		ssd1306_display_string(116, 52,"OK", 12, 1);
		ssd1306_draw_line(0,48,128,0);
		ssd1306_refresh_gram();
		/********************Key handler******/
		if(key_flag!=0)
			{		
				if(key_flag==1)					//up
				{	browser_cursor--;
					if(browser_cursor<0)
					{		browser_cursor=2;
							browser_paper--;	
							if(browser_paper<0)
							{	browser_paper=file_num/3;
								browser_cursor=file_num%3-1;
							}
					}
				}
				else if(key_flag==2)					//down
				{	browser_cursor++;
					if((browser_paper*3+browser_cursor)>=file_num)			//Last file
					{
						browser_cursor=0;
						browser_paper=0;
					}
					else if(browser_cursor>2)
					{
						browser_cursor=0;
						if((browser_paper*3-1)<file_num)
							browser_paper++;	
						else
						{
							browser_paper=0;
						}
					}
				}
				else if(key_flag==3)				//back
				{
					browser_cursor=0;
					Interface_flag--;							//Last interface
				}
				else if(key_flag==4)
				{
					Interface_flag++;							//Next interface
					Browser_paper_clean_full();
					ssd1306_display_string(10, 8,"Whether to go ahead and make a choice?", 12, 1);
					ssd1306_draw_bitmap(23, 52, c_chFont1608[97], 16, 8);
					ssd1306_display_string(37, 50,"BACK", 12, 1);
					ssd1306_draw_bitmap(72, 52, c_chFont1608[98], 16, 8);
					ssd1306_display_string(86, 52,"OK", 12, 1);
					ssd1306_refresh_gram();
				}
				key_flag=0;
		}
	}
	else if(Interface_flag==3)						//Confirmation interface
	{
				if(key_flag==3)
				{
					Interface_flag--;							//Previous interface
					Browser_paper_clean_full();
					/********************Display basic interface******/
					ssd1306_draw_bitmap(0, 48, c_chFont1608[95], 8, 16);
					ssd1306_display_string(10, 50,"UP", 12, 1);
					ssd1306_draw_bitmap(28, 48, c_chFont1608[96], 8, 16);
					ssd1306_display_string(38, 50,"DOWN", 12, 1);
					ssd1306_draw_bitmap(63, 52, c_chFont1608[97], 16, 8);
					ssd1306_display_string(77, 50,"BACK", 12, 1);
					ssd1306_draw_bitmap(102, 52, c_chFont1608[98], 16, 8);
					ssd1306_display_string(116, 52,"OK", 12, 1);
					ssd1306_draw_line(0,48,128,0);
				}
				else if(key_flag==4)
				{
					Interface_flag++;							//Next interface
				}
				key_flag=0;
	}
	else if(Interface_flag==4)						//Start drawing interface
	{
		  /*show sd card pic*/
    //1.Initialize the SD card
			while(1)
		{
			if(!SDCard_Init())
			{	LED_RED_1;
				Browser_paper_clean_full();
				ssd1306_display_string(26, 16,"SD Card Error!", 12, 1);
				ssd1306_display_string(0,28,"Please press any key to try again.", 12, 1);
				ssd1306_refresh_gram();
			}
			else 
			{	LED_RED_0;
				Browser_paper_clean_full();
				ssd1306_display_string(5, 16,"Reading BMP picture    data from RAM...", 12, 1);
				ssd1306_refresh_gram();
				break;
			}
			while(!ReadKey());
		}

    //2.Read BMP pictures into RAM
    SDCard_ReadBMP(filename[file_sel], 0, 0);
		/* Open TIM3 Interrupt */	
		HAL_TIM_Base_Start_IT(&htim3); 
		Interface_flag++;
		Browser_paper_clean_full();
		ssd1306_display_string(5, 16,"Please approach the e-paper or press back     key to exit.", 12, 1);
		ssd1306_refresh_gram();
	}
	else if(Interface_flag==5)
	{	
	//3.Refresh the picture in RAM to e-Paper
		if(flag_300ms==1)
		{
			rfalFieldOff();
			flag_300ms=0;
			LED_GREEN_1;
		}
		else if(flag_300ms==2)
		{
			Start_Dawring();
			flag_300ms=0;
			LED_GREEN_0;
		}
		if(key_flag==3)
		{	
			LED_GREEN_0;
			Interface_flag=2;
		}
	}
		
}
void Read_RAM(uint16_t i,uint8_t *l)
{
	uint8_t j;
	if(size_flag<2)
	{
		for(j=0;j<16;j++)
		{
			l[3+j]=SPIRAM_RD_Byte(i*16+j);
		}
	}
	if(size_flag==2)
	{
			for(j=0;j<100;j++)
		{
			l[3+j]=SPIRAM_RD_Byte(i*100+j);
		}
	}
	else if(size_flag==3)
	{
			for(j=0;j<120;j++)
		{
			l[3+j]=SPIRAM_RD_Byte(i*120+j);
		}
	}
}
void fail_interface(void)
{	
	Browser_paper_clean_full(); 
	ssd1306_display_string(26,8,"Update failed", 12, 1);
	ssd1306_display_string(0,24,"Please press any key to exit and try again", 12, 1);
	ssd1306_refresh_gram();
}
uint8_t Start_Dawring(void)
{	
	ReturnCode        err;
  uint8_t           devIt = 0;
  rfalNfcaSensRes   sensRes;
	uint8_t						step=0,progress=0;
	uint8_t						step0[2]={0xcd,0x0d};				
  uint8_t						step1[3]={0xcd,0x00,10};				//select e-paper type and reset e-paper  						4:2.13inch e-Paper   7:2.9inch e-Paper  10:4.2inch e-Paper  14:7.5inch e-Paper
	uint8_t						step2[2]={0xcd,0x01};						//e-paper normal mode  type£º
	uint8_t						step3[2]={0xcd,0x02};						//e-paper config1
	uint8_t						step4[2]={0xcd,0x03};						//e-paper power on	
	uint8_t						step5[2]={0xcd,0x05};						//e-paper config2
	uint8_t						step6[2]={0xcd,0x06};						//EDP load to main
	uint8_t						step7[2]={0xcd,0x07};						//Data preparation
	uint8_t						step8[123]={0xcd,0x08,0x64};		//Data start command			2.13inch(0x10:Send 16 data at a time)    2.9inch(0x10:Send 16 data at a time)     4.2inch(0x64:Send 100 data at a time)  7.5inch(0x78:Send 120 data at a time)
	uint8_t						step9[2]={0xcd,0x18};					//e-paper power on
	uint8_t						step10[2]={0xcd,0x09};					//Refresh e-paper
	uint8_t						step11[2]={0xcd,0x0a};					//wait for ready
	uint8_t						step12[2]={0xcd,0x04};					//e-paper power off command
//	uint8_t						step13[2]={0xcd,0x0b};					//Judge whether the power supply is turned off successfully
//	uint8_t						step14[2]={0xcd,0x0c};					//The end of the transmission
	uint8_t						rx[20];
	char							Progress[4]={0,0,'%','\0'};
	uint16_t					actrxlen[20],i=0;
	
  rfalNfcaPollerInitialize();   /* Initialize for NFC-A */
  rfalFieldOnAndStartGT();      /* Turns the Field On if not already and start GT timer */

  err = rfalNfcaPollerTechnologyDetection( RFAL_COMPLIANCE_MODE_NFC, &sensRes );
  if(err == ERR_NONE) 
  {
    rfalNfcaListenDevice nfcaDevList[1];
    uint8_t                   devCnt;

    err = rfalNfcaPollerFullCollisionResolution( RFAL_COMPLIANCE_MODE_NFC, 1, nfcaDevList, &devCnt);

    if ( (err == ERR_NONE) && (devCnt > 0) ) 
    {
      devIt = 0;
       Browser_paper_clean_full(); 
      /* Check if it is Topaz aka T1T */
      if( nfcaDevList[devIt].type == RFAL_NFCA_T1T ) 
      {
        /********************************************/
        /* NFC-A T1T card found                     */
        /* NFCID/UID is contained in: t1tRidRes.uid */
        printf("ISO14443A/Topaz (NFC-A T1T) TAG found. UID: %s\r\n", hex2Str(nfcaDevList[devIt].ridRes.uid, RFAL_T1T_UID_LEN));	
				ssd1306_display_string(10,24,"E-paper detected", 12, 1);
				ssd1306_refresh_gram();
      }
      else
      {
        /*********************************************/
        /* NFC-A device found                        */
        /* NFCID/UID is contained in: nfcaDev.nfcId1 */
        printf("ISO14443A/NFC-A card found. UID: %s\r\n", hex2Str(nfcaDevList[0].nfcId1, nfcaDevList[0].nfcId1Len));
				ssd1306_display_string(15, 24,"E-paper detected.", 12, 1);
				ssd1306_refresh_gram();
      }
			while(1)
		{			
						if(step==0)
				{		printf("Step0");	
						rfalTransceiveBlockingTxRx(step0,2,rx,20,actrxlen,RFAL_TXRX_FLAGS_DEFAULT,2157+2048);										//cd 0d																						
						if(HAL_GPIO_ReadPin(GREEN_LED_GPIO_Port,GREEN_LED_Pin))
							LED_GREEN_0;
						else
							LED_GREEN_1;
						if(rx[0]==0&&rx[1]==0)
						{	rx[0]=1;rx[1]=1;
							step=1;
							printf("Step1\r\n");	
						}
					else
					{
						fail_num++;
						if(fail_num>10)
						{
							printf("Update failed, please press any key to exit and try again.\r\n");
							fail_interface();
							LED_RED_1;
							step=14;
							fail_num=0;
							DEV_Delay_ms(200);
						}
					}
				}
				else if(step==1)
				{		Browser_paper_clean_full(); 
						if(size_flag==0)					//2.13inch
						{
							step1[2]=4;
							step8[2]=16;
						}
						else if(size_flag==1)			//2.9inch
						{	
							step1[2]=7;
							step8[2]=16;
						}
						else if(size_flag==2)			//4.2inch
						{
							step1[2]=10;
							step8[2]=100;
						}
						else if(size_flag==3)			//7.5inch
						{
							step1[2]=14;
							step8[2]=120;
						}
						rfalTransceiveBlockingTxRx(step1,3,rx,20,actrxlen,RFAL_TXRX_FLAGS_DEFAULT,2157+2048);										//cd 00   
						ssd1306_display_string(20, 24,"E-paper config", 12, 1);
						ssd1306_refresh_gram();
						if(rx[0]==0&&rx[1]==0)
						{rx[0]=1;rx[1]=1;
							step=2;
							printf("Step2\r\n");	
							fail_num=0;
						}
						else
						{
							fail_num++;
							if(fail_num>10)
							{
								printf("Update failed, please press any key to exit and try again.\r\n");
								fail_interface();
								step=14;
								fail_num=0;
								DEV_Delay_ms(200);
								LED_RED_1;
							}
						}
						DEV_Delay_ms(10);
				}
				else if(step==2)
				{
						rfalTransceiveBlockingTxRx(step2,2,rx,20,actrxlen,RFAL_TXRX_FLAGS_DEFAULT,2157+2048);										//cd 01
						if(rx[0]==0&&rx[1]==0)
						{	rx[0]=1;rx[1]=1;
							step=3;
							printf("Step3\r\n");	
							fail_num=0;
						}
						else
						{
							fail_num++;
							if(fail_num>50)
							{
								printf("Update failed, please press any key to exit and try again.\r\n");
								fail_interface();
								step=14;
								fail_num=0;
								DEV_Delay_ms(200);
								LED_RED_1;
							}
						}
						DEV_Delay_ms(100);
				}
				else if(step==3)
				{
						rfalTransceiveBlockingTxRx(step3,2,rx,20,actrxlen,RFAL_TXRX_FLAGS_DEFAULT,2157+2048);										//cd 02
						if(rx[0]==0&&rx[1]==0)	
						{
							rx[0]=1;rx[1]=1;
							step=4;
							printf("Step4\r\n");
							fail_num=0;
						}
						else
						{
							fail_num++;
							if(fail_num>10)
							{
								printf("Update failed, please press any key to exit and try again.\r\n");
								fail_interface();
								step=14;
								fail_num=0;
								DEV_Delay_ms(200);
								LED_RED_1;
							}
						}
					DEV_Delay_ms(200);
				}
				else if(step==4)
				{
						rfalTransceiveBlockingTxRx(step4,2,rx,20,actrxlen,RFAL_TXRX_FLAGS_DEFAULT,2157+2048);										//cd 03
						if(rx[0]==0&&rx[1]==0){
							rx[0]=1;rx[1]=1;
							step=5;
							printf("Step5\r\n");
							fail_num=0;
						}
						else
						{
							fail_num++;
							if(fail_num>10)
							{
								printf("Update failed, please press any key to exit and try again.\r\n");
								fail_interface();
								step=14;
								fail_num=0;
								DEV_Delay_ms(200);
								LED_RED_1;
							}
						}
					DEV_Delay_ms(500);
				}
				else if(step==5)
				{
						rfalTransceiveBlockingTxRx(step5,2,rx,20,actrxlen,RFAL_TXRX_FLAGS_DEFAULT,2157+2048);										//cd 05
							if(rx[0]==0&&rx[1]==0){
								rx[0]=1;rx[1]=1;
								step=6;
								printf("Step6\r\n");
								fail_num=0;
							}
							else
							{
								fail_num++;
								if(fail_num>30)
								{
									printf("Update failed, please press any key to exit and try again.\r\n");
									fail_interface();
									step=14;
									fail_num=0;
									DEV_Delay_ms(200);
									LED_RED_1;
								}
							}
							DEV_Delay_ms(10);
				}
				else if(step==6)
				{
						rfalTransceiveBlockingTxRx(step6,2,rx,20,actrxlen,RFAL_TXRX_FLAGS_DEFAULT,2157+2048);										//cd 06
					if(rx[0]==0&&rx[1]==0){	
					rx[0]=1;rx[1]=1;
						step=7;
						printf("Step7\r\n");
						fail_num=0;
					}
					else
					{
						fail_num++;
						if(fail_num>10)
						{
							printf("Update failed, please press any key to exit and try again.\r\n");
							fail_interface();
							step=14;
							fail_num=0;
							DEV_Delay_ms(200);
							LED_RED_1;
						}
					}
				}
				else if(step==7)
				{		Browser_paper_clean_full(); 
						rfalTransceiveBlockingTxRx(step7,2,rx,20,actrxlen,RFAL_TXRX_FLAGS_DEFAULT,2157+2048);										//cd 07
						ssd1306_display_string(5,16,"Start data transfer", 12, 1);
						ssd1306_refresh_gram();
						if(rx[0]==0&&rx[1]==0){
						rx[0]=1;rx[1]=1;
						step=8;
						printf("Step8\r\n");
						fail_num=0;
						}
						else
						{
							fail_num++;
							if(fail_num>10)
							{
								printf("Update failed, please press any key to exit and try again.\r\n");
								fail_interface();
								step=14;
								fail_num=0;
								DEV_Delay_ms(200);
								LED_RED_1;
							}
						}
				}
				else if(step==8)																																													//cd 08
				{		Browser_paper_clean_full(); 
						if(size_flag==0)							//2.13inch
					 {
							for(i=0;i<250;i++)
							{	rx[0]=1;rx[1]=1;
								Read_RAM(i,step8);
								rfalTransceiveBlockingTxRx(step8,19,rx,20,actrxlen,RFAL_TXRX_FLAGS_DEFAULT,2157+2048);
								progress=i*99/250;
								printf("Proress: %d %%\r\n", progress);
								Progress[0]=progress/10%10+'0';
								Progress[1]=progress/1%10+'0';
								ssd1306_display_string(40,16,"Progress:", 12, 1);
								ssd1306_display_string(58,32,Progress, 12, 1);
								ssd1306_refresh_gram();
								if(HAL_GPIO_ReadPin(GREEN_LED_GPIO_Port,GREEN_LED_Pin))
									LED_GREEN_0;
								else
									LED_GREEN_1;
							}
					 }
					 else if(size_flag==1)
					 {
						 for(i=0;i<296;i++)
							{	rx[0]=1;rx[1]=1;
								Read_RAM(i,step8);
								rfalTransceiveBlockingTxRx(step8,19,rx,20,actrxlen,RFAL_TXRX_FLAGS_DEFAULT,2157+2048);
								progress=i*99/296;
								printf("Proress: %d %%\r\n", progress);
								Progress[0]=progress/10%10+'0';
								Progress[1]=progress/1%10+'0';
								ssd1306_display_string(40,16,"Progress:", 12, 1);
								ssd1306_display_string(58,32,Progress, 12, 1);
								ssd1306_refresh_gram();
								if(HAL_GPIO_ReadPin(GREEN_LED_GPIO_Port,GREEN_LED_Pin))
									LED_GREEN_0;
								else
									LED_GREEN_1;
							}
					 }
					 else if(size_flag==2)					//4.2inch
						{
							for(i=0;i<150;i++)
							{	rx[0]=1;rx[1]=1;
								Read_RAM(i,step8);
								rfalTransceiveBlockingTxRx(step8,103,rx,20,actrxlen,RFAL_TXRX_FLAGS_DEFAULT,2157+2048);
								progress=i*99/150;
								printf("Proress: %d %%\r\n", progress);
								Progress[0]=progress/10%10+'0';
								Progress[1]=progress/1%10+'0';
								ssd1306_display_string(40,16,"Progress:", 12, 1);
								ssd1306_display_string(58,32,Progress, 12, 1);
								ssd1306_refresh_gram();
								if(HAL_GPIO_ReadPin(GREEN_LED_GPIO_Port,GREEN_LED_Pin))
									LED_GREEN_0;
								else
									LED_GREEN_1;
							}
						}
						else if(size_flag==3)			//7.5inch
						{
								for(i=0;i<400;i++)
							{	rx[0]=1;rx[1]=1;
								Read_RAM(i,step8);
								rfalTransceiveBlockingTxRx(step8,123,rx,20,actrxlen,RFAL_TXRX_FLAGS_DEFAULT,2157+2048);
								progress=i*99/400;
								printf("Proress: %d %%\r\n", progress);
								Progress[0]=progress/10%10+'0';
								Progress[1]=progress/1%10+'0';
								ssd1306_display_string(40,16,"Progress:", 12, 1);
								ssd1306_display_string(58,32,Progress, 12, 1);
								ssd1306_refresh_gram();
								if(HAL_GPIO_ReadPin(GREEN_LED_GPIO_Port,GREEN_LED_Pin))
									LED_GREEN_0;
								else
									LED_GREEN_1;
							}
						}
						rx[0]=1;rx[1]=1;
						step=9;
						printf("Step9\r\n");
				}
				else if(step==9)
				{		
						rfalTransceiveBlockingTxRx(step9,2,rx,20,actrxlen,RFAL_TXRX_FLAGS_DEFAULT,2157+2048);										//cd 18
						if(rx[0]!=0||rx[1]!=0)
							{
								fail_num++;
								if(fail_num>10)
								{
									printf("Update failed, please press any key to exit and try again.\r\n");
									fail_interface();
									step=14;
									fail_num=0;
									DEV_Delay_ms(500);
									LED_RED_1;
								}
							}
							else
								fail_num=0;
						rx[0]=1;rx[1]=1;
						step=10;
						printf("Step10\r\n");
				}
				else if(step==10)
				{
						rfalTransceiveBlockingTxRx(step10,2,rx,20,actrxlen,RFAL_TXRX_FLAGS_DEFAULT,2157+2048);										//cd 09
						if(rx[0]!=0||rx[1]!=0)
							{
								fail_num++;
								if(fail_num>10)
								{
									printf("Update failed, please press any key to exit and try again.\r\n");
									fail_interface();
									step=14;
									fail_num=0;
									DEV_Delay_ms(500);
									LED_RED_1;
								}
							}
							else
								fail_num=0;
						rx[0]=1;rx[1]=1;
						step=11;
						printf("Step11\r\n");
					DEV_Delay_ms(200);
				}
				else if(step==11)
				{		Browser_paper_clean_full(); 
						while(1)
						{	rx[0]=1;rx[1]=1;
							rfalTransceiveBlockingTxRx(step11,2,rx,20,actrxlen,RFAL_TXRX_FLAGS_DEFAULT,2157+2048);										//cd 0a
							Browser_paper_clean_full(); 
							if(rx[0]==0xff&&rx[1]==0)
							{
								printf("E-paper Reflash OK\r\n");
								ssd1306_display_string(10,16,"E-paper Reflash OK", 12, 1);
								ssd1306_refresh_gram();
								fail_num=0;
								step=12;
								printf("Step12\r\n");
								DEV_Delay_ms(200);
								break;
							}
							else
							{
								if(fail_num>70)
								{
									printf("Update failed, please press any key to exit and try again.\r\n");
									fail_interface();
									step=14;
									fail_num=0;
									DEV_Delay_ms(500);
									LED_RED_1;
									break;
								}
								else
								{	fail_num++;
									printf("E-paper Reflashing, Waiting\r\n");
									ssd1306_display_string(8,16,"E-paper Reflashing,        Waiting...", 12, 1);
									DEV_Delay_ms(100);
									ssd1306_refresh_gram();
								}

							}			
						}
					
				}
				else if(step==12)
				{
						rfalTransceiveBlockingTxRx(step12,2,rx,20,actrxlen,RFAL_TXRX_FLAGS_DEFAULT,2157+2048);										//cd 04
						rx[0]=1;rx[1]=1;
						step=13;
						printf("Step13\r\n");
						DEV_Delay_ms(200);
				}
				else if(step==13)
				{		
						rx[0]=1;rx[1]=1;
						step=14;
						printf("Step13\r\n");
						printf("E-paper UPdate OK\r\n");
						printf("Press any key to exit\r\n");
						Browser_paper_clean_full(); 
						ssd1306_display_string(0,32,"Press any key to exit", 12, 1);
						ssd1306_display_string(10,16,"E-paper UPdate OK", 12, 1);
						ssd1306_refresh_gram();
						DEV_Delay_ms(200);
				}
				else if(step==14)
				{	
					rfalFieldOff();
					key_flag=ReadKey();
					if(key_flag!=0)
					{
						LED_RED_0;
						LED_GREEN_0;
						step=0;
						Interface_flag=1;
						return 1;
					}
					
				}
				
				if(step==14||HAL_GPIO_ReadPin(GREEN_LED_GPIO_Port,GREEN_LED_Pin))
						LED_GREEN_0;
					else
						LED_GREEN_1;
			}
    }
  }
	return 0;
}
