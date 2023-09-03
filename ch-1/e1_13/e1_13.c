// Author: Ferhat Yilmaz
// 
// Compiler: Apple clang version 14.0.3 
//
// Exercise 1-13
// ------------
// Write a program to print a histogram of the lengths of words in its input.
// It is easy to draw the histogram with the bars horizontal; a vertical
// orientation is more challenging. 
//
// Note: Both of horizontal histogram and vertical histograms
// will be implemented.

#include <stdio.h>
#include <string.h>

#define WHITESPACE_CHARS " \t\n\r\f\b\v"    // List of whitespace characters
#define MAX_LENGTH 31   // Expected maximum length of a word is 30
#define msg_info    ">> Info: EOF signal can be inserted by"\
                    "using <CRTL+D>\n   in the Unix-like systems.\n\n\n"\
                    ">> Please type a text and send EOF signal to end.\n\n"
#define msg_warning "\n\n"\
                    ">> Warning: There is detected a word exceeds maximum\n"\
                    "   length limit <%d>. It will be excluded.\n\n"

int main(void)
{
    int word_histogram[MAX_LENGTH];
    int ch, prev_ch = 0, i, j, ch_counter = 0;
    int idx_of_lengthiest_word = 0, idx_of_most_frequent_word = 0;

    // Assign zero for all elements of <word_histogram>
    memset(word_histogram, 0, sizeof(word_histogram));
    
    printf(msg_info);

    while ((ch = getchar()) != EOF)
    {
        // Detect words and whitespace characters
        if (strchr(WHITESPACE_CHARS, ch) != NULL &&\
            strchr(WHITESPACE_CHARS, prev_ch) == NULL)
        {
            if ((ch_counter > 0) && (ch_counter < MAX_LENGTH))
                word_histogram[ch_counter]++;
            else
                printf(msg_warning, MAX_LENGTH-1);
            
            // Reset character counter
            ch_counter = 0;
        }
        
        if (strchr(WHITESPACE_CHARS, ch) == NULL)
            ch_counter++;

        prev_ch = ch;
    }

    // Determine most frequent word
    for (i = 0; i < MAX_LENGTH; i++)
        if (word_histogram[i] > word_histogram[idx_of_most_frequent_word])
            idx_of_most_frequent_word = i;

    // Determine length of lengthiest word
    for (i = MAX_LENGTH-1; i >= 0; i--)
        if (word_histogram[i] > 0)
        {
            idx_of_lengthiest_word = i;
            break;
        }

    // #### HISTOGRAMS ####
    // Print horizontal orientation histogram graph
    // y-axis
    printf("\n\n\n                    < Horizontal Orientation Histogram >\n");
    printf("     Word\n  < Length > \n");
    printf("       ^                \n");
    printf("       |                \n");
    for (i = idx_of_lengthiest_word; i > 0; i--)
    {
        printf("   %2d  |  ", i);
        for (j = word_histogram[i]; j > 0; j--)
            printf("##   ");

        printf("\n");
    }
    // x-axis
    printf("    ---| ");
    for (i = 1; i <= word_histogram[idx_of_most_frequent_word]; i++)
        printf("---- ");
    printf("--->  < Frequency >\n");
    printf("   %2d  |  ", 0);
    for (i = 1; i <= word_histogram[idx_of_most_frequent_word]; i++)
        printf("%2d   ", i);

    // Print vertical orientation histogram graph
    // y-axis
    printf("\n\n\n\n                    < Vertical Orientation Histogram >\n");
    printf(" < Frequency > \n");
    printf("       ^                \n");
    printf("       |                \n");
    for (i = word_histogram[idx_of_most_frequent_word]; i > 0; i--)
    {
        printf("   %2d  |  ", i);
        for (j = 1; j <= idx_of_lengthiest_word; j++)
        {
            if (word_histogram[j] >= i)
                printf("##   ");
            else
                printf("     ");
        }
        printf("\n");
    }
    // x-axis
    printf("    ---| ");
    for (i = 1; i <= idx_of_lengthiest_word; i++)
        printf("---- ");
    printf("--->   Word  \n");
    printf("   %2d  |  ", 0);
    for (i = 1; i <= idx_of_lengthiest_word; i++)
        printf("%2d   ", i);
    printf("    < Count >");
    // #### END ####

    printf("\n\n\n>> Bye...\n");

    return 0;
}
