/************************************/
/* Author      : Hassan Mahmoud     */
/* Version     : V01                */
/* Date        : 12 SEP 2020        */
/************************************/

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

void MDMA_voidChannelInit(void);
void MDMA_voidChannelStart(u32 *Copy_pu32SourceAddress, u32 *Copy_pu32DestinationAddress, u16 Copy_u16BlockLength);

#endif