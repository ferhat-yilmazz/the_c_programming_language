// Author: Ferhat Yilmaz <ferhatyilmaz.me@pm.me>
//
// Compiler: Apple clang version 14.0.3
//
// Exercise 1-20
// -------------
// Write a program "detap" that replaces tabs in the input with the proper
// number of blanks to space to the next tab stop. Assume a fixed set of tab
// stops, say every <n> columns. Should <n> be a variable or a symbolic
// parameter?
//
// Note: For flexibility, we will design the <n> as a symbolic parameter.

#include <stdio.h>

#define N 4 // Tab stop size

int main(void)
{
    char ch;
    int pos = 1;

    // There is a calculation for tab stop point. Mod of the cursor position
    // according to tab stop size shall be 1. When tab inserted, until reach
    // this result a space character shall be added.
    // For each new line cursor position must be reset.
    while ((ch = getchar()) != EOF)
        if (ch == '\t')
            while (pos % N != 1)
            {
                putchar(' ');
                pos++;
            }
        else if (ch == '\n')
        {
            putchar(ch);
            pos = 1;
        }
        else
        {
            putchar(ch);
            pos++;
        }

    // Bye
    printf("\n\n>> Bye...\n");

    return 0;
} 
