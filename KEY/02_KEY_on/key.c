
#include "key.h"
#include "led.h"
void init_key()
{
    GPFCON &=  ~((3 << 0) | ( 3 << 4));
    GPGCON &=  ~(3 << 6);
}
void key_on()
{
    int valF;
    int valG;
    
        valF = GPFDAT;
        valG = GPGDAT;
        if (valF & (1<<0))
        {
            select_led_off(LED_1_Register_num);
        }
        else
        {
            select_led_on(LED_1_Register_num);  
        }
        if (valF & (1<<2))
        {
            select_led_off(LED_2_Register_num);
        }
        else
        {
            select_led_on(LED_2_Register_num);
        }
        if (valG & (1<<3))
        {
            select_led_off(LED_4_Register_num);
        }
        else
        {
            select_led_on(LED_4_Register_num);        
        }
}
