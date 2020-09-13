.text
.global _start

_start:
/*
配置GPF4位输入引脚
把0x100写入到地址0x56000050
*/
    ldr r1,=0x56000050
    ldr r0,=0x100
    str r0,[r1]
/*
配置GPF4位输出高电平
把0写入到地址0x56000054
*/
    ldr r1,=0x56000054
    ldr r0,=0x00  
    str r0,[r1]
halt:
 b halt
