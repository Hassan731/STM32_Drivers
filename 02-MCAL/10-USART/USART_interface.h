/************************************/
/* Author      : Hassan Mahmoud     */
/* Version     : V01                */
/* Date        : 19 SEP 2020        */
/************************************/

#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

void MUSART1_voidInit(void);
void MUSART1_voidTransmit(u8 arr[]);
u8   MUSART1_u8Receive(void);



#endif