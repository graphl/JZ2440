
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

    while(1)
    {
        /*看原理图中是n开头，所以是低电平有效
         *所以低电平的时候灯点亮 
         */
        
        tmp = ~value;
        /*只需最低三位*/
        tmp &= 7;
        GPFDAT &= ~(7<<4) ;
        GPFDAT |= (tmp << 4);
 
        delay(100000);
        if (value == 8 )
            value = 0;
        value++;
        
        
    }

    return 0;
    
}
