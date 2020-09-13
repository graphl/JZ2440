.text
.global _start

_start:
    /*�رտ��Ź�*/
    ldr r0,=0x53000000
    ldr r1,=0
    str r1,[r0]



    ldr r1,=0x4C000000
    ldr r0,=0xFFFFFFFF
    str r0,[r1]


    /*
     * ����MPLLCON�Ĵ���������12MHZ ��� 400MHZ
     * ����MDIV = 0x5c
     * ����PDIV = 1
     * ����SDIV = 1
     */


     /*
      * ����CLKCON �Ĵ���
      *  ����GPIO Enable CPU Enable
      */
    ldr r1,=0x4C000004
    ldr r0,=0x00102000
    str r0,[r1]

    
     /*
      *  ���� CLKDIVN �Ĵ���  FCLK = 400
      *  ����HDIVN = 01  HCLK = FCLK/2. = 200
      *  ����PDIVN = 1   PCLK = HCLK/2.  = 100
      */
    
    ldr r1,=0x4C000014
    ldr r0,=0x00000003
    str r0,[r1]
    
    /* ����CPU�������첽ģʽ */
    mrc p15,0,r0,c1,c0,0
    orr r0,r0,#0xc0000000   /*R1_nF:OR:R1_iA*/
    mcr p15,0,r0,c1,c0,0


    /*�����ڴ�:SP ջ*/
    /*
    * ��ηֱ�ʱnor/nand����
    * д0��0��ַ��Ȼ���0��ַ  
    * �����������ֵΪ0����ʾ0��ַ�ϵ����ݱ��޸��ˣ�����Ӧram�������nand����
    * �������nor����  
    */
    mov r1,#0
    ldr r0,[r1] /*����ԭ����ֵ����*/
    str r1,[r1] /*0->[0]    [r1] = r1*/
    ldr r2,[r1] /*r2=[0]*/
    cmp r1,r2 /*r1==r2*/
    ldr sp, =0x40000000+ 4096  /*nor ����*/
    moveq sp,#4096  /*nand����*/
    streq r0,[r1] /*�ָ�ԭ����ֵ*/
    bl main


halt:
 b halt
