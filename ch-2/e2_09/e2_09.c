/*
 * Written by Ferhat Yilmaz <ferhatyilmaz.me@pm.me>, 2023
 *
 * Exercise 2-9
 * ------------
 * In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
 * in x. Explain why. Use this observation to write faster version of bitcount.
 *
 *  bitcount: count 1 bits in x
 *      int bitcount(unsigned x)
 *      {
 *          int b;
 *
 *          for (b = 0; x != 0; x >>= 1)
 *              if (x & 01)
 *                  b++;
 *
 *          return b;
 *      }
 */

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

/*
 * In a two's complement number system, when the number is decremented by 1,
 * rightmost 1 bit of the number changed as 0. Left-side bits of the 1-bit
 * stay as unchanged. Thus, when we apply AND operation to these numbers,
 * unchanged bits stay and others turn to zero. Thereby, rightmost 1-bit is
 * removed.
 */

uint8_t bitcount_fast(uint64_t x);

int main(void)
{
    char x_str[32];
    uint64_t x;

    /* User input */
    printf("Enter x in decimal form (max. 32-digits): ");
    fgets(x_str, 32, stdin);

    /* Convert input values to integer */
    x = strtoll(x_str, NULL, 10);

    printf("%" PRIu8 "\n", bitcount_fast(x));

    return 0;
}

/**
 * bitcount_fast - Return the number of 1-bits of x
 * @param x: Integer to count 1-bits
 * @return Count of 1-bits
*/
uint8_t bitcount_fast(uint64_t x)
{
    uint8_t count = (x > 0);

    while ((x &= (x-1)) > 0)
        count++;

    return count;
}
