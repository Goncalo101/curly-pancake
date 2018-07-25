[bits 32]

VIDEO_MEMORY equ 0xb8000
WHITE_ON_BLACK equ 0x0f

print_string_pm:
	pusha
	mov edi, VIDEO_MEMORY ; moving video_memory to edi allows the usage of special instructions

print_string_pm_loop:
	lodsb ; load a byte from esi into al
	mov ah, WHITE_ON_BLACK

	cmp al, 0
	je print_string_pm_done

	stosw ; store value from ax in position referenced by edi

	jmp print_string_pm_loop

print_string_pm_done:
	popa
	ret
