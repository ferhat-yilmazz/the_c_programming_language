/*
 * Written by Ferhat Yilmaz <ferhatyilmaz.me@pm.me>, 2023
 *
 * Compiler: gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
 *
 * Exercise 2-5
 * ------------
 * Write the function any(s1, s2), which returns the first location in the
 * string s1 where any character from the string s2 occurs, or -1 if s1 contains
 * no characters from s2. (The standard library function strpbrk does the same
 * job but returns pointer to the location.)
 */

#include <stdio.h>
#include <string.h>

#define S1 "The C Programming Language, K&R"
#define S2 ",&"

long int any(const char *s1, const char *s2);

int main(void)
{
    printf("\ns1: \"%s\"\ns2: \"%s\"\nidx: %ld\n", S1, S2, any(S1,S2));

    return 0;
}

/**
 * any - Find index of the first common character
 * @s1: Null-terminated byte string to be analyzed
 * @s2: Null-terminated byte string which contains character set to be looking
 *      for
 *
 * Analyze @s1 to find index of first character which given in the @s2. If there
 * is not such a character than return -1.
*/
long int any(const char *s1, const char *s2)
{
    char *str = NULL;

    if ((str = strpbrk(s1, s2)))
        return (str - s1);
    else
        return -1;
}
