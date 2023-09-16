// Author: Ferhat Yilmaz <ferhatyilmaz.me@pm.me>
//
// Compiler: Apple clang version 14.0.3
//
// Exercise 1-22
// -------------
// Write a program to "fold" long input lines into two or more shorter lines
// after the last non-blank character that occurs before the n-th column of
// input. Make sure your program does something intelligent with very long
// lines, and if there are no blanks or tabs before the specified column.
//
// Developer Notes
// ---------------
// In addittion to the folding operation, this program is also truncating the
// givem line for leading/trailing blanks.

#include <stdio.h>

#define MSG_INFO    ">> Info: EOF signal can be inserted by"\
                    "using <CTRL+D>\n   in the Unix-like systems.\n" \
                    "   Intended line length is %d\n\n"\
                    ">> Please send EOF signal to terminate the program.\n\n"
#define LINE_BUFFER_SIZE 2000
#define INTENDED_LINE_LENGTH 80

void fold_line(int * line, int line_length, int intended_length);
int truncate_line(int * line, int line_length);

int main(void)
{
    int ch, line_length = 0;
    int line[LINE_BUFFER_SIZE];

    // Info
    printf(MSG_INFO, INTENDED_LINE_LENGTH);

    while ((ch = getchar()) != EOF)
        if ((line_length == (LINE_BUFFER_SIZE-1)) || ch == '\n')
        {
            // Add null pointer end of the line buffer
            line[line_length] = '\0';
            // Call truncate function
            // Purpose of the function is to delete leading and trailing blanks
            line_length = truncate_line(line, line_length);
            // Call fold function
            fold_line(line, line_length, INTENDED_LINE_LENGTH);
            // Reset <line_length> value
            line_length = 0;
        }
        else
        {
            line[line_length] = ch;
            line_length++;
        }

    // Bye
    printf("\n\n>> Bye...\n");

    return 0;
}

// Definition of <fold_line()> function
void fold_line(int * line, int line_length, int intended_length)
{

    int lower = 0, upper;
    int ch, ch_prev = 0;
    int flag = 1, i;

    do
    {
        // Determine value of <upper>
        upper = ((lower + intended_length) < line_length) ?\
        (lower + intended_length) : line_length;

        for (i = upper - 1; i >= lower; i--) {
            ch = line[i];
            // Check condition to:
            // Find first a non-blank character before a blank character
            // OR detect upper limit is equal to line length. So all line
            // must be printed in that case
            if (((ch != ' ' && ch != '\t') && \
            (ch_prev == ' ' || ch_prev == '\t')) ||\
            (upper == line_length)) {
                while (lower <= i) {
                    putchar(line[lower]);
                    lower++;
                }
                flag = 0;
            }
            ch_prev = ch;
        }
        // Consider case of there is not a blank in the string snippet.
        // Then, the folding point should be a non-blank character
        if (flag)
        {
            while (lower < (upper - 1))
            {
                putchar(line[lower]);
                lower++;
            }
            // Insert '-' in case of folding from a non-blank character
            if (upper > 1)
                putchar('-');
        }
        // Reset flag value
        flag = 1;
        // Newline
        putchar('\n');

        // Determine new <lower> value
        while (((line[lower] == ' ') || (line[lower] == '\t')) &&\
         lower <= line_length)
            lower++;

    } while (upper != line_length);
}

// Definition of <truncate_line()> function
// Return: <int> updated line length
int truncate_line(int * line, int line_length)
{
    int i = 0, j = 0;

    // Delete leading blanks
    while ((line[j] == ' ' || line[j] == '\t') && (j < line_length))
        j++;

    if (j > 0)
        while (j <= line_length)
        {
            line[i] = line[j];
            i++;
            j++;
        }
    else
        i = line_length;

    // Delete trailing blanks
    // Move <i> index before of the '\0'
    i--;
    while ((line[i] == ' ' || line[i] == '\t') && (i >= 0))
        i--;

    i++;
    line[i] = '\0';

    return i;
}
