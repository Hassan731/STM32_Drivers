/************************************/
/* Author      : Hassan Mahmoud     */
/* Version     : V01                */
/* Date        : 5 Sep 2020        */
/************************************/

#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

void Scheduler(void);

typedef struct 
{
	u16 priodicity;
	void (*Fptr) (void) ;
	
}Task;


volatile u16 TickCounts = 0;

void Scheduler(void)
{
	for(u8 i = 0; i < NUMBER_OF_TASKS; i++)
	{
		if((TickCounts % OS_Tasks[i].priodicity) == 0)
		{
			OS_Tasks[i].Fptr();

		}


	}
	TickCounts++;
}

#endif