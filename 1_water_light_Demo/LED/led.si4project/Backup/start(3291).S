
.text
.code 32
.global _start

_start:
	bl close_watchdog
	bl clock_config
	bl start_on_flash
	//初始化uart
	bl sdram_init
	bl copy2sram
	bl cleanbss
close_watchdog:
	ldr r0, =0x53000000
	ldr r1, =0
	str r1, [r0]
	mov pc,lr
clock_config:
	ldr r0, =0x4C000000
	ldr r1, =0xFFFFFFFF
	str r1, [r0]

	ldr r0, =0x4C000014
	ldr r1, =0x5
	str r1, [r0]

	mrc p15,0,r0,c1,c0,0
	orr r0,r0,#0xc0000000  
	mcr p15,0,r0,c1,c0,0

	ldr r0, =0x4C000004
	ldr r1, =(92<<12)|(1<<4)|(1<<0)
	str r1, [r0]
	mov pc,lr
start_on_flash:
	mov r1, #0
	ldr r0, [r1] 
	str r1, [r1] 
	ldr r2, [r1] 
	cmp r1, r2   
	ldr sp, =0x40000000+4096
	moveq sp, #4096  
	streq r0, [r1]   
	mov pc,lr

copy2sram:
	mov r0,#0
	ldr r1,= _code_start
	ldr r2,= _bss_start
copy:
	ldr r3,[r0]
	str r3,[r1]
	add r1,r1,#4
	add r0,r0,#4
	cmp r1,r2
	ble copy

cleanbss:
	mov r0,#0
	ldr r1,= _bss_start
	ldr r2,= _end
clean:	
	str r0,[r1]
	add r1,r1,#4
	cmp r1,r2
	ble clean
//	bl main	
	ldr pc, =main  

halt:
	b halt
.end
