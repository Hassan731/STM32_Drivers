/************************************/
/* Author      : Hassan Mahmoud     */
/* Version     : V01                */
/* Date        : 19 SEP 2020        */
/************************************/

#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

typedef struct 
{
	volatile u32 SR  ;
	volatile u32 DR  ;
	volatile u32 BRR ;
	volatile u32 CR1 ;
	volatile u32 CR2 ;
	volatile u32 CR3 ;
	volatile u32 GTPR;
	
}MUSART_Registers;

#define MUSART1 ((volatile MUSART_Registers *)0x40013800)

#endif