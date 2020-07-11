#include "delay.h"
void delay_ms()
{
  for(int i=0;i<1000000;i++);
  
}

void delay_MS(char x)
{
  for(int i=0;i<(x*10);i++);
  
}
void delay_us(char x)
{
  for(int i=0;i<(x*100);i++);
  
}