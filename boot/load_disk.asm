disk_load:
	pusha

	push dx  ; overwrites input parameters from dx

	mov ah, 0x02 ; int 0x13 requires ah = 0x02 to read
	mov al, dh ; number of sectors to read
	mov cl, 0x02 ; sector that follows the bootsector
	mov ch, 0x00 ; cylinder
	mov dh, 0x00 ; head number

	; [es:bx] -> pointer to buffer where the data will be stored
	int 0x13
	jc disk_error

	pop dx
	cmp al, dh ; BIOS sets al to the number of sectors read
	jne sectors_error
	popa
	ret

disk_error:
	mov si, DISK_ERROR
	call print

sectors_error:
	mov si, SECTORS_ERROR
	call print

disk_loop:
	jmp $

DISK_ERROR db 'Disk read error', 13, 10, 0
SECTORS_ERROR db 'Incorrect number of sectors read', 13, 10, 0
