
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

    int valF,valG;

    /*
     * EINT0 EINT2 EINT11
     * GPF0  GPF2    GPG3
     * ȫ������λ��������
     *
     */
    GPFCON &=  ~((3 << 0) | ( 3 << 4));
    GPGCON &=  ~(3 << 6);



    while(1)
    {
        //����֮���ɵ͵�ƽ��ƽʱλ�ߵ�ƽ

     
        valF = GPFDAT;
        valG = GPGDAT;
        if (valF & (1<<0))
        {
            // �ɿ�EINT0
            GPFDAT |= (1 << 4);
        }
        else
        {
            // ����EINT0
            GPFDAT &= ~(1 << 4);
        }
        if (valF & (1<<2))
        {
            // �ɿ�EINT0
            GPFDAT |= (1 << 5);
        }
        else
        {
            // ����EINT0
            GPFDAT &= ~(1 << 5);
        }
        if (valG & (1<<3))
        {
            // �ɿ�EINT0
            GPFDAT |= (1 << 6);
        }
        else
        {
            // ����EINT0
            GPFDAT &= ~(1 << 6);
        }
            
        
    }

    return 0;
    
}
