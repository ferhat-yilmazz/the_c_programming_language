/*
 * Written by Ferhat Yilmaz <ferhatyilmaz.me@pm.me>, 2023
 *
 * Exercise 2-7
 * ------------
 * Write a function invert(x,p,n) that returns x with the n bits that begin
 * at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the
 * others unchanged.
 */

#include <stdio.h>
#include <inttypes.h>

uint64_t invert(uint64_t x, uint8_t p, uint8_t n);

int main(void)
{
    uint64_t x = 0xAC; /* 1010 1100 */
    uint8_t p = 6;
    uint8_t n = 2;

    /* Result must be: 1100 1100 */
    printf("%" PRIx64 "\n", invert(x, p ,n));
    return 0;
}

/**
 * invert - Invert specified bits and leave others
 * @x: 64-bit number
 * @p: Start position of bits to invert (0-based)
 * @n: Size of bits
 */
uint64_t invert(uint64_t x, uint8_t p, uint8_t n)
{
    if ((p-n+1) < 0) return 0;

    uint64_t mask = ~(~0 << n) << (p-n+1);
    return x ^ mask;
}
