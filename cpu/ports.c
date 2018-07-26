#include "ports.h"

// Read a byte from the specified port
uint8_t port_byte_in(uint16_t port) {
  uint8_t result;

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
void port_byte_out(uint16_t port, uint8_t data) {
  __asm__("out %%al, %%dx" : : "a"(data), "d"(port));
}

uint16_t port_word_in(uint16_t port) {
  uint16_t result;

  __asm__("in %%dx, %%ax" : "=a"(result) : "d"(port));

  return result;
}

void port_word_out(uint16_t port, uint16_t data) {
  __asm__("out %%ax, %%dx" : : "a"(data), "d"(port));
}
