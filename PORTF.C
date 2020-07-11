#include "POPRTF.h"
#include "lcd.h"
#include "delay.h"
#include "keypad.h"
char pins[16]={zero,one,two,three,four,five,six,seven,eight,nine,a,b ,c,d,e,f};



void PortB_Init(void)
{
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;
  // GPIO_PORTB_LOCK_R = 0x4c4f434b;
   //GPIO_PORTB_CR_R = 0x1f;
    GPIO_PORTB_DEN_R |= A | B | C | D | E | F | G | dp ;
    GPIO_PORTB_DIR_R |= A | B | C | D | E | F | G | dp  ;
    
}
void PortE_Init(void)
{
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
    //GPIO_PORTE_LOCK_R = 0x4c4f434b;
    //GPIO_PORTE_CR_R = 0x1f;
     GPIO_PORTE_ODR_R |= r1| r2 | r3 | r4  ;
    GPIO_PORTE_DEN_R |= r1| r2 | r3 | r4 ;
    GPIO_PORTE_DIR_R |= r1| r2 | r3 | r4   ;
   
    
}
void PortF_Init(void)
{
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
    GPIO_PORTF_LOCK_R = 0x4c4f434b;
    GPIO_PORTF_CR_R = 0x1f;
    GPIO_PORTF_PUR_R |= sw1|sw2;
    GPIO_PORTF_DEN_R |= sw1|sw2;
    GPIO_PORTF_DIR_R &=~ (sw1|sw2);
    GPIO_PORTF_PUR_R |= C2 | C3| C4 ;
    GPIO_PORTF_DEN_R |=  C2 | C3| C4;
    GPIO_PORTF_DIR_R &=~( C2 | C3| C4)  ;
}
int SW_input(void)
{
  /*if((!((GPIO_PORTF_DATA_R & sw2 )&&(GPIO_PORTF_DATA_R & sw1 ))))
  {
    return 0x00;
  }*/
  if((!(GPIO_PORTF_DATA_R & sw2)))
  {
    return 0x10;
  }
  if((!(GPIO_PORTF_DATA_R & sw1)))
  {
    return 0x01;
    
  }
  else {return 0x00;}
}


void LED_on(unsigned char x){
 
    LED_off();
    GPIO_PORTB_DATA_R |= x;
}
void LED_off()
{
  for (int i=0;i<16;i++)
  { 
    GPIO_PORTB_DATA_R &= ~(pins[i]);
  }

}