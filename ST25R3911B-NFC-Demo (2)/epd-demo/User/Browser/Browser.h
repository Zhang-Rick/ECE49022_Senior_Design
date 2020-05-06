
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _Browser_H
#define _Browser_H


/* Includes ------------------------------------------------------------------*/
#include "SSD1306.h"
#include "string.h"
#include "fatfs.h"
#include "Fonts.h"
#include "Key.h"
#include "GUI_Paint.h"
#include "SD_Card_APP.h"
#include "stdbool.h"
#include "rfal_rf.h"
#include "rfal_nfca.h"
#include "tim.h"
#include "demo.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
uint8_t	Browser_save_fileame(uint8_t * path);
void Browser_display(void);
uint8_t Start_Dawring(void);
#endif
