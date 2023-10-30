/*
 * Written by Ferhat Yilmaz <ferhatyilmaz.me@pm.me>, 2023
 *
 * Compiler: gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
 *
 * Exercise 2-2
 * ------------
 * Write a loop equivalent to the for loop below without using && or ||.
 *
 *  for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 *      s[i] = c;
 */

#include <stdio.h>

#define MSG_INFO ">> INFO\nEOF signal can be inserted by using <CTRL+D> on" \
                    " the Unix-like systems.\n" \
                    "Line size limit is %d characters.\n\n>> INPUT\n"
#define LIMIT 1000 /* Line limit */

int main(void)
{
    char c, s[LIMIT];
    int i;

    printf(MSG_INFO, LIMIT);

    for (i = 0; i < (LIMIT-1); i++) {
        c = (char)getchar();
        if (c != EOF) {
            if (c != '\n') {
                s[i] = c;
            } else
                break;
        } else
            break;
    }

    /* Assign null pointer */
    s[i] = '\0';

    printf("\n>> OUTPUT\n%s\n", s);
    /* Bye */
    printf("\n>> BYE...\n");

    return 0;
}
