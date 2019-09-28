
.text
.code 32
.global _start

_start:

	//关闭看门狗
	ldr r0,=0x53000000
	ldr r1,=0
	str r1,[r0]
	
	//设置自动选择启动方式识别代码
	ldr r0,=0
	ldr r2,[r0]//读取0地址数据作为备份
	str r0,[r0]//往0地址写入数据0
	ldr r1,[r0]//读取0地址数据
	cmp r1,r0
	ldr sp, = 0x40000000+4096  /* nor */
	moveq sp, #4096
	streq r2,[r0]

	//配置时钟
	ldr r0,=0x4c000000
	ldr r1,=0xffffffff
	str r1,[r0]

	ldr r0,=0x4C000014
	ldr r1,=((1<<2)|(1<<0))
	str r1,[r0]

	ldr r0,=0x4C00000C
	ldr r1,=0xfffff0
	str r1,[r0]
	
	mrc p15,0,r0,c1,c0,0
	orr r0,r0,#0xc0000000
	mcr p15,0,r0,c1,c0,0

	ldr r0,=0x4C000004
	ldr r1,=((92<<12)|(1<<4)|(1<<0))
	str r1,[r0]

	bl main

halt:
	b halt
.end
