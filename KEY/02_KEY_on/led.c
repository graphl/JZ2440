#include "led.h"

void init_led()
{
 
    /*
        LED-1 GPF4
        LED-2 GPF5
        LED-4 GPF6
        
    */
    // �����
    GPFCON &=  ~((3 << 8) | ( 3 << 10) | ( 3 << 12));
    // ����Ϊ�������
    GPFCON |= ((1 << 8) | (1 << 10 ) | (1 << 12));

    // �����ȫ��
    GPFDAT |= (7<<4);
}

void select_led_on(int val)
{
   GPFDAT &= ~(1 << val);
}

void select_led_off(int val)
{
   GPFDAT |= (1 << val);
}
