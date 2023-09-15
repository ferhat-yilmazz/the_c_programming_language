// Author: Ferhat Yilmaz <ferhatyilmaz.me@pm.me>
//
// Compiler: Apple clang version 14.0.3
//
// Exercise 1-21
// -------------
// Write a program "entab" that replaces strings of blanks by the minimum number
// tabs and blanks to achieve the same spacing. Used the same tab stops as for
// "detap." When either a tab or a single blank would suffice to reach a tab
// stop, which should be given preference?
//
// Developer Note
// --------------
// Terminal tabsize must be configured with defined symbolic variable.
// In addition, tab character is preffered in case of needs single blank.

#include <stdio.h>

#define MSG_INFO    ">> Info: EOF signal can be inserted by"\
                    "using <CTRL+D>\n   in the Unix-like systems.\n"\
                    "   Tab stop size of the terminal configured as %d.\n\n"\
                    ">> Please send EOF signal to terminate the program.\n\n"
#define TAB_STOP 8 // Terminal tab stop must be defined here

int main(void)
{
    int ch;
    int pos = 0, space_count = 0, tab_stop_blanks;

    printf(MSG_INFO, TAB_STOP);

    while ((ch = getchar()) != EOF)
        if (ch == ' ')
        {
            space_count++;
        }
        else
        {
            while (space_count > 0)
            {
                // Find tab stop blanks size  according to current position
                tab_stop_blanks = TAB_STOP - (pos % TAB_STOP);

                // Compare current tab stop blank size and inserted space count
                if (space_count >= tab_stop_blanks)
                {
                    putchar('\t');
                    space_count -= tab_stop_blanks;
                    pos = 0;
                }
                else
                {
                    putchar(' ');
                    pos++;
                    space_count--;
                }
            }

            putchar(ch);
            // For each '\t' character reset position value
            if (ch == '\t')
                pos = 0;
            else
                pos++;
        }

    // Bye
    printf("\n\n>> Bye...\n");

    return 0;
}
