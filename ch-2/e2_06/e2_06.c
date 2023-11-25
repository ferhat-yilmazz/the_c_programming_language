/*
 * Written by Ferhat Yilmaz <ferhatyilmaz.me@pm.me>, 2023
 *
 * Compiler: gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
 *
 * Exercise 2-6
 * ------------
 * Write a function setbits(x,p,n,y) that returns x with the n bits that begin
 * at position p set to the rightmost n bits of y, leaving the other bits
 * unchanged.
 */

#include <stdio.h>
#include <inttypes.h>

uint64_t setbits(uint64_t x, uint8_t p, uint8_t n, uint64_t y);

int main(void)
{
    uint64_t x = 0xFF; /* 1111 1111 */
    uint64_t y = 0xCA; /* 1100 1010 */
    uint8_t p = 5;
    uint8_t n = 3;

    /* Result must be: 1101 0111 */

    printf("%" PRIx64 "\n", setbits(x, p ,n, y));
    return 0;
}

/**
 * setbits - Assign right end @n bits of @y to [@p, p-n+1] bits of @x
 * @x: Assignee number
 * @p: Start index of bits
 * @n: Size of bits
 * @y: Assigned number
*/
uint64_t setbits(uint64_t x, uint8_t p, uint8_t n, uint64_t y)
{
    if ((p - n + 1) < 0)
        return 0;
    
    uint64_t y_rightmost_n = y & (~(~0 << n));
    uint64_t x_masked = x & ~(~(~0 << n) << (p-n+1));
    uint64_t n_mask = y_rightmost_n << (p-n+1);

    return x_masked | n_mask;
}
