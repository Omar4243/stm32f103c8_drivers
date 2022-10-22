// Header: Stm32f103c8 Drivers
// File Name: EXTI Header File
// Author: Omar Megahed Ismail
// Date: 2022/03/20
#ifndef EXTI_H_
#define EXTI_H_
#include "EXTI_Priv.h"
typedef enum
{
  Rising_Edge=0,
	Falling_Edge,
	Rising_Falling_Edge
}EXTI_Event_Type;	
typedef enum
{
  PORTA=0,
	PORTB,
	PORTC,
	PORTD,
}Port_Type;
typedef enum
{
  EXTI0=0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	EXTI5,
	EXTI6,
	EXTI7,
	EXTI8,
	EXTI9,
	EXTI10,
	EXTI11,
	EXTI12,
	EXTI13,
	EXTI14,
	EXTI15,
}EXTI_Line_t;

/*Function prototype*/
void vEXTI_NonMask(EXTI_Line_t lineNum);

void vEXTI_Mask(EXTI_Line_t lineNum);

void vEXTI_EventType(EXTI_Line_t lineNum,EXTI_Event_Type EXTI_Event);

void vEXTI_SWTrigger(EXTI_Line_t LineNum);

void vEXTI_SelectPin(Port_Type PORTn ,uint8 PinNum);

#endif
