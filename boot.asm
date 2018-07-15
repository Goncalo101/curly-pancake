loop: ; infinite loop
	jmp loop

times 510 - ($-$$) db 0
dw 0xaa55 ; magic number (BIOS will consider the device bootable if it finds
          ;0x55 and 0xAA in the last 2 bytes of the bootsector)
