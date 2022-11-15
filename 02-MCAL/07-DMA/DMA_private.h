/************************************/
/* Author      : Hassan Mahmoud     */
/* Version     : V01                */
/* Date        : 12 SEP 2020        */
/************************************/

#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

#define DMA     ((volatile DMA_*)0x40020000)

typedef struct 
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 Reserved;
}DMA_Channel;

typedef struct
{
	volatile u32 ISR;
	volatile u32 IFCR;
	DMA_Channel Channel[7];
}DMA_t;


#endif