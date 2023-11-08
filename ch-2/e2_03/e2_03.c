/*
 * Written by Ferhat Yilmaz <ferhatyilmaz.me@pm.me>, 2023
 *
 * Compiler: gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
 *
 * Exercise 2-3
 * ------------
 * Write the function htoi(s), which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent integer value. The
 * allowable digits are 0 through 9, a through f, and A through F.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define USAGE "Usage: e2_03.out HEXADECIMAL\n"

int htoi(const char *s);

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf(USAGE);
        return EXIT_FAILURE;
    }

    printf("\n%s => %d\n\n", argv[1], htoi(argv[1]));
    return EXIT_SUCCESS;
}

/*
 * htoi - Convert hexadecimal string to integer equivalent
 * @s: Hexadecimal number in string
 *
 * Hexadecimal number should be in format: 0[xX][123456789abcdefABCDEF]
 * If the format of s is not proper, then return -1.
 * This function is valid only ASCII charset.
*/
int htoi(const char *s)
{
    #define INVALID "Invalid hexadecimal format!\n"

    const char *hex_digits = "0123456789ABCDEF";
    int dec = 0, ch;

    /* Check for hexadecimal header */
    if ((strstr(s, "0x") != s) && (strstr(s, "0X") != s)) {
        printf(INVALID);
        return -1;
    }

    for (int i = 2; (ch = toupper((int)s[i])) != '\0'; ++i) {
        /* Check validity of the hexadecimal part */
        if (strrchr(hex_digits, ch) == NULL) {
            printf(INVALID);
            return -1;
        }

        /* Determine decimal value of the hexadecimal string */
        dec = (dec * 16) + (isalpha(ch) ? (ch - 55) : (ch - 48));
    }

    return dec;
}
