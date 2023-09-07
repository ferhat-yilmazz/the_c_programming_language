// Author: Ferhat Yilmaz <ferhatyilmaz.me@pm.me>
// 
// Compiler: Apple clang version 14.0.3 
//
// Exercise 1-10
// ------------
// Write a program to copy its input to its output, replacing each tab by \t,
// each bacspace by \b, and each backslash by \\. This makes tabs and
// backspaces visible in an unambiguous way.
//
// (EOF signal can be inserted by using <CRTL+D> in the Unix-like systems.)

#include <stdio.h>

int main(void)
{
    int ch;

    while ((ch = getchar()) != EOF)
        switch (ch)
        {
        case '\t':
            printf("\\t");
            break;
        case '\b':
            printf("\\b");
            break;
        case '\\':
            printf("\\\\");
            break;
        default:
            printf("%c", ch);
        }

    printf("\n\n>> Bye...\n");
    
    return 0;
}
