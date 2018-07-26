#include "kernel.h"
#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "../libc/mem.h"
#include "../libc/string.h"

void kernel_main() {
  // // clear_screen();
  // // kprint_at("X", 1, 6);
  // // kprint_at("This text spans multiple lines", 75, 10);
  // // kprint_at("There is a line\nbreak", 0, 20);
  // // kprint("There is a line\nbreak");
  // // kprint_at("What happens when we run out of space?", 45, 24);
  //
  // isr_install();
  // /* Test the interrupts */
  // // __asm__ __volatile__("int $31");
  // // __asm__ __volatile__("int $3");
  //
  // init_timer(50);
  //
  // /* Comment out the timer IRQ handler to read
  //  * the keyboard IRQs easier */
  // init_keyboard();

  isr_install();
  irq_install();

  kprint("Type something, it will go through the kernel\n"
         "Type END to halt the CPU\n> ");
}

void user_input(char *input) {
  if (strcmp(input, "END") == 0) {
    kprint("Stopping the CPU. Bye!\n");
    asm volatile("hlt");

  } else if (strcmp(input, "PAGE") == 0) {

    /* Code to test kmalloc */
    uint32_t phys_addr;
    uint32_t page = kmalloc(1000, 1, &phys_addr);
    char page_str[16] = "";
    hex_to_ascii(page, page_str);
    char phys_str[16] = "";
    hex_to_ascii(phys_addr, phys_str);
    kprint("Page: ");
    kprint(page_str);
    kprint(", physical address: ");
    kprint(phys_str);
    kprint("\n");
  }

  kprint("You said: ");
  kprint(input);
  kprint("\n> ");
}
