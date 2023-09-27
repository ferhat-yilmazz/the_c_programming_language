/*
 * Written by Ferhat Yilmaz, 2023.
 * <ferhatyilmaz.me@pm.me>
 *
 * Compiler: Apple clang version 15.0.0
 *
 * Exercise 2-1
 * ------------
 * Write a program to determine the ranges of char, short, int, and long
 * variables, both signed and unsigned, by printing appropriate values from
 * standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types.
 *
 * Developer Notes
 * ---------------
 * Computational method for the 'long double' type is not exist. I try,
 * but I could not solve.
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <stdint.h>

void determine_signed_char_limits(void);
void determine_unsigned_char_limits(void);
void determine_signed_short_limits(void);
void determine_unsigned_short_limits(void);
void determine_signed_int_limits(void);
void determine_unsigned_int_limits(void);
void determine_signed_long_limits(void);
void determine_unsigned_long_limits(void);
void determine_float_limits(void);
void determine_double_limits(void);
void determine_long_double_limits(void);

int main(void)
{
    /* Print limits by using header macro */
    printf("## Limits by Using Header Macro ##\n");
    printf("----------------------------------\n");
    printf("signed char:    %20d | %20d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char:  %20d | %20d\n", 0,  UCHAR_MAX);
    printf("signed short:   %20d | %20d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: %20d | %20d\n", 0, USHRT_MAX);
    printf("signed int:     %20d | %20d\n", INT_MIN, INT_MAX);
    printf("unsigned int:   %20u | %20u\n", 0, UINT_MAX);
    printf("signed long:    %20ld | %20ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long:  %20d | %20lu\n", 0, ULONG_MAX);
    printf("float:                 -%12e | %20e\n", FLT_MAX, FLT_MAX);
    printf("double:               -%13e | %20e\n", DBL_MAX, DBL_MAX);
    printf("long double:         -%14Le | %20Le\n", LDBL_MAX, LDBL_MAX);

    printf("\n\n");

    /* Print limits by using calculation */
    printf("## Limits by Using Calculation ##\n");
    printf("---------------------------------\n");
    determine_signed_char_limits();
    determine_unsigned_char_limits();
    determine_signed_short_limits();
    determine_unsigned_short_limits();
    determine_signed_int_limits();
    determine_unsigned_int_limits();
    determine_signed_long_limits();
    determine_unsigned_long_limits();
    determine_float_limits();
    determine_double_limits();
    determine_long_double_limits();


    /* Bye */
    printf("\n\n>> BYE...\n");

    return 0;
}

/**
 * determine_signed_char_limits - Print limits of signed char
 *
 * Determine limits of signed char type by calculation method instead of
 * by using <limits.h> macro. Print out result in proper format.
 */
void determine_signed_char_limits(void)
{
    char current, previous, max, min;

    /* Determine maximum limit */
    current = 1;
    previous = 0;
    while((current = (current << 1) | 1) > previous)
        previous = current;
    max = previous;

    /* Determine minimum limit */
    current = -1;
    previous = 0;
    while((current = current << 1) < previous)
        previous = current;
    min = previous;

    printf("signed char:    %20d | %20d\n", min, max);
}

/**
 * determine_unsigned_char_limits - Print limits of unsigned char
 *
 * Determine limits of unsigned char type by calculation method instead of
 * by using <limits.h> macro. Print out result in proper format.
 */
void determine_unsigned_char_limits(void)
{
    unsigned char current, previous, max, min;

    /* Determine maximum limit */
    current = 1;
    previous = 0;
    while((current = (current << 1) | 1) > previous)
        previous = current;
    max = previous;

    /* Determine minimum limit */
    current = -1;
    previous = 0;
    while((current = current << 1) < previous)
        previous = current;
    min = previous;

    printf("unsigned char:  %20d | %20d\n", min, max);
}

/**
 * determine_signed_short_limits - Print limits of signed short
 *
 * Determine limits of signed short type by calculation method instead of
 * by using <limits.h> macro. Print out result in proper format.
 */
void determine_signed_short_limits(void)
{
    short current, previous, max, min;

    /* Determine maximum limit */
    current = 1;
    previous = 0;
    while((current = (current << 1) | 1) > previous)
        previous = current;
    max = previous;

    /* Determine minimum limit */
    current = -1;
    previous = 0;
    while((current = current << 1) < previous)
        previous = current;
    min = previous;

    printf("signed short:   %20d | %20d\n", min, max);
}

/**
 * determine_unsigned_short_limits - Print limits of unsigned short
 *
 * Determine limits of unsigned short type by calculation method instead of
 * by using <limits.h> macro. Print out result in proper format.
 */
void determine_unsigned_short_limits(void)
{
    unsigned short current, previous, max, min;

    /* Determine maximum limit */
    current = 1;
    previous = 0;
    while((current = (current << 1) | 1) > previous)
        previous = current;
    max = previous;

    /* Determine minimum limit */
    current = -1;
    previous = 0;
    while((current = current << 1) < previous)
        previous = current;
    min = previous;

    printf("unsigned short: %20d | %20d\n", min, max);
}

