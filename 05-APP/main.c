/************************************/
/* Author      : Hassan Mahmoud     */
/* Version     : V01                */
/* Date        : 5 Sep 2020        */
/************************************/

#include "STD_Types.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "OS_interface.h"

void LED1(void);
void LED2(void);
void LED3(void);
int main(void)
{

	/* RCC Initialization */
	/* Enable GPIOA RCC PORTA */

	/* GPIO Initialization and Pin Direction */

	SOS_voidCreateTask(0, 1000, LED1);
	
	SOS_voidCreateTask(2, 2000, LED2);

	SOS_voidCreateTask(3, 4000, LED3);

	SOS_voidStart();

	while(1)
	{

	}

}

void LED1(void)
{
	static u8 Local_u8Pin0 = 0;
	TOG_BIT(Local_u8Pin0, 0);
	MGPIO_voidSetPinValue(GPIOA, PIN0, Local_u8Pin0);

}
void LED2(void)
{
	static u8 Local_u8Pin0 = 0;
	TOG_BIT(Local_u8Pin0, 0);
	MGPIO_voidSetPinValue(GPIOA, PIN1, Local_u8Pin0);

}
void LED3(void)
{
	static u8 Local_u8Pin0 = 0;
	TOG_BIT(Local_u8Pin0, 0);
	MGPIO_voidSetPinValue(GPIOA, PIN2, Local_u8Pin0);

}