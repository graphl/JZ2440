.text
.global _start

_start:
    /*�رտ��Ź�*/
    ldr r0,=0x53000000
    ldr r1,=0
    str r1,[r0]

    /*�����ڴ�:SP ջ*/
    /*
    * ��ηֱ�ʱnor/nand����
    * д0��0��ַ��Ȼ���0��ַ  
    * �����������ֵΪ0����ʾ0��ַ�ϵ����ݱ��޸��ˣ�����Ӧram�������nand����
    * �������nor����  
    */
    mov r1,#0
    ldr r0,[r1] /*����ԭ����ֵ����*/
    str r1,[r1] /*0->[0]*/
    ldr r2,[r1] /*r2=[0]*/
    cmp r1,r2 /*r1==r2*/
    ldr sp, =0x40000000+ 4096  /*nor ����*/
    moveq sp,#4096  /*nand����*/
    streq r0,[r1] /*�ָ�ԭ����ֵ*/
    bl main


halt:
 b halt
