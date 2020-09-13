


int main()
{
    unsigned int *pGONCON = 0x56000050;
    unsigned int *pGONDAT = 0x56000054;

    (*pGONCON) = 0x100;
    (*pGONDAT) = 0x00;
    
}
