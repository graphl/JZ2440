#include "key.h"

int main()
{
    init_led();
    init_key();
    while(1)
    {
        key_on();
    }

    return 0;
}