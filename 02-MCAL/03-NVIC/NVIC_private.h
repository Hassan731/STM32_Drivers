/***********************************/
/* Author      : Hassan Mahmoud    */
/* Version     : V01               */
/* Date        : 19 Aug 2020       */
/***********************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/* 0xE00E100    Base Address */

#define NVIC_ISER0 *((u32*)0xE00E100)              /* Enable  External Interruprts from 0  to 31 */
#define NVIC_ISER1 *((u32*)0xE00E104)              /* Enable  External Interruprts from 32 to 63 */

#define NVIC_ICER0 *((u32*)0xE00E180)              /* DISable External Interruprts from 0  to 31 */
#define NVIC_ICER1 *((u32*)0xE00E184)              /* DISable External Interruprts from 32 to 64 */

#define NVIC_ISPR0 *((u32*)0xE00E200)              /* Set Pending Flag for External Interruprts from 0  to 31 */
#define NVIC_ISPR1 *((u32*)0xE00E204)              /* Set Pending Flag for External Interruprts from 32 to 64 */

#define NVIC_ICPR0 *((u32*)0xE00E280)              /* Clear Pending Flag for External Interruprts from 0  to 31 */
#define NVIC_ICPR1 *((u32*)0xE00E284)              /* Clear Pending Flag for External Interruprts from 32 to 64 */

#define NVIC_IABR0 *((volatile u32*)0xE00E300)     /* Read Active Flag for External Interruprts from 0  to 31 */
#define NVIC_IABR1 *((volatile u32*)0xE00E304)     /* Read Active Flag for External Interruprts from 32 to 64 */

#define NVIC_IPR    ((volatile u8*)0xE00E400)


#define MNVIC_GROUP_4_SUB_0    0x05FA0300
#define MNVIC_GROUP_3_SUB_1    0x05FA0400
#define MNVIC_GROUP_2_SUB_2    0x05FA0500
#define MNVIC_GROUP_1_SUB_3    0x05FA0600
#define MNVIC_GROUP_0_SUB_4    0x05FA0700

#endif