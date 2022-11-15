/***********************************/
/* Author      : Hassan Mahmoud    */
/* Version     : V01               */
/* Date        : 26 Aug 2020       */
/***********************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

void MSTK_voidInit(void);                        /* Apply Clock choise from configuration file, Disable SYSTICK Interrupt, Disable SYSTICK */
void MSTK_voidSetBusyWait(u32_Copyu32Ticks);
void MSTK_voidSetIntervalSingle(u32_Copyu32Ticks, void (*ptr)(void));               /* Asynchronous func. */
void MSTK_voidSetIntervalPeriodic(u32_Copyu32Ticks, void (*ptr)(void)); 
u32  MSTK_voidStopInterval(void);
u32  MSTK_u32GetElapsedTime(void);
u32  MSTK_u32GetRemainingTime(void);

#endif