/************************************/
/* Author      : Hassan Mahmoud     */
/* Version     : V01                */
/* Date        : 12 SEP 2020        */
/************************************/

#include "STD_Types.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"

void MDMA_voidChannelInit(void)
{
	/* 
		1- Memory to Memory
		2- Very high priority
		3- Source sizeo, Destination size = 32-bit
		4- MINC, PINC activated
		5- no circular
		6- Direction :
		7- Transfer Interrupt Enable

	*/
	#if      CHANNEL_ID == 1
		DMA -> Channel[0].CCR   = 0x00007AC2; 
		DMA -> Channel[0].CNDTR = 0x000003E8;
		
	#else if CHANNEL_ID = 2
	
	
}
void MDMA_voidChannelStart(u32 *Copy_pu32SourceAddress, u32 *Copy_pu32DestinationAddress, u16 Copy_u16BlockLength)
{
	/* Make sure Channel id Disabled */
	CLR_BIT(DMA -> Cahnnel[CHANNEL_ID].CCR, 0);
	
	/* Write Source Address */
	DMA -> Channel[CHANNEL_ID].CPAR = Copy_pu32SourceAddress;
	/* Write Destination Address */
	DMA -> Channel[CHANNEL_ID].CMAR = Copy_pu32DestinationAddress;
	
	/* Block Length */
	DMA -> Channel[CHANNEL_ID].CNDTR = Copy_u16BlockLength;
	
	/* Channel Enable */
	SET_BIT(DMA -> Cahnnel[CHANNEL_ID].CCR, 0);
}
