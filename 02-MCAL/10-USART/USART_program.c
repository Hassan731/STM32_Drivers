/************************************/
/* Author      : Hassan Mahmoud     */
/* Version     : V01                */
/* Date        : 19 SEP 2020        */
/************************************/

#include "STD_Types.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

void MUSART1_voidInit(void)
{
	/* 9600   baud rate , BRR = 0x341 */
	MUSART1 -> BRR = 0x341;
	
	/* 115200 baud rate , BRR = */
	/* 
		1- Enable RX
		2- Enable TX
		3- Enable USART
	*/
		SET_BIT(MUSART1 -> CR1, 2);
		SET_BIT(MUSART1 -> CR1, 3);
		SET_BIT(MUSART1 -> CR1, 13);
		
		/* Clear Status Register */
		MUSART1 -> SR = 0;
		
}
void MUSART1_voidTransmit(u8 arr[])
{
	unsigned int i = 0;
	while(arr[i] != '\0')
	{
		MUSART -> DR = arr[i];
		/*while(GET_BIT(MUSART1 -> SR, 6) == 0);*/
		while((MUSART1 -> SR ) & 0x40 == 0);
		i++;
	}
	
}
u8   MUSART1_u8Receive(void)
{
	/*while(GET_BIT(MUSART1 -> SR, 5) == 0);*/
	while((MUSART1 -> SR ) & 0x20 == 0);
	return (0xFF & (MUSART -> DR));
	
}