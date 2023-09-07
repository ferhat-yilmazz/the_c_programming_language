// Author: Ferhat Yilmaz <ferhatyilmaz.me@pm.me>
// 
// Compiler: Apple clang version 14.0.3 
//
// Exercise 1-17
// -------------
// Write a program to print all input lines that are longer than 80 character.

#include <stdio.h>

#define MSG_INFO    ">> Info: EOF signal can be inserted by"\
                    "using <CRTL+D>\n   in the Unix-like systems.\n\n"\
                    ">> Please type a text and send EOF signal to end.\n"\
                    "   Input text must be limited with  %d characters.\n\n"
#define MIN_LINE_LENGTH 80
#define BUFFER_SIZE 10000

// Decleration of the function to print filtered lines
void print_long_lines(int * text, int min_length);

int main(void)
{
    int ch, ch_counter = 0;
    int buffer[BUFFER_SIZE];

    printf(MSG_INFO, BUFFER_SIZE);

    while (((ch = getchar()) != EOF) && (ch_counter < (BUFFER_SIZE-2)))
    {
        // Save input text to buffer
        buffer[ch_counter] = ch;
        // Increase counter for each character
        ch_counter++;

        // Display warning in case of buffer capacity is full
        if (ch_counter == (BUFFER_SIZE-2))
        {
            printf("\n\n>> WARNING: Buffer capacity is full!\n\n");
        }
    }

    // Add '\n' and \0' characters to be sure the string completed
    buffer[ch_counter] = '\n';
    buffer[ch_counter + 1] = '\0';

    // Call function to filter input text and print all lines which are longer
    // than the MIN_LINE_LENGTH
    print_long_lines(buffer, MIN_LINE_LENGTH);

    // Bye
    printf("\n\n>> Bye...\n");

    return 0;
}

// Definition of the function <print_long_lines()>
void print_long_lines(int * text, int min_length)
{
    int head = 0, tail = 0, ch, i;

    printf("\n\n>>\n");

    while ((ch = text[tail]) != '\0')
    {
        // Increase tail for each new character
        tail++;

        if (ch == '\n')
        {
            // For each new line take difference between head and tail
            // If the difference bigger that min_length than print the line
            // Update head position
            if ((tail - head) > min_length)
                for (i = head; i < tail; i++)
                    putchar(text[i]);

            head = tail;
        }
    }
}
