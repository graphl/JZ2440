.text
.global _start

_start:
/*
����GPF4λ��������
��0x100д�뵽��ַ0x56000050
*/
    ldr r1,=0x56000050
    ldr r0,=0x100
    str r0,[r1]
/*
����GPF4λ����ߵ�ƽ
��0д�뵽��ַ0x56000054
*/
    ldr r1,=0x56000054
    ldr r0,=0x00  
    str r0,[r1]
halt:
 b halt
