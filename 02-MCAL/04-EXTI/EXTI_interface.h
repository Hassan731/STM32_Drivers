/***********************************/
/* Author      : Hassan Mahmoud    */
/* Version     : V01               */
/* Date        : 22 Aug 2020       */
/***********************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

void MEXTI_voidInit();
void MEXTI_voidEnableEXTI(u8 copy_u8Line);
void MEXTI_voidDisableEXTI(u8 copy_u8Line);
void MEXTI_voidSwTrigger(u8 copy_u8Line);

#endif