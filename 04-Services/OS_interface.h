/************************************/
/* Author      : Hassan Mahmoud     */
/* Version     : V01                */
/* Date        : 5 Sep 2020        */
/************************************/

#ifndef OS_INTERFAC_H
#define OS_INTERFAC_H

void SOS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u16Priodicity, void (*ptr) (void));
void SOS_voidStart(void);


#endif