/**
 * determine_signed_int_limits - Print limits of signed int
 *
 * Determine limits of signed int type by calculation method instead of
 * by using <limits.h> macro. Print out result in proper format.
 */
void determine_signed_int_limits(void)
{
    int current, previous, max, min;

    /* Determine maximum limit */
    current = 1;
    previous = 0;
    while((current = (current << 1) | 1) > previous)
        previous = current;
    max = previous;

    /* Determine minimum limit */
    current = -1;
    previous = 0;
    while((current = current << 1) < previous)
        previous = current;
    min = previous;

    printf("signed int:     %20d | %20d\n", min, max);
}

/**
 * determine_unsigned_int_limits - Print limits of unsigned int
 *
 * Determine limits of unsigned int type by calculation method instead of
 * by using <limits.h> macro. Print out result in proper format.
 */
void determine_unsigned_int_limits(void)
{
    unsigned int current, previous, max, min;

    /* Determine maximum limit */
    current = 1;
    previous = 0;
    while((current = (current << 1) | 1) > previous)
        previous = current;
    max = previous;

    /* Determine minimum limit */
    current = -1;
    previous = 0;
    while((current = current << 1) < previous)
        previous = current;
    min = previous;

    printf("unsigned int:   %20u | %20u\n", min, max);
}

/**
 * determine_signed_long_limits - Print limits of signed long
 *
 * Determine limits of signed long type by calculation method instead of
 * by using <limits.h> macro. Print out result in proper format.
 */
void determine_signed_long_limits(void)
{
    long current, previous, max, min;

    /* Determine maximum limit */
    current = 1;
    previous = 0;
    while((current = (current << 1) | 1) > previous)
        previous = current;
    max = previous;

    /* Determine minimum limit */
    current = -1;
    previous = 0;
    while((current = current << 1) < previous)
        previous = current;
    min = previous;

    printf("signed long:    %20ld | %20ld\n", min, max);
}

/**
 * determine_unsigned_long_limits - Print limits of unsigned long
 *
 * Determine limits of unsigned long type by calculation method instead of
 * by using <limits.h> macro. Print out result in proper format.
 */
void determine_unsigned_long_limits(void)
{
    unsigned long current, previous, max, min;

    /* Determine maximum limit */
    current = 1;
    previous = 0;
    while((current = (current << 1) | 1) > previous)
        previous = current;
    max = previous;

    /* Determine minimum limit */
    current = -1;
    previous = 0;
    while((current = current << 1) < previous)
        previous = current;
    min = previous;

    printf("unsigned long:  %20lu | %20lu\n", min, max);
}

/**
 * determine_float_limits - Print limits of float
 *
 * Determine limits of float type by calculation method instead of
 * by using <limits.h> macro. To calculate max/min value of  single-precision
 * floating number IEEE 754 standard will be used. According to the standard
 * single-precision floating number consist of 32 bits, such that:
 * -> Sign bit: 1 bit
 * -> Exponent: 8 bits
 * -> Mantissa: 23 bits
 * Print out result in proper format.
 */
void determine_float_limits(void)
{
     /* Maximum biased exponent for single-precision float */
    int max_exponent = 127;
    /* Calculate approximate FLT_MAX */
    float max_float = ldexpf(2.0f - powf(2, -23), max_exponent);

    printf("float:                 -%12e | %20e\n", max_float, max_float);
}

/**
 * determine_double_limits - Print limits of double
 *
 * Determine limits of double type by calculation method instead of
 * by using <limits.h> macro. To calculate max/min value of  double-precision
 * floating number IEEE 754 standard will be used. According to the standard
 * single-precision floating number consist of 32 bits, such that:
 * -> Sign bit: 1 bit
 * -> Exponent: 11 bits
 * -> Mantissa: 52 bits
 * Print out result in proper format.
 */
void determine_double_limits(void)
{
    /*
     * Define the components of a double-precision IEEE 754 number
     * Sign bit: 0 for positive
     */
    uint64_t sign_bit = 0;
    /* Maximum finite exponent value */
    uint64_t exponent_bits = 0x7FE;
    /* All 1's in fraction bits for max value */
    uint64_t fraction_bits = 0xFFFFFFFFFFFFF;

    /* Combine the components to form the IEEE 754 representation */
    uint64_t ieee_754_bits = (sign_bit << 63) |
            (exponent_bits << 52) | fraction_bits;

    /* Interpret the bits as a double-precision floating-point number */
    double max_double = *(double*)&ieee_754_bits;

    printf("double:               -%13e | %20e\n", max_double, max_double);
}

/**
 * determine_long_double_limits - Print limits of long double
 *
 * Determine limits of long double type by calculation method instead of
 * by using <limits.h> macro. To calculate max/min value of long
 * double-precision floating number IEEE 754 standard will be used.
 * According to the standard single-precision floating number consist
 * of 32 bits, such that:
 * -> Sign bit: 1 bit
 * -> Exponent: 15 bits
 * -> Integer part: 1 bit
 * -> Mantissa: 63 bits
 * Print out result in proper format.
 */
void determine_long_double_limits(void)
{
    /* Solution is not exist */
}