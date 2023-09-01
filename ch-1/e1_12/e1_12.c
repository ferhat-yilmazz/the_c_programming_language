// Author: Ferhat Yilmaz
// 
// Compiler: Apple clang version 14.0.3 
//
// Exercise 1-12
// ------------
// Write a progrma that prints its input one word per line.
//
// (EOF signal can be inserted by using <CRTL+D> in the Unix-like systems.)

#include <stdio.h>
#include <string.h>

#define WHITESPACE_CHARS " \t\n\r\f\v" // Define all white space characters

int main(void)
{
    int ch, prev_ch = 0;

    // Except white space characters, each character should belong to a word
    while((ch = getchar()) != EOF)
    {
        // To detect the character is belong white space or not, <strchr()>
        // function will be used which located <string.h>
        //
        // <strchr()> function returns location of the character in the
        // specified string. If it does not find, then returns NULL
        //
        // Briefly the algorithm is:
        // IF "current character" is white space AND
        // "previous character" is NOT white space THEN print newline
        //
        // IF "current character" is NOT white space, THEN print it
        if ((strchr(WHITESPACE_CHARS, ch) != NULL) &&\
            (strchr(WHITESPACE_CHARS, prev_ch) == NULL)) 
            printf("\n");
        
        if (strchr(WHITESPACE_CHARS, ch) == NULL)
            printf("%c", ch);

        prev_ch = ch;
    }

    printf("\n\n>> Bye...\n");

    return 0;
}
