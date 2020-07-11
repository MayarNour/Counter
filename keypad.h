#include "tm4c123gh6pm.h"
#include <stdint.h>
#define r1 (1u<<1)
#define r2 (1u<<2)
#define r3 (1u<<3)
#define r4 (1u<<4)
#define C1 (1u<<5)
#define C2 (1u<<1)
#define C3 (1u<<2)
#define C4 (1u<<3)
unsigned char display(unsigned char i,unsigned char j);
unsigned char WhichKey(void);
unsigned char ButtonPressed(void);
void portA_init(void);
int get_pressed(void);