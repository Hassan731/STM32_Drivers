/***********************************/
/* Author      : Hassan Mahmoud    */
/* Version     : V01               */
/* Date        : 12 Aug 2020        */
/***********************************/


#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define HIGH      1
#define LOW       0

#define GPIOA     0
#define GPIOB     1
#define GPIOC     2

#define PIN0      0
#define PIN1      1
#define PIN2      2
#define PIN3      3
#define PIN4      4
#define PIN5      5
#define PIN6      6
#define PIN7      7
#define PIN8      8
#define PIN9      9
#define PIN10     10
#define PIN11     11
#define PIN12     12
#define PIN13     13
#define PIN14     14
#define PIN15     15

/* 10MHZ Speed */
#define OUTPUT_SPEED_10MHZ_PP         0b0001
#define OUTPUT_SPEED_10MHZ_OD         0b0101
#define OUTPUT_SPEED_10MHZ_AFPP       0b1001
#define OUTPUT_SPEED_10MHZ_AFOP       0b1101

/* 2MHZ Speed */
#define OUTPUT_SPEED_2MHZ_PP         0b0010
#define OUTPUT_SPEED_2MHZ_OD         0b0110
#define OUTPUT_SPEED_2MHZ_AFPP       0b1010
#define OUTPUT_SPEED_2MHZ_AFOP       0b1110

/* 50MHZ Speed */
#define OUTPUT_SPEED_50MHZ_PP         0b0011
#define OUTPUT_SPEED_50MHZ_OD         0b0111
#define OUTPUT_SPEED_50MHZ_AFPP       0b1011
#define OUTPUT_SPEED_50MHZ_AFOP       0b1111

/* Input Modes */
#define IN_ANALOG                  0b0000
#define IN_FLOATING                0b0100
#define IN_PULL_Up_Down            0b1000



void MGPIO_voidSetPinDirection (u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8MODE);
void MGPIO_voidSetPinValue (u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Value);
u8 MGPIO_u8GetPinValue (u8 copy_u8PORT, u8 copy_u8PIN);
void MGPIO_voidSetPort(u8 Copy_u8PORT);
void MGPIO_voidResetPort(u8 Copy_u8PORT);

#endif