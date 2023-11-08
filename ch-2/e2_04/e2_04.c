/*
 * Written by Ferhat Yilmaz <ferhatyilmaz.me@pm.me>, 2023
 *
 * Compiler: gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
 *
 * Exercise 2-4
 * ------------
 * Write an alternate version of squeeze(s1, s2) that deletes each character in
 * s1 that matches any character in the string s2.
 *
 * Given squeeze(char *, int) function in the book:
 *  void squeeze(char s[], int c)
 *  {
 *      int i,j;
 *
 *      for (i = j = 0; s[i] != '\0'; i++)
 *          if (s[i] != c)
 *              s[j++] = s[i];
 *      s[j] = '\0';
 *  }
 */

#include <stdio.h>
#include <string.h>

#define CHAR_LIST "evR"

void squeeze(char *s1, const char *s2);

int main(void)
{
    char text[] = "foreveR Islam";

    printf("Original Text ->  %s\n", text);
    printf("\nCharacter List -> %s\n\n", CHAR_LIST);

    squeeze(text, CHAR_LIST);
    printf("Squeezed Text ->  %s\n", text);

    return 0;
}

/**
 * squeeze - Squeeze text from the given characters
 * @s1: Text will be squeezed
 * @s2: Character set
 *
 * Remove all characters given with @s2 from the mutable @s1 string.
*/
void squeeze(char *s1, const char *s2)
{
    int i, j;

    for (i = j = 0; s1[i] != '\0'; ++i)
        if (!strchr(s2, s1[i]))
            s1[j++] = s1[i];
    s1[j] = '\0';
}
