#include "delay.h"
#include "keypad.h"
#include "POPRTF.h"
unsigned char keymap[4][4]={{'1','2','3','a'},{'4','5','6','b'},{'7','8','9','c'},{'e','0','f','d'}};
 unsigned char var=0;
 unsigned char lastvar=0;
 unsigned char lastvar1=0;
int x=0;
 void portA_init()
 {
   
SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;
    GPIO_PORTA_DEN_R |= C1  ;
    GPIO_PORTA_DIR_R &= (~C1);
     GPIO_PORTA_PUR_R |= C1;
 }
unsigned char ButtonPressed(void)
{ 

  
  if (!(GPIO_PORTA_DATA_R & C1))
  {
    var=(1<<0);
    lastvar=0x00;
     x=1;
  return 0x00;
  }
  else if (!(GPIO_PORTF_DATA_R & C2))
  {
     var=C2;
     lastvar=0x01;
      x=1;
  return 0x01;
  }
  else if (!(GPIO_PORTF_DATA_R & C3))
  {
     var=C3;
     lastvar=0x02;
      x=1;
  return 0x02;
  }
  else if (!(GPIO_PORTF_DATA_R & C4))
  {
     var=C4;
     lastvar=0x03;
      x=1;
  return 0x03;
  }
 else
 {
   x=0;
   return lastvar;
 }
}
int get_pressed()
{
  return x;
}
unsigned char WhichKey()
{
  GPIO_PORTE_DATA_R &=~ r1;
  GPIO_PORTE_DATA_R |= r2 | r3 | r4 ;
   delay_ms();
   if(!(GPIO_PORTF_DATA_R & var))
   {
     lastvar1=0x00;
      
   return 0x00;
   }
  GPIO_PORTE_DATA_R &=~ r2;
  GPIO_PORTE_DATA_R |= r1 | r3 | r4 ;
   delay_ms();
   if(!(GPIO_PORTF_DATA_R & var))
   {
    lastvar1=0x01;
   
   return 0x01;
   }
  GPIO_PORTE_DATA_R &=~ r3;
  GPIO_PORTE_DATA_R |= r2 | r1 | r4 ;
   delay_ms();
   if(!(GPIO_PORTF_DATA_R & var))
   {
     lastvar1=0x02;

   return 0x02;
   }
  GPIO_PORTE_DATA_R &=~ r4;
  GPIO_PORTE_DATA_R |= r2 | r3 | r1 ;
   delay_ms();
   if(!(GPIO_PORTF_DATA_R & var))
   {
     lastvar1=0x03;
   return 0x03;
   }
   else
   {
     return lastvar1;
   }
}


unsigned char display(unsigned char i,unsigned char j)
{
  unsigned char index= keymap[i][j];
return index;
}
