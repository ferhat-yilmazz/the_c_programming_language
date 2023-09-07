// Author: Ferhat Yilmaz <ferhatyilmaz.me@pm.me>
// 
// Compiler: Apple clang version 14.0.3 
//
// Exercise 1-14
// -------------
// Write a program to print a histogram of the frequencies of different
// characters in its input
//
// Note: Only ASCII characters are supported.

#include <stdio.h>
#include <string.h>

#define MSG_INFO    ">> Info: EOF signal can be inserted by"\
                    "using <CRTL+D>\n   in the Unix-like systems.\n\n\n"\
                    ">> Please type a text and send EOF signal to end.\n"\
                    "   (Only ASCII characters are supported)\n\n"
#define ASCII_LIMIT 128

int main(void)
{
    int char_histogram[ASCII_LIMIT];
    int ch;
    int idx_most_freq_char = 0, i, j;

    printf(MSG_INFO);

    // Assign zero to all array elements
    memset(char_histogram, 0, sizeof(char_histogram));

    // Count characters by one by
    while ((ch = getchar()) != EOF)
        // Check for read character in limit of the extended ASCII set
        if (ch < ASCII_LIMIT)
            char_histogram[ch]++;

    // Determine most frequent char index
    for (i = 1; i < ASCII_LIMIT; i++)
        if (char_histogram[i] > char_histogram[idx_most_freq_char])
            idx_most_freq_char = i;

    // Draw horizontal histogram graph
    // y-axis
    printf("\n\n\n                    < Horizontal Orientation Histogram >\n");
    printf("    < Chars >\n");
    printf("        ^               \n");
    printf("        |               \n");
    for (i = ASCII_LIMIT-1; i >= 0; i--)
    {
        if (char_histogram[i] > 0)
        {
            switch (i)
            {
            case '\n':
                printf("   '\\n' |  ");
                break;
            case '\t':
                printf("   '\\t' |  ");
                break;
            case '\v':
                printf("   '\\v' |  ");
                break;
            case '\r':
                printf("   '\\r' |  ");
                break;
            case '\f':
                printf("   '\\f' |  ");
                break;
            default:
                printf("    '%c' |  ", i);
            }

            for (j = char_histogram[i]; j > 0; j--)
                printf("##   ");

            printf("\n");
        }
    }

    // x-axis
    printf("    ----| ");
    for (i = 1; i <= char_histogram[idx_most_freq_char]; i++)
        printf("---- ");
    printf("--->  < Frequency >\n");
    printf("     %2c |  ", '0');
    for (i = 1; i <= char_histogram[idx_most_freq_char]; i++)
        printf("%2d   ", i);

    // Bye
    printf("\n\n\n>> Bye...\n");

    return 0;
}
