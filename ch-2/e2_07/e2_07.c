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
#include <stdlib.h>

uint64_t invert(uint64_t x, uint8_t p, uint8_t n);

int main(void)
{
    char x_str[32] = {0}, p_str[8] = {0}, n_str[8] = {0};
    uint64_t x;
    uint8_t p, n;

    /* User input */
    printf("Enter x in decimal form (max. 32-digits): ");
    fgets(x_str, 32, stdin);
    printf("Enter p in decimal form (max. 8-digits): ");
    fgets(p_str, 8, stdin);
    printf("Enter n in decimal form (max. 8-digits): ");
    fgets(n_str, 8, stdin);

    /* Convert input values to integer */
    x = strtoll(x_str, NULL, 10);
    p = strtol(p_str, NULL, 10);
    n = strtol(n_str, NULL, 10);

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
    if ((p < (n-1)) || (p > 63))
        return 0;

    uint64_t mask = ~(~0 << n) << (p-n+1);
    return x ^ mask;
}
