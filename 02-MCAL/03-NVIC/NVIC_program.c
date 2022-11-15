/***********************************/
/* Author      : Hassan Mahmoud    */
/* Version     : V01               */
/* Date        : 19 Aug 2020       */
/***********************************/

#include "STD_Types.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidInit(void)
{
	#define SCB_AIRCR   *((u32*)0xE000ED00 + 0x0C)
	SCB_AIRCR = MNVIC_GROUP_2_SUB_2;
}

void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <= 31)
	{
		NVIC_ISER0 = (1 << Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 59)
	{
		NVIC_ISER1 = (1 << (Copy_u8IntNumber-32));
	}
	else
	{
		/*Return Error*/
	}
	
}
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <= 31)
	{
		NVIC_ICER0 = (1 << Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 59)
	{
		NVIC_ICER1 = (1 << (Copy_u8IntNumber-32));
	}
	else
	{
		/*Return Error*/
	}
	
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <= 31)
	{
		NVIC_ISPR0 = (1 << Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 59)
	{
		NVIC_ISPR1 = (1 << (Copy_u8IntNumber-32));
	}
	else
	{
		/*Return Error*/
	}
	
}

void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <= 31)
	{
		NVIC_ICPR0 = (1 << Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 59)
	{
		NVIC_ICPR1 = (1 << (Copy_u8IntNumber-32));
	}
	else
	{
		/*Return Error*/
	}
	
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8Result;
	
	if(Copy_u8IntNumber <= 31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0, Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 59)
	{
		Local_u8Result = GET_BIT(NVIC_IABR1, Copy_u8IntNumber-32);
	}
	else
	{
		/*Return Error*/
	}
	
}

void MNVIC_voidSetPriority(s8 Copy_s8IntID, u8 copy_u8GroupPriority,u8 copy_u8SubPriority, u32 copy_u32Group)
{
	u8 Local_u8Priority = copy_u8SubPriority | (copy_u8GroupPriority <<(copy_u32Group - 0x05FA0300) / 256) ;
	/* core peripheral*/
	
	
	/* external peripheral*/
	if (Copy_s8IntID >= 0)
	{
		NVIC_IPR[Copy_s8IntID] = Local_u8Priority << 4;
	}
	
	SCB_AIRCR = copy_u32Group;

}

