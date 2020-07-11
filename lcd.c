
#include "lcd.h"
#include "delay.h"
#include "POPRTF.h"
 int counter=-1;
char  str[];
char names[5][6]={"engy", "gina", "mayar", "rowan", "yara"};

void LCD_Init (void)  /* LCD Initialize function */
{
	
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;
    GPIO_PORTA_DEN_R |= regs| rw | en  ;
    GPIO_PORTA_DIR_R |= regs| rw | en ;
     GPIO_PORTA_DATA_R &= ~ rw   ;
     
     delay_MS(20);
     LCD_Command(0x30);
      delay_MS(5);
      LCD_Command(0x30);
      delay_us(100);
      LCD_Command(0x30);
      delay_us(100);
      
	LCD_Command(0x38);	
	LCD_Command(0x06);	
	LCD_Command(0x01);
        LCD_Command(0x0f);	
}

void LCD_Command( unsigned char cmnd )
{
	
	/* Sending upper nibble */
	GPIO_PORTB_DATA_R = cmnd;
	/* RS=0, command reg. */
	GPIO_PORTA_DATA_R &= ~ regs;		
	
	/* Enable pulse */
	GPIO_PORTA_DATA_R |= en;		
	/*delay bt3na*/
        delay_us(1);
	GPIO_PORTA_DATA_R &= ~ en;
	if(cmnd<4)
        {
            delay_MS(2);
        }
        else
        {
            delay_us(40);
        }
        
	
}

void LCD_Char( unsigned char data )
{
	/* Sending upper nibble */
	GPIO_PORTB_DATA_R =data;
	/* RS=1, data reg. */
	GPIO_PORTA_DATA_R |= regs;  
	/* Enable pulse */
	GPIO_PORTA_DATA_R |= en;
	delay_us(1);
	GPIO_PORTA_DATA_R &= ~ en;
	delay_us(40);

}

void LCD_String (char *str)		/* Send string to LCD function */
{
	int i;
	for(i=0;i<(strlen(str));i++)		/* Send each char of string till the NULL */
	{
        
          if(str[i-2]=='.')
             {
                LCD_Char (str[i]);
               break;
             }
          else
          {
            LCD_Char (str[i]);
          }
	}
}

void displayname(int x)
{
  if (x==0x10){
    counter++;
    
     LCD_Clear();
    LCD_String(names[counter]);
    if (counter==4){
    counter=-1;}
  } 
  else  if (x==0x01){
    counter--;
    if (counter <=-1){
    counter=4;}
    
  
   
     LCD_Clear();
    LCD_String(names[counter]);
    if (counter==4){
    counter=-1;}
  }
}

void LCD_String_xy (char row, char pos, char *str)	/* Send string to LCD with xy position */
{
	if (row == 0 && pos<16)
	LCD_Command((pos & 0x0F)|0x80);	/* Command of first row and required position<16 */
	else if (row == 1 && pos<16)
	LCD_Command((pos & 0x0F)|0xC0);	/* Command of first row and required position<16 */
	LCD_String(str);		/* Call LCD string function */
}
void LCD_char_xy (char row, char pos, char str)	/* Send string to LCD with xy position */
{
	if (row == 0 && pos<16)
	LCD_Command((pos & 0x0F)|0x80);	/* Command of first row and required position<16 */
	else if (row == 1 && pos<16)
	LCD_Command((pos & 0x0F)|0xC0);	/* Command of first row and required position<16 */
	LCD_Char(str);		/* Call LCD string function */
}
void LCD_Int_to_String_xy (char row, char pos, int num)	/* Send string to LCD with xy position */
{
	char i = 0 , len = 0;
	int n;
	n = num;
	
	while ( (n % 10) != 0)
	{
		
		n = (int)n / (int) 10 ;
		len++;
	}
	while ( (num % 10) != 0)
	{
		str[(len - 1)-i] = (num % 10) +48;
		num = (int)num / (int) 10 ;
		i++;
	}
	str[len] = '\0';
	
	if (row == 0 && pos<16)
	LCD_Command((pos & 0x0F)|0x80);	/* Command of first row and required position<16 */
	else if (row == 1 && pos<16)
	LCD_Command((pos & 0x0F)|0xC0);	/* Command of first row and required position<16 */
	LCD_String(str);		/* Call LCD string function */
}

void LCD_Clear()
{
	LCD_Command (0x01);		/* Clear display */
	delay_ms();
	LCD_Command (0x80);		/* Cursor at home position */
}


