/***********************************/
/* Author      : Hassan Mahmoud    */
/* Version     : V01               */
/* Date        : 24 Aug 2020       */
/***********************************/

#ifndef LED_INTERFAC_H
#define LED_INTERFAC_H

/* Pins choices  PIN0  :  PIN15 */
/* Port choices  GPIOA or GPIOB */

void HLED_voidLedOn(u8 Copy_u8PortId, u8 Copy_u8PinId);
void HLED_voidLedOff(u8 Copy_u8PortId, u8 Copy_u8PinId);

#endif