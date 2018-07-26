#include "ports.h"

// Read a byte from the specified port
u8 port_byte_in(u16 port) {
  u8 result;

  /* "=a" (result)'; set '=' the C variable '(result)' to the value of register
  * e'a'x
  *  '"d" (port)': map the C variable '(port)' into e'd'x register
  *
  * Inputs and outputs are separated by colons
  */

  __asm__("in %%dx, %%al" : "=a"(result) : "d"(port));
  return result;
}

// when requesting data from a VGA register, the result is in a different port,
// which requires us to use port_byte_in to get it
void port_byte_out(u16 port, u8 data) {
  __asm__("out %%al, %%dx" : : "a"(data), "d"(port));
}

u16 port_word_in(u16 port) {
  u16 result;

  __asm__("in %%dx, %%ax" : "=a"(result) : "d"(port));

  return result;
}

void port_word_out(u16 port, u16 data) {
  __asm__("out %%ax, %%dx" : : "a"(data), "d"(port));
}
