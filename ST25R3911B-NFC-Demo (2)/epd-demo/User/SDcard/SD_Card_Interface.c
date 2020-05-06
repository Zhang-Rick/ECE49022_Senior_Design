
/* Includes ------------------------------------------------------------------*/
#include "SD_Card_Interface.h"
#include "spi.h"

/**
  * @brief LINK SD Card
  */
#define SD_DUMMY_BYTE            0xFF
#define SD_NO_RESPONSE_EXPECTED  0x80

/**
  * @brief  Set the SD_CS pin.
  * @param  pin value.
  */
void SD_IO_CSState(uint8_t val)
{
    if(val == 1) {
        HAL_GPIO_WritePin(SD_CS_GPIO_Port, SD_CS_Pin, GPIO_PIN_SET);
    } else {
        HAL_GPIO_WritePin(SD_CS_GPIO_Port, SD_CS_Pin, GPIO_PIN_RESET);
    }
}

/**
  * @brief  Write byte(s) on the SD
  * @param  DataIn: Pointer to data buffer to write
  * @param  DataOut: Pointer to data buffer for read data
  * @param  DataLength: number of bytes to write
  */
void SD_IO_WriteReadData(const uint8_t *DataIn, uint8_t *DataOut, uint16_t DataLength)
{
    HAL_StatusTypeDef status = HAL_OK;

    status = HAL_SPI_TransmitReceive(&hspi2, (uint8_t*) DataIn, DataOut, DataLength, 1000);

    /* Check the communication status */
    if(status != HAL_OK) {
        /* Execute user timeout callback */
        MX_SPI2_Init();
    }
}

/**
  * @brief  Write a byte on the SD.
  * @param  Data: byte to send.
  * @retval Data written
  */
uint8_t SD_IO_WriteByte(uint8_t Data)
{
    uint8_t tmp;
    HAL_StatusTypeDef status = HAL_OK;

    /* Send the byte */
    status = HAL_SPI_TransmitReceive(&hspi2, &Data, &tmp, 1, 1000);

    /* Check the communication status */
    if(status != HAL_OK) {
        /* Execute user timeout callback */
        MX_SPI2_Init();
    }

    return tmp;
}

/**
  * @brief  Write an amount of data on the SD.
  * @param  Data: byte to send.
  * @param  DataLength: number of bytes to write
  */
void SD_IO_ReadData(uint8_t *DataOut, uint16_t DataLength)
{
    /* Send the byte */
    SD_IO_WriteReadData(DataOut, DataOut, DataLength);
}

/**
  * @brief  Write an amount of data on the SD.
  * @param  Data: byte to send.
  * @param  DataLength: number of bytes to write
  */
void SD_IO_WriteData(const uint8_t *Data, uint16_t DataLength)
{
    HAL_StatusTypeDef status = HAL_OK;

    /* Send the byte */
    status = HAL_SPI_Transmit(&hspi2, (uint8_t *)Data, DataLength, 1000);

    /* Check the communication status */
    if(status != HAL_OK) {
        /* Execute user timeout callback */
        MX_SPI2_Init();
    }
}


