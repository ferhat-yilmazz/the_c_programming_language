/*
 * Written by Ferhat Yilmaz <ferhatyilmaz.me@pm.me>, 2023
 *
 * Exercise 2-10
 * ------------
 * Rewrite the function lower, which converts upper case letters to lower case,
 * with a conditional expression instead of if-else.
 *
 *  lower: convert c to lower case; ASCII only
 *      int lower(int c)
 *      {
 *          if (c >= 'A' && c <= 'Z')
 *              return c + 'a' - 'A';
*           else
 *              return c;
 *      }
 */

#include <stdio.h>

#define MSG_INFO ">> INFO\nEOF signal can be inserted by "\
                    "using <CTRL+D> on the Unix-like systems.\n\n"

int lower(int c);

int main(void)
{
    int c;

    printf(MSG_INFO);

    while ((c = getchar()) != EOF)
        putchar(lower(c));

    printf("\n>> BYE...\n");

    return 0;
}

/**
 * lower - Convert x to lower case; ASCII only
 * @param c: ASCII alphabetic character
 * @return Lower case of c
*/
int lower(int c)
{
    /* Since ASCII table is fixed; then use 32 instead of ('a' - 'A') */
    return (c >= 'A' && c <= 'Z') ? (c + 32) : c;
}
