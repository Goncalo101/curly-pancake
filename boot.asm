[org 0x7c00]
mov bp, 0x9000 ; set the stack
mov sp, bp

mov si, MSG_REAL_MODE
call print ; This will be written after the BIOS messages

call switch_to_pm
jmp $ ; this will never be executed

%include "boot_utils/print.asm"
%include "load_disk.asm"
%include "gdt.asm"
%include "32bit-print.asm"
%include "switch.asm"

[bits 32]
BEGIN_PM: ; after the switch we will get here
    mov esi, MSG_PROT_MODE
    call print_string_pm ; Note that this will be written at the top left corner
    jmp $

MSG_REAL_MODE db "Started in 16-bit real mode", 0
MSG_PROT_MODE db "Loaded 32-bit protected mode", 0

times 510 - ($-$$) db 0
dw 0xaa55 ; magic number (BIOS will consider the device bootable if it finds
          ; 0x55 and 0xAA in the last 2 bytes of the bootsector)
