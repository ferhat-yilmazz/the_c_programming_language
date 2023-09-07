// Author: Ferhat Yilmaz <ferhatyilmaz.me@pm.me>
// 
// Compiler: Apple clang version 14.0.3 
//
// Exercise 1-5
// ------------
// Modify the temperature conversion program (which converts from Celcius to
// Fahrenheit) to print the table in reverse order, that is, from 300 degrees
// to 0.

#include <stdio.h>

int main(void)
{
    // Print header of the temperature conversion table
    printf("|----------------------|\n");
    printf("|Temperature Conversion|\n");
    printf("|----------------------|\n");
    printf("|Celcius  |  Fahrenheit|\n");
    printf("|-------  |  ----------|\n");

    // Since the subject of the exercise is the "for loops", then the solution
    // will be by using the "for loop". Following method can be seen scary.
    // However, it is intended to show that the "for loop" executes three
    // expressions and they can be any expression. At below, third expression
    // of the "for loop" is used for following tasks:
    //  * Calculate Fahrenheit value for related Celcius value
    //  * Print out Celcius and Fahrenheit value
    //  * Decrement Celcius value
    // So, the "for loop" is a powerful statement of the C Language  
    for (int celcius = 300; celcius >= 0;\
        printf("|%7d  |  %10.2f|\n",    celcius,\
                                        (celcius * (9.0/5.0)) + 32),\
                                        celcius-=20); 

    // Insert horizontal line to bottom of the table
    printf("|----------------------|\n");
    
    return 0;
}
