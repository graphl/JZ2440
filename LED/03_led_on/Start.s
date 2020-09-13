.text
.global _start

_start:
    /*设置内存:SP 栈*/
    ldr sp, = 4096  /*nand 启动*/

    /*调用main*/
    mov r0,#4
    bl led_on
    mov r0,#5
    bl led_on
halt:
 b halt
