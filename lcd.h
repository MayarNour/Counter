#include "tm4c123gh6pm.h"
#include <stdint.h>
#define regs (1u<<2)
#define rw (1u<<3)
#define en (1u<<4)



void LCD_Init (void) ;
void LCD_Command( unsigned char cmnd );
void LCD_Char( unsigned char data );
void LCD_String (char *str);
void LCD_String_xy (char row, char pos, char *str);
void LCD_Int_to_String_xy (char row, char pos, int num);
void LCD_Clear();
void displayname(int x);

