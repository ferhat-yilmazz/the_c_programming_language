// Author: Ferhat Yilmaz <ferhatyilmaz.me@pm.me>
//
// Compiler: Apple clang version 14.0.3
//
// Exercise 1-18
// -------------
// Write a program to remove trailing blanks and tabs from each line of input,
// and to delete entirely blank lines.
//
// Note: This program not working line by line; instead, it is able to
// accept a text and remove trailing blanks of its lines. Empty lines
// are completely removed.

#include <stdio.h>
#include <string.h>

#define MSG_INFO    ">> Info: EOF signal can be inserted by"\
                    "using <CRTL+D>\n   in the Unix-like systems.\n\n"\
                    ">> Please type a text and send EOF signal to end.\n"\
                    "   Input text must be limited with  %d characters.\n\n"
#define BUFFER_SIZE 10000
#define TRAILING_BLANKS " \t\n"

void remove_trailing_blanks(    char * buffer,
                                char * clean_text,
                                int text_length,
                                char * trailing_blanks
);

int main(void)
{
    int ch, ch_counter = 0;
    char buffer[BUFFER_SIZE], clean_text[BUFFER_SIZE];

    printf(MSG_INFO, BUFFER_SIZE);

    // Read input text and save to the buffer
    while (((ch = getchar()) != EOF) && (ch_counter < (BUFFER_SIZE - 1)))
    {
        buffer[ch_counter] = ch;
        ch_counter++;

        if (ch == (BUFFER_SIZE - 1))
            printf("\n\n>> WARNING: Buffer capacity is full!\n\n");
    }

    // Add '\n' and \0' characters to be sure the string completed
    buffer[ch_counter] = '\0';

    // Call function to clear the input text
    remove_trailing_blanks(buffer, clean_text, ch_counter, TRAILING_BLANKS);

    // Print clean version of the text
    printf("\n\n>>\n%s", clean_text);

    // Bye
    printf("\n---------\n>> Bye...\n");

    return 0;
}

void remove_trailing_blanks(    char * buffer,
                                char * clean_text,
                                int text_length,
                                char * trailing_blanks
)
{
    int counter = text_length, slider;
    char ch, i = 0, j = 0;

    // Write -127 into removed trailing character locations
    while (counter >= 0)
    {
        if (buffer[counter] == '\n')
        {
            for (slider = counter - 1;\
                (strchr(trailing_blanks, buffer[slider]) != NULL) &&\
                slider >= 0; slider--)
                buffer[slider] = -127;
        }
        counter--;
    }

    // Check for first character is '\n'
    if (buffer[0] == '\n')
        buffer[0] = -127;

    // Make clean copy of the text, skip -127 valued characters 
    while (buffer[i] != '\0')
    {
        if (buffer[i] != -127) {
            clean_text[j] = buffer[i];
            j++;
        }
        i++;
    }

    // Insert '\0' to the end of the clean text
    clean_text[j] = '\0';
}
