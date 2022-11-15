/***********************************/
/* Author      : Hassan Mahmoud    */
/* Version     : V01               */
/* Date        : 24 Aug 2020       */
/***********************************/

#include "STD_Types.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LED_private.h"
#include "LED_config.h"
#include "LED_interface.h"

void HLED_voidLedOn(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
	MGPIO_voidSetPinValue (Copy_u8PortId, Copy_u8PinId, HIGH);
	
}

void HLED_voidLedOff(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
	MGPIO_voidSetPinValue (Copy_u8PortId, Copy_u8PinId, LOW);
}

