.text
.global _start

_start:
    /*�����ڴ�:SP ջ*/
    ldr sp, = 4096  /*nand ����*/

    /*����main*/
    mov r0,#4
    bl led_on
    mov r0,#5
    bl led_on
halt:
 b halt
