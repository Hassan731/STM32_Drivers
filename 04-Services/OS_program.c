/************************************/
/* Author      : Hassan Mahmoud     */
/* Version     : V01                */
/* Date        : 5 Sep 2020        */
/************************************/

#include "STD_Types.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config"

#define NULL    (void *)0
/* Array of Tasks   "Array of Structures" */
static Task OS_Tasks[NUMBER_OF_TASKS] = {NULL};

void SOS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Priodicity, void (*ptr) (void))
{
	OS_Tasks[Copy_u8Priority].priodicity = Copy_u16Priodicity;
	OS_Tasks[Copy_u8Priority].Fptr = ptr;

}

void SOS_voidStart(void)
{
	/* Initialization */
	MSTK_voidInt();
	/* 1msec Tick_Time */
	/* HSE 8MHZ / 8  --> 1000 Msec = 1 msec */
	MSTK_voidSetIntervalPeriodic(1000, Scheduler);

}

