// Header: Stm32f103c8 Drivers
// File Name: EXTI Source File
// Author: Omar Megahed Ismail
// Date: 2022/03/20
#include "EXTI.h"
#include "Macros.h"


void vEXTI_NonMask(EXTI_Line_t lineNum)
{
  SET_BIT(EXTI_IMR,lineNum);
}

void vEXTI_Mask(EXTI_Line_t lineNum)
{
  CLEAR_BIT(EXTI_IMR,lineNum);
}

void vEXTI_EventType(EXTI_Line_t lineNum,EXTI_Event_Type EXTI_Event)
{
 switch(EXTI_Event)
    {
	    case Rising_Edge        :SET_BIT(EXTI_RTSR,lineNum);break;
      case Falling_Edge       :SET_BIT(EXTI_FTSR,lineNum);break;
      case Rising_Falling_Edge:SET_BIT(EXTI_RTSR,lineNum);SET_BIT(EXTI_FTSR,lineNum);break;
    }
}
void vEXTI_SWTrigger(EXTI_Line_t LineNum)
{
SET_BIT(EXTI_SWIER,LineNum);
}
void vEXTI_SelectPin(Port_Type PORTn ,uint8 PinNum)
{
 
 if(PinNum<=3)
 {
	 AFIO_EXTICR1 &=~(0b1111<<(PinNum*4));
   AFIO_EXTICR1 |=(PORTn<<(PinNum*4));
 }
 else if((PinNum>3)&&(PinNum<=7))
 {
	 AFIO_EXTICR2 &=~(0b1111<<((PinNum-4)*4));
   AFIO_EXTICR2 |=(PORTn<<((PinNum-4)*4));
 }
 else if((PinNum>7)&&(PinNum<=11))
 {
	 AFIO_EXTICR3 &=~(0b1111<<((PinNum-8)*4));
   AFIO_EXTICR3 |=(PORTn<<((PinNum-8)*4));
 }
 else if((PinNum>11)&&(PinNum<=15))
 {
	 AFIO_EXTICR4 &=~(0b1111<<((PinNum-12)*4));
   AFIO_EXTICR4 |=(PORTn<<((PinNum-12)*4));
 }

}















