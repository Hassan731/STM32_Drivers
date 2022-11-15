/************************************/
/* Author      : Hassan Mahmoud     */
/* Version     : V01                */
/* Date        : 16 SEP 2020        */
/************************************/

#include "STD_Types.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void MSPI1_voidInit(void)
{
	SPI_Registers -> CR1 = 0x
	
}
void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceive)
{
	/* Clear For Slave Select Pin */
	MGPIO_VidSetPinValue(MSPI1_SLAE_PIN, LOW);
	
	/* Send Data */
	MSPI1 -> DR = Copy_u8DataToTransmit;
	
	/* Wait Busy Flag to Finish */
	while (GET_BIT(MSPI1 - >SR, 7) == 1);
	
	/* Return to the received Data */
	*Copy_DataToReceive = MSPI1 -> DR;
		
	
	/* Set Slave Select Pin */
	MGPIO_VidSetPinValue(MSPI1_SLAE_PIN, HIGH);
	
	
}

void SPI1_IRQHandler()
{
	
}
