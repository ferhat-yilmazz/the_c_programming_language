// Author: Ferhat Yilmaz <ferhatyilmaz.me@pm.me>
//
// Compiler: Apple clang version 14.0.3
//
// Exercise 1-19
// -------------
// Write a function <reverse(s)> that reverses the character string <s>. Use
// it to write a program that reverses its input a line at a time.

#include <stdio.h>

#define MSG_INFO    ">> Info: EOF signal can be inserted by"\
                    "using <CRTL+D>\n   in the Unix-like systems.\n\n"\
                    ">> Please type a line and send EOF signal to end.\n"\
                    "   Input line must be limited with  %d characters.\n"\
                    "   Only ASCII characters are supported.\n\n"
#define MAX_LINE_LENGTH 1000

// Function prototype
void reverse(char * s);

int main(void)
{
    int line_length = 0;
    char line[MAX_LINE_LENGTH], ch;

    printf(MSG_INFO, MAX_LINE_LENGTH);

    while (((ch = getchar()) != EOF) && (line_length < (MAX_LINE_LENGTH-1)))
    {
        line[line_length] = ch;
        line_length++;

        if ((ch == '\n') || (line_length == (MAX_LINE_LENGTH-1)))
        {
            if (line_length == (MAX_LINE_LENGTH-1))
                printf(">> WARNING: Buffer capacity is full!!\n");

            line[line_length] = '\0';
            reverse(line);
            printf(">> %s\n\n", line);
            line_length = 0;
        }
    }

    // Bye
    printf("\n---------\n>> Bye...\n");

    return 0;
}

// Function definition
void reverse(char * s)
{
    int line_length;
    int head, tail;
    char temp;

    // Calculate line length
    for (line_length = 0; s[line_length] != '\0'; line_length++)
        ;
    // Remove any trailing blank or newline character
    while ( s[line_length] == '\0' || s[line_length] == '\n' ||\
            s[line_length] == '\t' || s[line_length] == ' ')
        line_length--;

    // Swap operation
    head = 0;
    tail = line_length;

    while (head <= tail)
    {
        temp = s[head];
        s[head] = s[tail];
        s[tail] = temp;
        head++;
        tail--;
    }

    s[line_length+1] = '\0';
}
