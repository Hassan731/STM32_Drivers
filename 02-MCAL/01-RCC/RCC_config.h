/***********************************/
/* Author      : Hassan Mahmoud    */
/* Version     : V01               */
/* Date        : 8 Aug 2020        */
/***********************************/


#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* options : RCC_HSE_CRYSTAL
             RCC_HSE_RC
			 RCC_HSI
			 RCC_PLL              */
			 
#define RCC_Clock_Type    RCC_HSE_CRYSTAL

/* Options :  RCC_PLL_IN_HSI_DIV_2
			  RCC_PLL_IN_HSE_DIV_2
			  RCC_PLL_IN_HSE         */
			  
/* Note: Select value only if you have PLL as input Clock source */
#if RCC_Clock_Type == RCC_PLL
#define RCC_PLL_INPUT   RCC_PLL_IN_HSE_DIV_2
#endif
 
  /* PLL MUL , OPtions: 2 to 16 */
  /* Note: Select value only if you have PLL as input Clock source */
#if RCC_Clock_Type == RCC_PLL
#define RCC_PLL_MUL_VAL  4
#endif




#endif