#include "POPRTF.h"
#include "lcd.h"
#include "keypad.h"
#include "delay.h"
#include <string.h>

double i;
int countt=0;
int flag;

int main()
{
 PortB_Init();
 PortE_Init();
 PortF_Init();
 portA_init();
 LCD_Init ();
 systick_init();
 GPIO_PORTE_DATA_R &=~( r1| r2 | r3 | r4 );
int check;
 unsigned char arr[8];
char temp[16];
int w; 
   
  while(1)
  {
  

    while((GPIO_PORTF_DATA_R & sw1) && (GPIO_PORTF_DATA_R & sw2))
    {
     systick_init();
        unsigned char X= ButtonPressed();
        unsigned char Y= WhichKey();
        unsigned char state= display(Y,X);
           check=get_pressed();
        if((countt<4) && check)
        {
          arr[countt]=state;
          LCD_Char(arr[countt]);
          countt++;
        }
        else if(countt==4){
         break; 
        }     
    }
    
    if(!(GPIO_PORTF_DATA_R & sw1))
    {   
      arr[countt]='.';
    arr[++countt]='0';
    arr[++countt]='0';
     LCD_String_xy(0,0,arr);
     LCD_Clear();
      while(GPIO_PORTF_DATA_R & sw2){
          
        while(((NVIC_ST_CTRL_R & 0x10000)==0)){
          if(!(GPIO_PORTF_DATA_R & sw2))
          {
            flag=1;
                break;
          }
        }
        if(flag==1)
        {
          countt=0;
          LCD_Clear();
          break;
        }
         
            LCD_String_xy(0,0,arr);
              i =strtod(arr,NULL);
              i=i-(0.01);
             sprintf(temp,"%f",i);
               for(int t=0;t<=countt;t++)
               {
                   arr[t]=temp[t];
                   if(arr[t-2]=='.'&&t>2)
                   {
                 
                     break;
                   }
               } 
                if(i<=0.0)
                 {
                     LCD_Clear();
                    LCD_String("endofcountdown");
                    delay_ms();
                    NVIC_ST_CTRL_R &=(~(1<<0));
                      NVIC_ST_RELOAD_R = 0XFFFFFF;
                      NVIC_ST_CTRL_R =5;
                      int countred=0;
                     GPIO_PORTF_DIR_R |=( C2 | C3| C4);
                  
                      GPIO_PORTF_DATA_R &=~( C2 | C3| C4) ;
                     
                      while(countred<3)
                      {
                       GPIO_PORTF_DATA_R |=(C2);
                         while(((NVIC_ST_CTRL_R & 0x10000)==0));
                          GPIO_PORTF_DATA_R &=~(C2);
                          while(((NVIC_ST_CTRL_R & 0x10000)==0));
                       countred++;
                      }
                        GPIO_PORTF_PUR_R |= (C2 | C3| C4);
                      GPIO_PORTF_DIR_R &=~( C2 | C3| C4); 
                      
                    
                     LCD_Clear();
                    countt=0;
                   break;
                 }
               if(!(GPIO_PORTF_DATA_R & sw2))
               {
                 countt=0;
                   LCD_Clear();
                  break;
               }
      }
        
    }

  }
  return 0;
}
