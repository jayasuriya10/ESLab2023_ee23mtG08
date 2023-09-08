#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"

#define Red_Led 1
#define Blue_Led 2
#define Green_Led 3

int main(void)
{
            SYSCTL_RCGC2_R |= 0x00000020;       /* enable clock to GPIOF */
            GPIO_PORTF_LOCK_R = 0x4C4F434B;     /* unlock commit register */
            GPIO_PORTF_CR_R = 0x0F;             /* make PORTF0+PORTF1+PORTF2+PORTF3 configurable */
            GPIO_PORTF_DIR_R = 0x0E;            /* set PORTF3+PORTF2+PORTF1 pin as output (LED) pin */
            GPIO_PORTF_DEN_R = 0x0F;            /* set PORTF pins 3-2-1-0 as digital pins */
            GPIO_PORTF_PUR_R = 0x01;            /* enable pull up for pin 0 */

            int a,b,c,count;

            while(1)
            {
                count=0;
                a = (GPIO_PORTF_DATA_R & 0x01);             /*checking if switch 2 is pressed*/
                if((a==0) & (count=0))

                    {
                    GPIO_PORTF_DATA_R |= (1 << Red_Led);    /*only Red Led is on*/
                    count=count+1;
                    GPIO_PORTF_DATA_R &= (0 << Red_Led);
                    }
                else
                    {
                    GPIO_PORTF_DATA_R &= (0 << Red_Led);    /* only Red Led is off*/
                    GPIO_PORTF_DATA_R &= (0 << Blue_Led);   /* only Blue Led is off*/
                    GPIO_PORTF_DATA_R &= (0 << Green_Led);  /* only Red Led is off*/
                    }







                b = (GPIO_PORTF_DATA_R & 0x01);             /*checking if switch 2 is pressed*/
                if ((b==0) & (count=1))

                    {
                    GPIO_PORTF_DATA_R |= (1 << Blue_Led);   /*only Blue Led is on*/
                    count=count+1;
                    GPIO_PORTF_DATA_R &= (0 << Blue_Led);
                    }
                else
                    {
                    GPIO_PORTF_DATA_R &= (0 << Red_Led);    /* only Red Led is off*/
                    GPIO_PORTF_DATA_R &= (0 << Blue_Led);   /* only Blue Led is off*/
                    GPIO_PORTF_DATA_R &= (0 << Green_Led);    /* only Red Led is off*/
                    }







                c = (GPIO_PORTF_DATA_R & 0x01);             /*checking if switch 2 is pressed*/
                if ((c==0) & (count=2))

                    {
                    GPIO_PORTF_DATA_R |= (1 << Green_Led);  /*only Blue Led is on*/
                    count=count+1;
                    GPIO_PORTF_DATA_R &= (0 << Green_Led);
                    }
                else
                    {
                    GPIO_PORTF_DATA_R &= (0 << Red_Led);    /* only Red Led is off*/
                    GPIO_PORTF_DATA_R &= (0 << Blue_Led);   /* only Blue Led is off*/
                    GPIO_PORTF_DATA_R &= (0 << Green_Led);    /* only Red Led is off*/
                    }




            }
}


