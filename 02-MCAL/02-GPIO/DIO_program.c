/************************************/
/* Author      : Hassan Mahmoud     */
/* Version     : V01                */
/* Date        : 12 Aug 2020        */
/************************************/

#include "STD_Types.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void MGPIO_voidSetPinDirection (u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8MODE){
	
	switch(copy_u8PORT)
	{
		case GPIOA :
					if(copy_u8PIN <= 7)
					{
						GPIOA_CRL &= ~ ((0b1111) << copy_u8PIN * 4);
						GPIOA_CRL |=   ((copy_u8MODE) << copy_u8PIN * 4);

					}
					else if (copy_u8PIN <= 15)
					{
						GPIOA_CRH &= ~ ((0b1111) << (copy_u8PIN-8)*4);
						GPIOA_CRH |=   ((copy_u8MODE) << (copy_u8PIN-8)*4);
					}
					break;
		case GPIOB :
					if(copy_u8PIN <= 7)
					{
						GPIOB_CRL &= ~ ((0b1111) << copy_u8PIN*4);
						GPIOB_CRL |=   ((copy_u8MODE) << copy_u8PIN*4);

					}
					else if (copy_u8PIN <= 15)
					{
						GPIOB_CRH &= ~ ((0b1111) << (copy_u8PIN-8)*4);
						GPIOB_CRH |=   ((copy_u8MODE) << (copy_u8PIN-8)*4);
					}
					break;
		case GPIOC :
					if(copy_u8PIN <= 7)
					{
						GPIOC_CRL &= ~ ((0b1111) << copy_u8PIN*4);
						GPIOC_CRL |=   ((copy_u8MODE) << copy_u8PIN*4);

					}
					else if (copy_u8PIN <= 15)
					{
						GPIOC_CRH &= ~ ((0b1111) << (copy_u8PIN-8)*4);
						GPIOC_CRH |=   ((copy_u8MODE) << (copy_u8PIN-8)*4);
					}
					break;
		default : break;
	}
}

void MGPIO_voidSetPinValue (u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Value){
	switch(copy_u8PORT){
		case GPIOA :
			if(copy_u8Value == HIGH){
				SET_BIT(GPIOA_ODR, copy_u8PIN);
			}
			else if (copy_u8Value == LOW){
				CLR_BIT(GPIOA_ODR, copy_u8PIN);
			}
			break;
			
		case GPIOB :
			if(copy_u8Value == HIGH){
				SET_BIT(GPIOB_ODR, copy_u8PIN);
			}
			else if (copy_u8Value == LOW){
				CLR_BIT(GPIOB_ODR, copy_u8PIN);
			}
			break;
		
		case GPIOC :
			if(copy_u8Value == HIGH){
				SET_BIT(GPIOC_ODR, copy_u8PIN);
			}
			else if (copy_u8Value == LOW){
				CLR_BIT(GPIOC_ODR, copy_u8PIN);
			}
			break;
			
		default : break;
	}

	
}

u8 MGPIO_u8GetPinValue (u8 copy_u8PORT, u8 copy_u8PIN){
	
	u8 LOC_u8Result = 0;
	
	switch(copy_u8PORT){
		case GPIOA :
			LOC_u8Result = GET_BIT(GPIOA_IDR,copy_u8PIN );
			break;
			
		case GPIOB :
			LOC_u8Result = GET_BIT(GPIOB_IDR,copy_u8PIN );
			break;
		
		case GPIOC :
			LOC_u8Result = GET_BIT(GPIOC_IDR,copy_u8PIN );
			break;
			
		default : break;
	}
	return LOC_u8Result;
}
void MGPIO_voidSetPort(u8 Copy_u8PORT)
{
	switch(Copy_u8PORT){
		case GPIOA :
			GPIOA_BSR = 0x00FF;           /* first 2 bytes for set pins 0 to 16 and the last 2 bytes for reset */
			break;
		case GPIOB :
			GPIOB_BSR = 0x00FF;
			break;
		case GPIOC :
			GPIOC_BSR = 0x00FF;
			break;
		default : break;
	}
}

void MGPIO_voidResetPort(u8 Copy_u8PORT)
{
	switch(Copy_u8PORT){
		case GPIOA :
			GPIOA_BRR = 0x00FF;           /* first 2 bytes for set pins 0 to 16 and the last 2 bytes for reset */
			break;
		case GPIOB :
			GPIOB_BRR = 0x00FF;
			break;
		case GPIOC :
			GPIOC_BRR = 0x00FF;
			break;
		default : break;
	}
}