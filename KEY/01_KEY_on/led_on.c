
#include "s3c2440_soc.h"

void delay(volatile int time)
{
    while (time--);
    
}

int main()
{
    int value = 0;
    int tmp;
    /*
     * 
     */
    
    /*
        LED-1 GPF4
        LED-2 GPF5
        LED-4 GPF6
        
    */
    // 先清空
    GPFCON &=  ~((3 << 8) | ( 3 << 10) | ( 3 << 12));
    // 设置为输出引脚
    GPFCON |= ((1 << 8) | (1 << 10 ) | (1 << 12));

    int valF,valG;

    /*
     * EINT0 EINT2 EINT11
     * GPF0  GPF2    GPG3
     * 全都设置位输入引脚
     *
     */
    GPFCON &=  ~((3 << 0) | ( 3 << 4));
    GPGCON &=  ~(3 << 6);



    while(1)
    {
        //按下之后变成低电平，平时位高电平

     
        valF = GPFDAT;
        valG = GPGDAT;
        if (valF & (1<<0))
        {
            // 松开EINT0
            GPFDAT |= (1 << 4);
        }
        else
        {
            // 按下EINT0
            GPFDAT &= ~(1 << 4);
        }
        if (valF & (1<<2))
        {
            // 松开EINT0
            GPFDAT |= (1 << 5);
        }
        else
        {
            // 按下EINT0
            GPFDAT &= ~(1 << 5);
        }
        if (valG & (1<<3))
        {
            // 松开EINT0
            GPFDAT |= (1 << 6);
        }
        else
        {
            // 按下EINT0
            GPFDAT &= ~(1 << 6);
        }
            
        
    }

    return 0;
    
}
