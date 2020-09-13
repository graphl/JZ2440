.text
.global _start

_start:
    /*关闭看门狗*/
    ldr r0,=0x53000000
    ldr r1,=0
    str r1,[r0]



    ldr r1,=0x4C000000
    ldr r0,=0xFFFFFFFF
    str r0,[r1]


    /*
     * 设置MPLLCON寄存器，输入12MHZ 输出 400MHZ
     * 设置MDIV = 0x5c
     * 设置PDIV = 1
     * 设置SDIV = 1
     */


     /*
      * 设置CLKCON 寄存器
      *  设置GPIO Enable CPU Enable
      */
    ldr r1,=0x4C000004
    ldr r0,=0x00102000
    str r0,[r1]

    
     /*
      *  设置 CLKDIVN 寄存器  FCLK = 400
      *  设置HDIVN = 01  HCLK = FCLK/2. = 200
      *  设置PDIVN = 1   PCLK = HCLK/2.  = 100
      */
    
    ldr r1,=0x4C000014
    ldr r0,=0x00000003
    str r0,[r1]
    
    /* 设置CPU工作于异步模式 */
    mrc p15,0,r0,c1,c0,0
    orr r0,r0,#0xc0000000   /*R1_nF:OR:R1_iA*/
    mcr p15,0,r0,c1,c0,0


    /*设置内存:SP 栈*/
    /*
    * 如何分辨时nor/nand启动
    * 写0到0地址，然后读0地址  
    * 如果读出来的值为0，表示0地址上的内容被修改了，它对应ram，这就是nand启动
    * 否则就是nor启动  
    */
    mov r1,#0
    ldr r0,[r1] /*读出原来的值备份*/
    str r1,[r1] /*0->[0]    [r1] = r1*/
    ldr r2,[r1] /*r2=[0]*/
    cmp r1,r2 /*r1==r2*/
    ldr sp, =0x40000000+ 4096  /*nor 启动*/
    moveq sp,#4096  /*nand启动*/
    streq r0,[r1] /*恢复原来的值*/
    bl main


halt:
 b halt
