.text
.global _start

_start:
    /*设置内存:SP 栈*/
    ldr sp, = 4096  /*nand 启动*/

    /*调用main*/
    bl main
halt:
 b halt
