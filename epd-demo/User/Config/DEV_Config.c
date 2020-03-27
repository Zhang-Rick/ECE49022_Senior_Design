/*****************************************************************************
* | File      	:	DEV_Config.cpp
* | Author      : Waveshare team
* | Function    :
* | Info        :
*   Image scanning
*      Please use progressive scanning to generate images or fonts
*----------------
* |	This version:   V1.0
* | Date        :   2018-01-11
* | Info        :   Basic version
*
******************************************************************************/
#include "DEV_Config.h"
#include "stm32f1xx_hal_spi.h"
#include "usart.h"
#include "spi.h"

#include <errno.h>
#include <stdio.h>
#include <string.h>

extern SPI_HandleTypeDef hspi2;

/******************************************************************************
function:	Initialize Arduino, Initialize Pins, and SPI
parameter:
Info:
******************************************************************************/
UBYTE DEV_Module_Init(void)
{
    SD_CS_1;
    SPIRAM_CS_1;
	
    return 0;
}

/*********************************************
function:	Hardware interface
note:
	SPI4W_Write_Byte(value) : 
		Register hardware SPI
*********************************************/	
void DEV_SPI_WriteByte(UBYTE value)
{
    HAL_SPI_Transmit(&hspi2, &value, 1, 1000);
}

UBYTE DEV_SPI_ReadByte(void)
{
	UBYTE value;
	HAL_SPI_Receive(&hspi2, &value, 1, 1000);
	return value;
} 

/******************************************************************************
function:	Analog microsecond delay
parameter:
Info:
******************************************************************************/
void DEV_Delay_us(UWORD xus)
{
    for(int j=xus; j > 0; j--);
}
