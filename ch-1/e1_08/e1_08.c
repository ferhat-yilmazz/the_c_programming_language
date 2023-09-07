// Author: Ferhat Yilmaz <ferhatyilmaz.me@pm.me>
// 
// Compiler: Apple clang version 14.0.3 
//
// Exercise 1-8
// ------------
// Write a program to count blanks, tabs, and newlines.
//
// (EOF signal can be inserted by using <CRTL+D> in the Unix-like systems.)

#include <stdio.h>

int main(void)
{
    // Decleration and definition of a variable to hold count of white-spaces
    int ws_counts = 0;
    int ch;

    while ((ch = getchar()) != EOF)
        if ((ch == ' ') || (ch == '\t') || (ch == '\n'))
            ws_counts++;

    // Print result when EOF inserted
    printf("\n\n>> %d\n", ws_counts);

    return 0;
}

