.text
.global _start

_start:
    /*�����ڴ�:SP ջ*/
    ldr sp, = 4096  /*nand ����*/

    /*����main*/
    bl main
halt:
 b halt
