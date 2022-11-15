/************************************/
/* Author      : Hassan Mahmoud     */
/* Version     : V01                */
/* Date        : 28 SEP 2020        */
/************************************/

#include "STD_Types.h"
#include "BIT_MATH.h"

#include "USART_interface.h"

#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"
 
 
 void ESP_voidInit(void)
 {
	 u8 Local_u8Result = 0;
	 
	 while(Local_u8Result == 0)
	 {
	/* Echo Disabled */
	MUSART1_voidTransmit("ATE0\r\n");
	Local_u8Result = voidESPValidateCmd();    /* check ok recieved */
	
	/*u8 x = MUSART1_voidReceive();
	while(x != 'ok');*/
	
	 }
	/* Set station Mode */
	while(Local_u8Result == 0)
	{
	MUSART1_voidTransmit("AT+CWMODE=1\r\n");
	Local_u8Result = voidESPValidateCmd();
	}
 }
 
u8 voidESPValidateCmd(void)
{
	u8 Local_u8Response[100] = {0};
	u8 i =0;
	u8 Dummy = 0;
	u8 Result = 0;
	
	while(Dummy != 255)
	{
			Dummy = MUSART1_voidReceive();
			Local_u8Response = MUSART1_voidReceive();
			i++;
		
	}
	/* Check if Ok */
	if (Local_u8Response[0] == '0' && Local_u8Response[1] == 'k')
	{
		Result = 1;
	}
}

u8   MUSART1_u8Receive(void)
{
	u16 timeout = 0;
	u8 Loc_u8ReceivedData = 0;
	while((GET_BIT((MUSART1 -> SR), 5)) == 0)
	{
		timeout++
		if(timeout == 10000)
		{
				Loc_u8ReceivedData = 255;
				break;
			
		}
		
	}
	if ()Loc_u8ReceivedData == 0)
	{
		
	}
	while((MUSART1 -> SR ) & 0x20 == 0);
	return (0xFF & (MUSART -> DR));
	
}