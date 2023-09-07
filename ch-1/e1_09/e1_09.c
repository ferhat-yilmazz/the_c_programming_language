// Author: Ferhat Yilmaz <ferhatyilmaz.me@pm.me>
// 
// Compiler: Apple clang version 14.0.3 
//
// Exercise 1-9
// ------------
// Write a program to copy its input to its output, replacing each string of
// one or more blanks by a single blank.
//
// (EOF signal can be inserted by using <CRTL+D> in the Unix-like systems.)

#include <stdio.h>

int main(void)
{
    int ch, prev_ch = 0;

    while ((ch = getchar()) != EOF) {
        if (prev_ch == ' ' && ch == ' ')
            continue;
        else
            printf("%c", (char)ch);

        prev_ch = ch;
    }

    printf("\n\n>>Bye...\n");
    
    return 0;
}
