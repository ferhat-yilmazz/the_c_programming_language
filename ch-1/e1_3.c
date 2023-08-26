// Author: Ferhat Yilmaz
// 
// Compiler: Apple clang version 14.0.3 
//
// Exercise 1-3
// ------------
// Modify the temperature conversion program (which converts Fahrenheit to
// Celcius) to print a heading above the table.
// (Fahrenheit value interval is 0..300 by step size 20)

#include <stdio.h>

int main(void)
{
    float fahrenheit, celcius;

    // Print header of the temperature conversion table
    printf("|----------------------|\n");
    printf("|Temperature Conversion|\n");
    printf("|----------------------|\n");
    printf("|Fahrenheit  |  Celcius|\n");
    printf("|----------  |  -------|\n");

    for (fahrenheit = 0; fahrenheit <= 300; fahrenheit += 20)
    {
        // Calculate Celcius value according to given Fahrenheit value
        celcius = (5.0/9.0) * (fahrenheit-32.0);
        
        // Print values in format to fit the header of table
        printf("|%10.2f  |  %7.2f|\n", fahrenheit, celcius);
    }

    // Print bottom line of the table
    printf("|----------------------|\n");

    return 0;
}
