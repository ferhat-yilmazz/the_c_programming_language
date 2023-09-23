/*
 * Written by Ferhat Yilmaz, 2023.
 * <ferhatyilmaz.me@pm.me>
 *
 * Compiler: Apple clang version 15.0.0
 *
 * Exercise 1-24
 * -------------
 * Write a program to check a C program for rudimentary syntax errors like
 * unbalanced parentheses, brackets and braces. Don't forget about quotes,
 * both single and double, escape sequences, and comments. (This program is hard
 * if you do it in full generality.)
 *
 * Developer Notes
 * ---------------
 * In addition to detection of parentheses based syntax error, the program also
 * provides info about line number which an error occurs. It is possible to
 * hold parentheses list with dynamic memory allocation. However, the author of
 * the book did not touch dynamic memory allocation until this exercise. So,
 * predefined limited array is used.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MSG_INFO ">> INFO\nEOF signal can be inserted by"\
                    "using <CTRL+D> on the Unix-like systems.\n" \
                    "Text buffer size is %d characters.\n"\
                    "Please send EOF signal to get the output.\n\n>> INPUT\n"
#define BUFFER_WARNING  "\n\n>> WARNING: Buffer capacity is full!"
#define BUFFER_SIZE 10000

int remove_non_code(const char *text, char *clean_text, int text_length);

int check_syntax(const char *text, int text_length);

int main(void) {
    int length = 0, clean_code_length, result = 1;
    char buffer[BUFFER_SIZE], clean_code[BUFFER_SIZE];

    printf(MSG_INFO, BUFFER_SIZE);
    /* Copy input text to the buffer */
    while (((buffer[length] = (char) getchar()) != EOF) &&
           (length < (BUFFER_SIZE - 1))) {
        length++;
        if (length == (BUFFER_SIZE - 1))
            printf(BUFFER_WARNING);
    }

    /* Insert NULL character to end of the buffer */
    buffer[length] = '\0';

    clean_code_length = remove_non_code(buffer,
                                        clean_code,
                                        length);
    result = check_syntax(clean_code,clean_code_length);

    printf("\n>> %s!, BYE...\n", (result == 0) ? "SUCCESS" : "FAILURE");

    return 0;
}

/**
 * check_syntax - Check rudimentary syntax error of the given C code
 * @text: C script
 * @text_length: Character count of the C script
 *
 * Rudimentary syntax error includes unbalanced parentheses, brackets, and
 * braces. Comments, single/double quotes, and escape sequences should be
 * considered.
*/
int check_syntax(const char *text, int text_length) {
    char *parentheses_list, ch;
    int idx = 0, i = 0, newline_count = 1, result = 0;

    /* Allocate memory for $parentheses_list as many as $text_length */
    parentheses_list = (char *) malloc(sizeof(char) * text_length);
    if (parentheses_list == NULL)
        return 1;

    while ((ch = text[i]) != '\0') {
        if (strchr("{([", (int) ch) != NULL) {
            parentheses_list[idx++] = ch;
        }
            /* Check mismatching parentheses */
        else if (strchr("}])", (int) ch) != NULL) {
            if ((idx-- < 0) ||
                (ch == '}' && parentheses_list[idx] != '{') ||
                (ch == ']' && parentheses_list[idx] != '[') ||
                (ch == ')' && parentheses_list[idx] != '(')) {
                printf("\n\n>> ERROR:Line:%d, mismatching '%c' parentheses!\n",
                       newline_count, ch);
                result = 1;
                break;
            }
        } else if (ch == '\n') {
            newline_count++;
        }
        i++;
    }
    /* Check remaining parentheses */
    if ((idx > 0) && (result == 0)) {
        switch (parentheses_list[idx]) {
            case '{':
                printf("\n\n>> ERROR:Line:%d, expected '}'\n", newline_count);
                break;
            case '[':
                printf("\n\n>> ERROR:Line:%d, expected ']'\n", newline_count);
                break;
            case '(':
                printf("\n\n>> ERROR:Line:%d, expected ')'\n", newline_count);
                break;
            default:
                printf("\n\n>> ERROR: Unexpected '%c'\n",
                       parentheses_list[idx]);
        }
        result = 1;
    }

    free(parentheses_list);
    return result;
}

/**
 * remove_non_code - Remove comments from the given C script
 * @text: Original C script
 * @clear_text: Non-code-free C script
 * @text_length: Length of the @text
 *
 * Remove multiline comments, inline comments, double quotes, single quotes.
 * Keep newline characters to preserve line count of the original C script.
 * Returns length of the clean_text.
*/
int remove_non_code(const char *text, char *clean_text, int text_length) {
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
            continue;
        }
            /* Single quote detection */
        else if ((!multiline_comment_active && !inline_comment_active &&
                  !double_quote_active && !single_quote_active) &&
                 (text[i] == '\'')) {
            single_quote_active = true;
            continue;
        }
        /* Assign %text to %clean_text if comments are de-active */
        if ((!multiline_comment_active && !inline_comment_active &&
             !double_quote_active && !single_quote_active) ||
            text[i] == '\n') {
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

    return j;
}
