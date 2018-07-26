#ifndef TYPES_H
#define TYPES_H

/* defines new types with no semantic meaning */
typedef unsigned int u32;
typedef int s32;
typedef unsigned short u16;
typedef short s16;
typedef unsigned char u8;
typedef char s8;

// define functions to return the low or high 16 bits of an address
#define low_16(address) (u16)((address)&0xFFFF)
#define high_16(address) (u16)(((address) >> 16) & 0xFFFF)

#endif
