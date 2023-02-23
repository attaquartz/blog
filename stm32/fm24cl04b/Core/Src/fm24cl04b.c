#include "main.h"

extern I2C_HandleTypeDef hi2c1;

/**
  * @param  Addr: I2C Address
  * @param  Reg: Reg Address 
  * @param  pBuffer: pointer to read data buffer
  * @param  Length: length of the data
  * @retval HAL status
  */
HAL_StatusTypeDef FM24CL04B_ReadBuffer(uint8_t Addr, uint16_t Reg, uint8_t *pBuffer, uint16_t Length)
{
  HAL_StatusTypeDef status = HAL_ERROR;

  status = HAL_I2C_Mem_Read(&hi2c1, Addr, Reg, I2C_MEMADD_SIZE_8BIT, pBuffer, Length, 1000);

  /* Check the communication status */
  if(status != HAL_OK)
  {
    /* Re-Initialize the BUS */
  }
  
  return status;
}

/**
  * @param  Addr: Device address on BUS Bus.  
  * @param  Reg: The target register address to write
  * @param  pBuffer: The target register value to be written 
  * @param  Length: buffer size to be written
  * @retval HAL status
  */
HAL_StatusTypeDef FM24CL04B_WriteBuffer(uint8_t Addr, uint16_t Reg, uint8_t *pBuffer, uint16_t Length)
{
  HAL_StatusTypeDef status = HAL_ERROR;
  
  status = HAL_I2C_Mem_Write(&hi2c1, Addr, Reg, I2C_MEMADD_SIZE_8BIT, pBuffer, Length, 1000);

  /* Check the communication status */
  if(status != HAL_OK)
  {
    /* Re-Initialize the BUS */
  }

  return status;
}

HAL_StatusTypeDef Read_FRAM(uint16_t Reg, uint8_t *pBuffer, uint16_t Length)
{
  HAL_StatusTypeDef status = HAL_ERROR;
  
  uint8_t DevAddress = FM24CL04B_I2C_ADDR;
  
  DevAddress |= 0x01;
  
  if((HIGHBYTE(Reg) & 0x01) == 1)
  {
    DevAddress |= FM24CL04B_PAGE1;
  }
    status = FM24CL04B_ReadBuffer(DevAddress, Reg, pBuffer, Length);
  
  return status;
}

HAL_StatusTypeDef Write_FRAM(uint16_t Reg, uint8_t *pBuffer, uint16_t Length)
{
  HAL_StatusTypeDef status = HAL_ERROR;
  
  uint8_t DevAddress = FM24CL04B_I2C_ADDR;
  
  if((HIGHBYTE(Reg) & 0x01) == 1)
  {
    DevAddress |= FM24CL04B_PAGE1;
  }
    status = FM24CL04B_WriteBuffer(DevAddress, Reg, pBuffer, Length);
  
  return status;
}
