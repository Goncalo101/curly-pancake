print_hex:
	pusha
  std ; set direction to fill hex_out from right to left

	mov cx, 4 ; loop 4 times
  mov di, hex_out + 5 ; di points to the last character in hex_out

hex_loop:
	mov ax, dx ; hex value to print is in dx
	and ax, 0x000f ; mask value in ax to get the last byte

	add al, 0x30 ; add al, 48
	cmp al, 0x39
	jle step2 ; if value in al is a number, move to step2
	add al, 7 ; else, make it a capital letter

step2:
	stosb ; move value in al to memory referenced by di
	ror dx, 4

	loop hex_loop

finish:
  cld ; clear direction

  ; prepare for print
	mov si, hex_out
	call print

	popa
	ret

hex_out db '0x0000', 0
