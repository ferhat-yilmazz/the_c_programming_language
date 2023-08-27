// Author: Ferhat Yilmaz
// 
// Compiler: Apple clang version 14.0.3 
//
// Exercise 1-6
// ------------
// Verify that the expression `getchar() != EOF` is 0 or 1.

#include <stdio.h>

int main(void)
{
    int ch;

    const char *message = "With or without typing press <CR>, you can see that"
    "`getchar() != EOF` is equal to TRUE.\nYou can send EOF character by using"
    "<CTRL+D>, then `getchar() != EOF` is equal to FALSE.\n\n";

    printf("%s", message);

    // Read character from STDIN, assign to `ch` and
    // check for it is equal to EOF or not
    while ((ch = getchar()) != EOF)
        // If `ch` not equal to EOF, print info. To prevent print the infor for
        // each character in the line, only "\n" character is considered
        if (ch == '\n')
            printf("ch != EOF => TRUE\n");
    
    // If `ch` is equal to EOF, then print info
    printf("ch != EOF => FALSE\n");

    return 0;
}
