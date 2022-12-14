/***********************************/
/* Author      : Hassan Mahmoud    */
/* Version     : V01               */
/* Date        : 8 Aug 2020        */
/***********************************/


#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB  0
#define RCC_APB1 1
#define RCC_APB2 2

void RCC_voidInitSysClocck(void);
void RCC_voidDisableClock(u8 Copy_u8BusID, u8 Copy_u8PerID );
void RCC_voidEnableClock(u8 Copy_u8BusID, u8 Copy_u8PerID );


#endif