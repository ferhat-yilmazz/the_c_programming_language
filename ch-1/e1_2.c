// Author: Ferhat Yilmaz
// 
// Compiler: Apple clang version 14.0.3 
//
// Exercise 1-2
// ------------
// Experiment to find out what happens when <printf>'s argument string contains
// '\c', where 'c' is some character not listed above.

#include <stdio.h>

int main(void)
{
    // Insert '\c' escape sequence to he argument of the <printf> function
    printf("\chello, world\n");

    return 0;
}
