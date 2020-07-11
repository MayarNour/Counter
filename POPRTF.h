#include "tm4c123gh6pm.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define A (1u<<0)
#define B (1u<<1)
#define C (1u<<2)
#define D (1u<<3)
#define E (1u<<4)
#define F (1u<<5)
#define G (1u<<6)
#define dp (1u<<7)
#define zero A | B| C | D | E |F
#define one B | C
#define two A | B | G | E | D
#define three A | B | G | C | D
#define four F | B | G | C 
#define five A | F | G | C | D
#define six A | F | G | E | C | D
#define seven A | B | C
#define eight A | B | G | C | D | E | F
#define nine A | B | G | C | D | F
#define  a  A | B | G | C | F | E
#define b F | E | G | C | D
#define c A | F | E | D
#define d  (B | G | C | D  | E)
#define e A | F | G | E | D
#define f A | F | G | E
#define sw1 (1u<<4)
#define sw2 (1u<<0)

void LED_off();
void LED_on(unsigned char x);
void PortF_Init(void);
void PortE_Init(void);
void PortB_Init(void);
int SW_input(void);