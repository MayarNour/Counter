#include "systick.h"

void systick_init()
{
NVIC_ST_CTRL_R &=(~(1<<0));
NVIC_ST_RELOAD_R = 159999;
NVIC_ST_CTRL_R =5;
}