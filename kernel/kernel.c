#include "../drivers/screen.h"
#include "utils.h"
#include "../cpu/isr.h"
#include "../cpu/idt.h"

void main() {
    // clear_screen();
    // kprint_at("X", 1, 6);
    // kprint_at("This text spans multiple lines", 75, 10);
    // kprint_at("There is a line\nbreak", 0, 20);
    // kprint("There is a line\nbreak");
    // kprint_at("What happens when we run out of space?", 45, 24);

    isr_install();
    /* Test the interrupts */
    __asm__ __volatile__("int $2");
    __asm__ __volatile__("int $3");
}
