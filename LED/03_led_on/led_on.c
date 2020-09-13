


int led_on(int value)
{
    unsigned int *pGONCON = 0x56000050;
    unsigned int *pGONDAT = 0x56000054;
    switch (value)
    {
    case 4:
        /* code */
            (*pGONCON) = 0x100;
            (*pGONDAT) = 0x00;
        break;
    case 5:
            (*pGONCON) = 0x00000400;
            (*pGONDAT) = 0x00;
        (*pGONDAT) = 0x00;
        break;
    default:
        break;
    }

    
}
