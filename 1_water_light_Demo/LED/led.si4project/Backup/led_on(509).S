/*
 * 点亮LED1: gpf4
 */

.text //接下来的内容放到代码段
.code 32//接下来的内容翻译成arm指令集
.global start//声明全局start标号

start:

/* 配置GPF4为输出引脚
 * 把0x100写到地址0x56000050
 */
	ldr r0 ,=0x100
	ldr r1 ,=0x56000050
	tr r0 ,[r1]

/* 设置GPF4输出高电平 
 * 把0写到地址0x56000054
 */
	ldr r0 ,=0
	ldr r1 ,=0x56000054
	str r0 ,[r1]


	/* 死循环 */
hult:
	B hult

.end//汇编文件的结束
