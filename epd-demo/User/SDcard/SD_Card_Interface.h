
#ifndef __SD_CARD_INTERFACE_H__
#define __SD_CARD_INTERFACE_H__

#include "DEV_Config.h"

void SD_IO_Init(void);
void SD_IO_CSState(uint8_t val);
void SD_IO_WriteReadData(const uint8_t *DataIn, uint8_t *DataOut, uint16_t DataLength);
uint8_t SD_IO_WriteByte(uint8_t Data);
void SD_IO_ReadData(uint8_t *DataOut, uint16_t DataLength);
void SD_IO_WriteData(const uint8_t *Data, uint16_t DataLength);

#endif
