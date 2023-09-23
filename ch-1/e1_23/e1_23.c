/*
 * Written by Ferhat Yilmaz, 2023.
 * <ferhatyilmaz.me@pm.me>
 *
 * Compiler: Apple clang version 15.0.0
 *
 * Exercise 1-24
 * -------------
 * Write a program to remove all comments from a C program. Don't forget to
 * handle quoted strings and character constants properly. C comments do not
 * nest.
 */

#include <stdio.h>
#include <stdbool.h>

#define MSG_INFO ">> INFO\nEOF signal can be inserted by"\
                    "using <CTRL+D> on the Unix-like systems.\n" \
                    "Text buffer size is %d characters.\n"\
                    "Please send EOF signal to get the output.\n\n>> INPUT\n"
#define BUFFER_WARNING  "\n\n>> WARNING: Buffer capacity is full!"
#define BUFFER_SIZE 10000

void remove_comments(const char *text, char *clean_text, int text_length);

int main(void)
{
    int length = 0;
    char buffer[BUFFER_SIZE];
    char clear_text[BUFFER_SIZE];
    char ch;

    /* Info */
    printf(MSG_INFO, BUFFER_SIZE);
    /* Save input text to the buffer */
    while ((ch = (char)getchar()) != EOF)
        if (length < (BUFFER_SIZE-1))
        {
            buffer[length] = ch;
            length++;
        }
    /*
     * Display warning if the buffer is full
     * and be sure NULL character is inserted
     */
    if ((buffer[length] != EOF) && length == (BUFFER_SIZE-1))
        printf(BUFFER_WARNING);
    buffer[length] = '\0';

    /* Call remove_comments() function to remove comments */
    remove_comments(buffer, clear_text, length);
    /* Print comment-free text */
    printf("\n\n>> OUTPUT\n%s", clear_text);
    /* Bye */
    printf("\n>> BYE...\n");

    return 0;
}
/**
 * remove_comments - Remove comments of the given C source code
 * @text: Original C source code
 * @clean_text: Comment-free C source code
 * @text_length: Length of the text
 *
 * Multiline and inline comments in the given source code are removed and
 * clean source code assigned to clean_text. NULL character will be inserted
 * to end of the clean_text. Double and single quotes are also considered.
 * */
void remove_comments(const char *text, char *clean_text, int text_length) {
    bool multiline_comment_active = false, inline_comment_active = false;
    bool double_quote_active = false, single_quote_active = false;
    int i = 0, j = 0;

    for (i = 0; i < (text_length - 1); i++) {
        /* Multi-line comment detection */
        if ((!inline_comment_active && !double_quote_active &&
             !multiline_comment_active) &&
            (text[i] == '/' && text[i + 1] == '*')) {
            multiline_comment_active = true;
            continue;
        }
        /* Single-line comment detection */
        else if ((!multiline_comment_active && !double_quote_active &&
                  !inline_comment_active) &&
                 (text[i] == '/' && text[i + 1] == '/')) {
            inline_comment_active = true;
            continue;
        }
        /* Double quote detection */
        else if ((!multiline_comment_active && !inline_comment_active &&
                  !single_quote_active && !double_quote_active) &&
                 (text[i] == '"')) {
            double_quote_active = true;
        }
        /* Single quote detection */
        else if ((!multiline_comment_active && !inline_comment_active &&
                  !double_quote_active && !single_quote_active) &&
                 (text[i] == '\'')) {
            single_quote_active = true;
        }
        /* Assign %text to %clean_text if comments are de-active */
        if (!multiline_comment_active && !inline_comment_active) {
            clean_text[j] = text[i];
            j++;
        }
        /* Multi-line comment termination */
        if (multiline_comment_active && (text[i - 1] == '*' && text[i] == '/'))
            multiline_comment_active = false;
        /* Single-line comment termination */
        if (inline_comment_active && (text[i] == '\n'))
            inline_comment_active = false;
        /* Double quote termination */
        if (double_quote_active && (i > 0) &&
            (text[i] == '"' && text[i - 1] != '\\'))
            double_quote_active = false;
        /* Single quote termination */
        if (single_quote_active && (text[i] == '\'' && text[i + 1] != '\''))
            single_quote_active = false;
    }
    /* Be sure NULL character added end of the clean_text */
    clean_text[j] = '\0';
}
