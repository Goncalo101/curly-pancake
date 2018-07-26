; address of string in si register
print:
  push ax
  push si

  mov ah, 0x0e ; only works in BIOS mode, outputs to screen

print_loop:
  lodsb ; move value referenced by si to al and increment al

  cmp al, 0
  je end

  int 0x10
  jmp print_loop

end:
  pop si
  pop ax
  ret
