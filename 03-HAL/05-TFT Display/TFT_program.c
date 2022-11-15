/************************************/
/* Author      : Hassan Mahmoud     */
/* Version     : V01                */
/* Date        : 21 SEP 2020        */
/************************************/

#include "STD_Types.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

void HTFT_voidInit(void)
{
	/* Reset Pulse */
	MGPIO_voidSetPinValue(TFT_RST_PIN, HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN, LOW);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(TFT_RST_PIN, HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN, LOW);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN, HIGH);
	MSTK_voidSetBusyWait(120000);
	
	/* Sleep Out Command */
	voidWriteCommand(0x11);
	
	/* Wait 150 ms */
	MSTK_voidSetBusyWait(150000);
	
	/* Color Mode Command */
	voidWriteCommand(0x3A);
	voidWriteData   (0x05);
	
	/* Dispaly On Command */
	voidWriteCommand(0x29);
	
}
void HTFT_voidDispalyImage(const u16* Copy_Image)
{
	/* Set X Address */
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127);
	
	/* Set Y Address */
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);
	
	/* RAM Write */
	voidWriteCommand(0x2C);
	
	for (u16 counter = 0 ; counter < 20480; counter++)
	{
		voidWriteData(Copy_Image[counter] >> 8);        /* High Byte */
		voidWriteData(Copy_Image[counter] & 0x00ff);    /* LOW  Byte */
		
	}
	
}

static void voidWriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8Temp;
	/* Set A0 Pin to LOW */
	MGPIO_voidSetPinValue(TFT_A0_PIN, LOW);
	
	/* Send Command over SPI */
	MSPI1_voidSendReceiveSynch(Copy_u8Command, &Local_u8Temp);
	
}

static void voidWriteData(u8 Copy_u8Data)
{
	/* Set A0 Pin to HIGH */
	MGPIO_voidSetPinValue(TFT_A0_PIN, HIGH);
	
	/* Send Data over SPI */
	MSPI1_voidSendReceiveSynch(Copy_u8Data, &Local_u8Temp);
}

void HTFT_voidFillColor(u16 Copy_u16Color)
{
	/* Set X Address */
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127);
	
	/* Set Y Address */
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);
	
	/* RAM Write */
	voidWriteCommand(0x2C);
	
	for (u16 counter = 0 ; counter < 20480; counter++)
	{
		voidWriteData(Copy_u16Color >> 8);        /* High Byte */
		voidWriteData(Copy_u16Color & 0x00ff);    /* LOW  Byte */
		
	}
	
}

void HTFT_voidDrawRect(u8 x1, u8 x2, u8 y1, u8 y2 u16 Copy_u16Color)
{
	u16 size = (x2 - x1) * (y2 - y1);
	
	/* Set X Address */
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(x1);
	voidWriteData(0);
	voidWriteData(x2);
	
	/* Set Y Address */
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(y1);
	voidWriteData(0);
	voidWriteData(y2);
	
	/* RAM Write */
	voidWriteCommand(0x2C);
	
	for (u16 counter = 0 ; counter < size; counter++)
	{
		voidWriteData(Copy_u16Color >> 8);        /* High Byte */
		voidWriteData(Copy_u16Color & 0x00ff);    /* LOW  Byte */
		
	}
	
}