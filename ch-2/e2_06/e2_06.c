/*
 * Written by Ferhat Yilmaz <ferhatyilmaz.me@pm.me>, 2023
 * 
 * Exercise 2-6
 * ------------
 * Write a function setbits(x,p,n,y) that returns x with the n bits that begin
 * at position p set to the rightmost n bits of y, leaving the other bits
 * unchanged.
 */

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

uint64_t setbits(uint64_t x, uint8_t p, uint8_t n, uint64_t y);

int main(void)
{
    char x_str[32], y_str[32], p_str[8], n_str[8];
    uint64_t x, y;
    uint8_t p, n;

    /* User input */
    printf("Enter x in decimal form (max. 32-digits): ");
    fgets(x_str, 32, stdin);
    printf("Enter y in decimal form (max. 32-digits): ");
    fgets(y_str, 32, stdin);
    printf("Enter p in decimal form (max. 8-digits): ");
    fgets(p_str, 8, stdin);
    printf("Enter n in decimal form (max. 8-digits): ");
    fgets(n_str, 8, stdin);

    /* Convert input values to integer */
    x = strtoll(x_str, NULL, 10);
    y = strtoll(y_str, NULL, 10);
    p = strtol(p_str, NULL, 10);
    n = strtol(n_str, NULL, 10);

    printf("%" PRIx64 "\n", setbits(x, p ,n, y));
    return 0;
}

/**
 * setbits - Assign right-end n bits of y to [p, p-n+1] bits of x
 * @param x: Assignee number
 * @param p: Start index of bits
 * @param n: Size of bits
 * @param y: Assigned number
 * @return Modified version of x
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
