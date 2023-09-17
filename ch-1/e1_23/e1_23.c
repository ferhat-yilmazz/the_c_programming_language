// Author: Ferhat Yilmaz <ferhatyilmaz.me@pm.me>
//
// Compiler: Apple clang version 14.0.3
//
// Exercise 1-23
// -------------
// Write a program to remove all comments from a C program. Don't forget to
// handle quoted strings and character constants properly. C comments do not
// nest.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MSG_INFO ">> INFO\n\nEOF signal can be inserted by"\
                    "using <CTRL+D> on the Unix-like systems.\n" \
                    "Text buffer size is %d characters.\n"\
                    "Please send EOF signal to get the output.\n\n>> INPUT\n\n"
#define BUFFER_WARNING  "\n\n>> WARNING: Buffer capacity is full!"
#define BUFFER_SIZE 10000

void remove_comments(char * text, char * clear_text, int text_length);

int main(void)
{
    int length = 0;
    char buffer[BUFFER_SIZE];
    char clear_text[BUFFER_SIZE];
    char ch;

    // Info
    printf(MSG_INFO, BUFFER_SIZE);

    // Save input text to the buffer
    while ((ch = getchar()) != EOF)
        if (length < (BUFFER_SIZE-1))
        {
            buffer[length] = ch;
            length++;
        }

    // Display warning if the buffer is full
    // and be sure NULL character is inserted
    if ((buffer[length] != EOF) && length == (BUFFER_SIZE-1))
        printf(BUFFER_WARNING);
    buffer[length] = '\0';

    // Call <remove_comments()> function to remove comments.
    // It will generate comment-free text
    remove_comments(buffer, clear_text, length);

    // Print comment-free text
    printf("\n\n>> OUTPUT\n%s", clear_text);

    // Bye
    printf("\n\n>> BYE...\n");

    return 0;
}

// Definition of the <remove_comments()> function
void remove_comments(char * text, char * clear_text, int text_length)
{
    bool multiline_comment_active = false, singleline_comment_active = false;
    bool double_quote_active = false, single_quote_active = false;
    int i = 0, j = 0;

    while (i < (text_length-1))
    {   
        // Multi-line comment detection
        if ((!singleline_comment_active && !double_quote_active) &&\
            (text[i] == '/' && text[i+1] == '*'))
            multiline_comment_active = true;
        // Single-line comment detection
        else if ((!multiline_comment_active && !double_quote_active)&&\
            (text[i] == '/' && text[i+1] == '/'))
            singleline_comment_active = true;
        // Double quote detection
        else if ((!multiline_comment_active && !singleline_comment_active &&\
            !single_quote_active) && (text[i] == '"'))
            double_quote_active = true;
        // Single quote detection
        else if ((!multiline_comment_active && !singleline_comment_active &&\
            !double_quote_active) && (text[i] == '\''))
            single_quote_active = true;

        // Assign <text> to <clear_text> if comments are deactive
        if (!multiline_comment_active && !singleline_comment_active)
        {
            clear_text[j] = text[i];
            j++;
        }

        // Multi-line comment termination
        if (multiline_comment_active && (text[i-1] == '*' && text[i] == '/'))
            multiline_comment_active = false;
        // Single-line comment termination
        if (singleline_comment_active && (text[i] == '\n'))
            singleline_comment_active = false;
        // Double quote termination
        if (double_quote_active && (i > 0) &&\
            (text[i] == '"' && text[i-1] != '\\'))
            double_quote_active = false;
        // Single quote termination
        if (single_quote_active && (i>0) &&\
            (text[i] == '\'' && text[i-1] != '\\'))
            single_quote_active = false;

        i++;
    }

    // Be sure NULL character added for <clear_text>
    clear_text[j] = '\0';
}
