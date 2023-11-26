/*
 * Written by Ferhat Yilmaz <ferhatyilmaz.me@pm.me>, 2023
 *
 * Exercise 2-8
 * ------------
 * Write a function rightrot(x,n) that returns the value of the integer x
 * rotated to the right by n bit positions.
 */

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

uint64_t rightrot(uint64_t x, uint8_t n);

int main(void)
{
    char x_str[32] = {0}, n_str[32] = {0};
    uint64_t x;
    uint8_t n;

    /* User input */
    printf("Enter x in decimal format: ");
    if (fgets(x_str, 32, stdin) == NULL) {
        perror("Error reading input!");
        return 1;
    }
    printf("Enter n in decimal format: ");
    if (fgets(n_str, 32, stdin) == NULL) {
        perror("Error reading input!");
        return 1;
    }

    /* Convert input */
    x = strtoll(x_str, NULL, 10);
    n = strtol(n_str, NULL, 10);

    /* Result must be: 1100 1100 */
    printf("%" PRIx64 "\n", rightrot(x, n));
    return 0;
}

/**
 * rightrot - Rotate right integer x by n bit positions
 * @param x: 64-bit unsigned number
 * @param n: Bit position
 * @return Rotated x integer
 */
uint64_t rightrot(uint64_t x, uint8_t n)
{
    if (n != n % 64) return 0;

    uint64_t rightmost = x & ~(~0 << n); // << (64 - n)
    uint64_t leftmost = x >> (n + 1);
    uint64_t nth = (x >> n) & 1;

    return (rightmost << (64 - n)) | (nth << (64 - n - 1)) | leftmost;
}
