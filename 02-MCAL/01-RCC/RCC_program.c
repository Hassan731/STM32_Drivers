/***********************************/
/* Author      : Hassan Mahmoud    */
/* Version     : V01               */
/* Date        : 8 Aug 2020        */
/***********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_config.h"
#include "RCC_private.h"


void RCC_voidDisableClock(u8 Copy_u8BusID, u8 Copy_u8PerID );
void RCC_voidEnableClock(u8 Copy_u8BusID, u8 Copy_u8PerID );
void RCC_voidInitSysClocck(void);

void RCC_voidEnableClock(u8 Copy_u8BusID, u8 Copy_u8PerID ){

	if (Copy_u8PerID <= 31)             /* Copy_u8PerID : Bit that will be enabled*/
	{                                   /* Copy_u8BusID : Bus that which contain the peripheral*/
		switch(Copy_u8PerID)
		{
			case RCC_AHB  :  SET_BIT(RCC_AHBENR,  Copy_u8PerID); break;
			case RCC_APB1 :  SET_BIT(RCC_APB1ENR, Copy_u8PerID); break;
			case RCC_APB2 :  SET_BIT(RCC_APB2ENR, Copy_u8PerID); break;
			default   :   /* Return Error*/  break; 
		}
		
	}
	else 
	{
		
		/*Return Error*/
	}
}
	
	void RCC_voidDisableClock(u8 Copy_u8BusID, u8 Copy_u8PerID ){

	if (Copy_u8PerID <= 31)             /* Copy_u8PerID : Bit that will be enabled*/
	{                                   /* Copy_u8BusID : Bus that which contain the peripheral*/
		switch(Copy_u8PerID)
		{
			case RCC_AHB  :  CLR_BIT(RCC_AHBENR,  Copy_u8PerID); break;
			case RCC_APB1 :  CLR_BIT(RCC_APB1ENR, Copy_u8PerID); break;
			case RCC_APB2 :  CLR_BIT(RCC_APB2ENR, Copy_u8PerID); break;
			default   :   /* Return Error*/  break; 
		}
		
	}
	else 
	{
		
		/*Return Error*/
	}
}
	
void RCC_voidInitSysClocck(void){
	
	#if   RCC_Clock_type == RCC_HSE_CRYSTAL
	
		RCC_CR    = 0x00010000; /* Enable HSE Crystal */
		RCC_CFGR  = 0x00000001;
	#elif RCC_Clock_type == RCC_HSE_RC
	
		RCC_CR    = 0x00050000; /* Enable HSE RC */
		RCC_CFGR  = 0x00000001;
	#elif RCC_Clock_type == RCC_HSI
	
		RCC_CR    = 0x00000081;  /* Enable HSI + No Trim */
		RCC_CFGR  = 0x00000000;
	#elif RCC_Clock_type == RCC_PLL
	
		#if     RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2       /* PLL Clock source with HSI/2 */
			RCC_CR    = 0x01000081;
			RCC_CFGR  = 0x0008000A;
		
		#elif   RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2       /* PLL Clock source with HSE/2 */
		
			#if    RCC_Clock_Type == RCC_HSE_CRYSTAL        /* Crystal HSE */
				RCC_CR    = 0x01090000;
				RCC_CFGR  = 0x0003000A;
			#elif  RCC_Clock_Type == RCC_HSE_RC             /* RC HSE */
				RCC_CR    = 0x010D0000;
				RCC_CFGR  = 0x0003000A;
				
			#else 
				#error ("You chosed wrong Clock type")
			
			#endif
			
		#elif   RCC_PLL_INPUT == RCC_PLL_IN_HSE             /* PLL Clock source with HSE */
		
			#if    RCC_Clock_Type == RCC_HSE_CRYSTAL        /* Crystal HSE */
				RCC_CR    = 0x01090000;
				RCC_CFGR  = 0x0001000A
				;
			#elif  RCC_Clock_Type == RCC_HSE_RC             /* RC HSE */
				RCC_CR    = ;
				RCC_CFGR  = ;
				
			#else 
				#error ("You chosed wrong Clock type")
			
			#endif
			
		#else 
			#error ("You chosed wrong Clock type")
	
		# endif
	
	#else 
		#error ("You chosed wrong Clock type")
	
	#endif
	
}