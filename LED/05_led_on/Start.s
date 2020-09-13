.text
.global _start

_start:
    /*关闭看门狗*/
    ldr r0,=0x53000000
    ldr r1,=0
    str r1,[r0]

    /*设置内存:SP 栈*/
    /*
    * 如何分辨时nor/nand启动
    * 写0到0地址，然后读0地址  
    * 如果读出来的值为0，表示0地址上的内容被修改了，它对应ram，这就是nand启动
    * 否则就是nor启动  
    */
    mov r1,#0
    ldr r0,[r1] /*读出原来的值备份*/
    str r1,[r1] /*0->[0]*/
    ldr r2,[r1] /*r2=[0]*/
    cmp r1,r2 /*r1==r2*/
    ldr sp, =0x40000000+ 4096  /*nor 启动*/
    moveq sp,#4096  /*nand启动*/
    streq r0,[r1] /*恢复原来的值*/
    bl main


halt:
 b halt
