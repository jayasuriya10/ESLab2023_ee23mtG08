#include<stdint.h>
#include<stdbool.h>
#include"tm4c123gh6pm.h"

#define Red_Led 1

/* SysTick memory-mapped registers */
#define STCTRL *((volatile long *) 0xE000E010)   /* control status register*/
#define STRELOAD *((volatile long *) 0xE000E014) /* reload value register*/
#define STCURRENT *((volatile long *) 0xE000E018)/* current value register*/

#define COUNT_FLAG (1 << 16)                     /* bit 16 of CSR automatically set to 1 when timer expires*/
#define ENABLE (1 << 0)                          /* bit 0 of CSR set to 1 to enable the timer*/
#define CLKINT (1 << 2)                          /* bit 2 of CSR set to 1 to specify CPU clock*/

#define CLOCK_MHZ 16

void Delay(int us)
{
  STRELOAD = us*16;                             /* reload value for Systic timer (Systick timer interrupt time period = (Reload value + 1 ) x time period*/
  STCTRL |= (CLKINT | ENABLE);                  /* set internal clock, enable the timer*/

  while ((STCTRL & COUNT_FLAG) == 0)            /* wait until flag is set*/
  {
                                               /* do nothing*/
  }
  STCTRL = 0;                                  /* stop the timer*/
  return;
}

int main(void)

{
SYSCTL_RCGCGPIO_R |= 0x00000020;          /* enable clock to GPIOF */
GPIO_PORTF_LOCK_R = 0x4C4F434B;           /* unlock commit register */
GPIO_PORTF_CR_R = 0x1F;                   /* make PORTF configurable */
GPIO_PORTF_DIR_R = 0x02;                  /* set PORTF1 pin as output (LED) pin */
GPIO_PORTF_DEN_R = 0x02;                  /* set PORTF pin 1 as digital pin */




  while(1)
  {
    GPIO_PORTF_DATA_R |= (1 << Red_Led);
    Delay(800);
    GPIO_PORTF_DATA_R &= (0 << Red_Led);
    Delay(200);
  }
}

