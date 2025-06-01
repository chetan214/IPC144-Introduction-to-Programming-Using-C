/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
Full Name  : Chetan Arora
Student ID#: 100976240
Email      : carora18@myseneca.ca
Section    : ZRA

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
    int numericValue, a = 0;
    char alphabet;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");

    do {
        printf("\n");
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");

        if (scanf(" %c%d", &alphabet, &numericValue) != 2)
        {
            printf("ERROR: Invalid numericValue format. Please enter valid numericValue.\n");
        }
        else {
        if (alphabet == 'D' || alphabet == 'W' || alphabet == 'F' || alphabet == 'Q') 
              {
                if (numericValue >= 3 && numericValue <= 20)
                {
                if (alphabet == 'D') {
                        printf("DO-WHILE: ");
                        a = 0;
                        do {
                            a++;
                            printf("%c", alphabet);
                        } while (a < numericValue);
                        printf("\n");
                    }
                    else if (alphabet == 'W') {
                        printf("WHILE   : ");
                        a = 0;
                        while (a < numericValue) {
                            a++;
                            printf("%c", alphabet);
                        }
                        printf("\n");
                    }
                    else if (alphabet == 'F') {
                        printf("FOR     : ");
                        for (a = 0; a < numericValue; a++) {
                            printf("%c", alphabet);
                        }
                        printf("\n");
                    }
                    else if (alphabet == 'Q' && numericValue == 0) {
                        printf("Quitting the program.\n");
                    }
                }
                else if (alphabet == 'Q' && numericValue != 0) {
                    printf("ERROR: To quit, the number of iterations should be 0!\n");
                }
                else if (numericValue < 3 || numericValue > 20) {
                    if (alphabet != 'Q') {
                        printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
                    }
                }
            }
            else {
                printf("ERROR: Invalid entered value(s)!\n");
            }
        }
    } while (!((alphabet == 'Q') && (numericValue == 0)));

    printf("\n");
    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");
    return 0;
}