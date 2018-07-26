#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

// define functions to return the low or high 16 bits of an address
#define low_16(address) (uint16_t)((address)&0xFFFF)
#define high_16(address) (uint16_t)(((address) >> 16) & 0xFFFF)

#endif
