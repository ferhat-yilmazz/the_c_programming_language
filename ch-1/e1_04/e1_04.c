// Author: Ferhat Yilmaz <ferhatyilmaz.me@pm.me>
// 
// Compiler: Apple clang version 14.0.3 
//
// Exercise 1-4
// ------------
// Write a program to print the corresponding Celcius to Fahrenheit table.
// (Celcius value range is 0..300 by step size 20)

#include <stdio.h>

int main(void)
{
    float fahrenheit, celcius;

    // Print header of the temperature conversion table
    printf("|----------------------|\n");
    printf("|Temperature Conversion|\n");
    printf("|----------------------|\n");
    printf("|Celcius  |  Fahrenheit|\n");
    printf("|-------  |  ----------|\n");

    for (celcius = 0; celcius <= 300; celcius += 20)
    {
        // Calculate Fahrenheit value according to given Celcius value
        fahrenheit = (celcius * (9.0/5.0)) + 32;
        
        // Print values in format to fit the header of the table
        printf("|%7.2f  |  %10.2f|\n", celcius, fahrenheit);
    }

    // Insert horizontal line to bottom of the table
    printf("|----------------------|\n");

    return 0;
}
