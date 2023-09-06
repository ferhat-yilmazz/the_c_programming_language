// Author: Ferhat Yilmaz <ferhatyilmaz.me@pm.me>
// 
// Compiler: Apple clang version 14.0.3 
//
// Exercise 1-15
// -------------
// Rewrite temperature conversion program of Section 1.2 to use a function
// for conversion.
//
// (Write program that converts given Fahrenheit values to Celcius values.
// Value list is pre-defined.)

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

// Declare converter function prototype
int fahr_to_celc(int fahrenheit_value);

int main(void)
{
    int fahr;

    // Print header of the temperature conversion table
    printf("\n");
    printf("|----------------------|\n");
    printf("|Temperature Conversion|\n");
    printf("|----------------------|\n");
    printf("|Fahrenheit  |  Celcius|\n");
    printf("|----------  |  -------|\n");

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        // Call declared funciton <fahr_to_celc()>
        printf("|%7d     |  %5d  |\n", fahr, fahr_to_celc(fahr));
    
    // Print bottom line of the table
    printf("|----------------------|\n\n");

    return 0;
}

// Define the converter function
int fahr_to_celc(int fahrenheit_value)
{
    int celcius_value;
    // Calculate Celcius value
    celcius_value = (5.0/9.0) * (fahrenheit_value - 32);

    return celcius_value;
}
