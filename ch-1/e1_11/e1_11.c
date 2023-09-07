// Author: Ferhat Yilmaz <ferhatyilmaz.me@pm.me>
// 
// Compiler: Apple clang version 14.0.3 
//
// Exercise 1-11
// ------------
// How would you test the word count program? What kinds of input are most
// likely to uncover bugs if there are any?
//
// (EOF signal can be inserted by using <CRTL+D> in the Unix-like systems.)

#include <stdio.h>

#define IN 1    /* inside a word */
#define OUT 0   /* outside a word */

/* counts lines, words, and characters in input */
int main(void)
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    char *solution =    "< SOLUTION >\n"
                        "As you can see, backspace sequence '\\b', vertical tab"
                        "\nsequence '\\v', carriage return '\\r' etc. are not\n"
                        "considered in the program. These characters accepted\n"
                        "as a new word. It is a bug.\n"
                        "You can test by using terminal in Unix-like system:\n"
                        "^H : backspace character\n"
                        "^K : vertical tab character etc.\n\n";

    printf("%s", solution);

    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
            ++nl;

        /* SOLUTION:
        * As you can see, backspace sequence '\b', vertical tab sequence '\v'
        * carriage return '\r' etc. are not considered in the program. These
        * characters accepted as a new word. It is a bug.
        * You can test it by using terminal in Unix-like system:
        * ^H : backspace character
        * ^K : vertical tab character etc.
        */
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }

    printf("\n\n>>nl: %d | nw: %d | nc: %d\n", nl, nw, nc);

    return 0;
}
