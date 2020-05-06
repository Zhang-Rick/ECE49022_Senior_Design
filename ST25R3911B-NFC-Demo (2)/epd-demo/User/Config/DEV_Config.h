/*****************************************************************************
* | File      	: DEV_Config.h
* | Author      : Waveshare team
* | Function    :	debug with prntf
* | Info        :
*   Image scanning
*      Please use progressive scanning to generate images or fonts
*----------------
* |	This version:   V1.0
* | Date        :   2018-01-11
* | Info        :   Basic version
*
******************************************************************************/
#ifndef _DEV_CONFIG_H_
#define _DEV_CONFIG_H_

#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include <stdint.h>
#include "main.h"
/**
 * data
**/
#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t

#define EPD_RST_PIN     EPD_RST_GPIO_Port, EPD_RST_Pin
#define EPD_DC_PIN      EPD_DC_GPIO_Port, EPD_DC_Pin
#define EPD_CS_PIN      EPD_CS_GPIO_Port, EPD_CS_Pin
#define EPD_BUSY_PIN    EPD_BUSY_GPIO_Port, EPD_BUSY_Pin

/**
 * GPIO read and write
**/
#define DEV_Digital_Write(_pin, _value) HAL_GPIO_WritePin(_pin, _value == 0? GPIO_PIN_RESET:GPIO_PIN_SET)
#define DEV_Digital_Read(_pin) HAL_GPIO_ReadPin(_pin)


/**
 * delay x ms
**/
#define DEV_Delay_ms(__xms) HAL_Delay(__xms);

/**
 * SPI RAM
**/
#define SPIRAM_CS_0		HAL_GPIO_WritePin(SPIRAM_CS_GPIO_Port, SPIRAM_CS_Pin, GPIO_PIN_RESET)
#define SPIRAM_CS_1		HAL_GPIO_WritePin(SPIRAM_CS_GPIO_Port, SPIRAM_CS_Pin, GPIO_PIN_SET)

/**
 * SD Card
**/
#define SD_CS_0		HAL_GPIO_WritePin(SD_CS_GPIO_Port, SD_CS_Pin, GPIO_PIN_RESET)
#define SD_CS_1		HAL_GPIO_WritePin(SD_CS_GPIO_Port, SD_CS_Pin, GPIO_PIN_SET)

/**
 * LED
**/
#define LED_GREEN_0		HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, GPIO_PIN_RESET)
#define LED_GREEN_1		HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, GPIO_PIN_SET)

#define LED_RED_0		HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_RESET)
#define LED_RED_1		HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_SET)
/**
 * OLED GPIO
**/
#define OLED_CS_0		HAL_GPIO_WritePin(OLED_CS_GPIO_Port,OLED_CS_Pin, GPIO_PIN_RESET)
#define OLED_CS_1		HAL_GPIO_WritePin(OLED_CS_GPIO_Port,OLED_CS_Pin, GPIO_PIN_SET)

#define OLED_DC_0		HAL_GPIO_WritePin(OLED_DC_GPIO_Port,OLED_DC_Pin, GPIO_PIN_RESET)
#define OLED_DC_1		HAL_GPIO_WritePin(OLED_DC_GPIO_Port,OLED_DC_Pin, GPIO_PIN_SET)

#define OLED_RES_0		HAL_GPIO_WritePin(OLED_RES_GPIO_Port,OLED_RES_Pin, GPIO_PIN_RESET)
#define OLED_RES_1		HAL_GPIO_WritePin(OLED_RES_GPIO_Port,OLED_RES_Pin, GPIO_PIN_SET)

/**
 * KEY
**/
#define Key_UP			HAL_GPIO_ReadPin(KEY_UP_GPIO_Port,KEY_UP_Pin)
#define Key_DOWN		HAL_GPIO_ReadPin(KEY_DOWN_GPIO_Port,KEY_DOWN_Pin)
#define Key_BACK		HAL_GPIO_ReadPin(KEY_BACK_GPIO_Port,KEY_BACK_Pin)
#define Key_OK			HAL_GPIO_ReadPin(KEY_OK_GPIO_Port,KEY_OK_Pin)

UBYTE DEV_Module_Init(void);
void DEV_Module_Exit(void);

void DEV_SPI_WriteByte(UBYTE value);
UBYTE DEV_SPI_ReadByte(void);

void DEV_Delay_us(UWORD xus);


#endif
