
void delay(volatile int time)
{
    while (time--);
    
}

int main()
{
     unsigned int *pGPFCON =( unsigned int *) 0x56000050;
     unsigned int *pGPFDAT =( unsigned int *) 0x56000054;
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
    *pGPFCON &=  ~((3 << 8) | ( 3 << 10) | ( 3 << 12));
    // 设置为输出引脚
    *pGPFCON |= ((1 << 8) | (1 << 10 ) | (1 << 12));

    while(1)
    {
        /*看原理图中是n开头，所以是低电平有效
         *所以低电平的时候灯点亮 
         */
        
        tmp = ~value;
        /*只需最低三位*/
        tmp &= 7;
        *pGPFDAT &= ~(7<<4) ;
        *pGPFDAT |= (tmp << 4);
 
        delay(10000);
        if (value == 8 )
            value = 0;
        value++;
        
        
    }

    return 0;
    
}
