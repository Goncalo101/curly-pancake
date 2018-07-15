[org 0x7c00]

mov si, msg1
call print

mov dx, 0xcafe
call print_hex

jmp $

%include "boot_utils/print.asm"
%include "boot_utils/print_hex.asm"

msg1 db 'Hello World!', 13, 10, 0

times 510 - ($-$$) db 0
dw 0xaa55 ; magic number (BIOS will consider the device bootable if it finds
          ; 0x55 and 0xAA in the last 2 bytes of the bootsector)
