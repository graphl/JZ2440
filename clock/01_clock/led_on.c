
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
    // �����
    GPFCON &=  ~((3 << 8) | ( 3 << 10) | ( 3 << 12));
    // ����Ϊ�������
    GPFCON |= ((1 << 8) | (1 << 10 ) | (1 << 12));

    while(1)
    {
        /*��ԭ��ͼ����n��ͷ�������ǵ͵�ƽ��Ч
         *���Ե͵�ƽ��ʱ��Ƶ��� 
         */
        
        tmp = ~value;
        /*ֻ�������λ*/
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
