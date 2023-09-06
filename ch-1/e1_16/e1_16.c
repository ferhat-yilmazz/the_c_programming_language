// Author: Ferhat Yilmaz <ferhatyilmaz.me@pm.me>
// 
// Compiler: Apple clang version 14.0.3 
//
// Exercise 1-16
// -------------
// Revise the main routine of the longest-line program so it will correctly
// print the length of arbitrarily long input lines, and as much as possible
// of the text.

#include <stdio.h>

#define MSG_INFO    ">> Info: EOF signal can be inserted by"\
                    "using <CRTL+D>\n   in the Unix-like systems.\n\n"\
                    ">> Please type a text and send EOF signal to end.\n"
#define MAXLINE 10

int get_line(char line[], int max_line);
void copy(char to[], char from[]);

int main(void)
{
    int len, max = 0;
    char line[MAXLINE], longest[MAXLINE];

    printf(MSG_INFO);

    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }

    if (max > 0)
        printf("\n\n>> Maximum Length: %3d\n", MAXLINE);
        printf(">> Actual Length:  %3d\n", max);
        printf(">> Text: %s\n", longest);

    return 0;
}

int get_line(char line[], int max_line)
{
    int c, i = 0;

    // Read line until EOF character or newline character are recieved
    while (((c = getchar()) != EOF))
    { 
        if (i < (max_line - 1))
            line[i] = c;
        // Increase line length counter
        i++;
        // Break loop if newline character is read
        if (c == '\n')
            break;
    }

    // Determine location of '\0' character according to line length
    if (i < max_line - 1)
        line[i] = '\0';
    else
        line[max_line-1] = '\0';


    return i;
}

void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
        i++;
}
