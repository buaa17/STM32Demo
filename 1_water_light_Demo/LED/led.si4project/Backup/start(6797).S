.text
.global _start
_start:
	/*
	 *关闭看门狗
	 */
	ldr r0, = 0x53000000
	ldr r1, = 0x0
	str r1,[r0]

	/*
	 *设置locktime
	 *地址（0x4c000000）写入值：0xFFFFFFFF
	 */
	ldr r0, = 0x4c000000
	ldr r1, = 0xFFFFFFFF
	str r1,[r0]//把r1的值写到r0上面


	/*
	 *设置CLKDIVN，配置Hclk、Pclk
	 *地址（0x4c000014） 写入内容：0x5
	 */
	ldr r0, = 0x4c000014
	ldr r1, = 0x5
	str r1,[r0]

	/*
	 *设置CPU工作于异步模式
	 */
	mrc p15,0,r0,c1,c0,0      
	orr r0,r0,#0xc0000000
	mcr p15,0,r0,c1,c0,0

	/*
	 *设置MPLLCON，配置FCLK
	 *地址（0x4c000004）写入内容：91 << 12 | 1 << 4 | 1<< 0
	 *计算：Fclk = 2*m*Fin/(p*2^s)
	 */
	ldr r0, = 0x4c000000
	ldr r1, = (92 << 12) | (1 << 4) | (1 << 0)
	str r0,[r1]

	/*
	 *设置启动方式
	 */
	mov r1, #0
	ldr r0, [r1]    /*读取原来的值备份*/
	str r1, [r1]    /*0 -> [0]*/
	ldr r2, [r1]    /*r2 = [0]*/
	cmp r1, r2      /*r1 == r2?如果相等表明表是nand启动*/
	ldr sp, = 0x40000000 + 4096 /*先假设是nor启动*/
	moveq sp, #4096     /*nand启动*/
	streq r0, [r1]      /*恢复原来的值*/

	/*
	 *跳转到主函数
	 */
	bl main	
	
halt:
	b halt
