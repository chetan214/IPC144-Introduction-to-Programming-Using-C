/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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
#include <string.h>

#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//


//guarantee an integer value is entered and returned
int inputInt()
{
    int input, output;
    char newLine = 'x';
    while (newLine != '\n')
    {
        scanf("%d%c", &input, &newLine);
        if (newLine == '\n')
        {
            output = input;
        }
        else
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    }
    return output;
}

//validates the value entered is greater than 0
int inputIntPositive()
{
    int input = 0, output;
    char newLine = 'x';
    while (newLine != '\n' || input <= 0)
    {
        scanf("%d%c", &input, &newLine);
        if (newLine == '\n' && input > 0)
        {
            output = input;
        }
        else if (input <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
        else if (newLine != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    }
    return output;
}

//prompt for a value until a value is between the permitted range
int inputIntRange(const int min, const int max)
{
    int input, output;
    char newLine;
    do
    {
        scanf("%d%c", &input, &newLine);
        if (newLine != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        else if (input < min || input > max)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", min, max);
        }
        else
        {
            output = input;
        }
    } while (newLine != '\n' || input < min || input > max);
    return output;
}

//Guarantee a single character value is entered within the list of valid characters returned
char inputCharOption(const char checkList[])
{
    int quit = 1, i;
    char input[100] = "\0", output;
    do
    {
        scanf("%[^\n]", input);
        clearInputBuffer();
        for (i = 0; i < 6; i++)
        {
            if (input[0] == checkList[i])
            {
                output = input[0];
                quit = 0;
            }
        }
        if (quit == 1 || strlen(input) != 1)
        {
            printf("ERROR: Character must be one of [%s]: ", checkList);
        }
    } while (quit || strlen(input) != 1);
    return output;
}

void inputCString(char* stringPtr, const int min, const int max)
{
    int i, end = 1;
    while (end)
    {
        int length = 0;
        char string[100];
        scanf("%[^\n]", string);
        clearInputBuffer();
        length = strlen(string);
        if (length >= min && length <= max)
        {
            for (i = 0; i < max; i++)
            {
                stringPtr[i] = string[i];
            }
            end = 0;
        }
        else
        {
            if (min == max)
            {
                printf("Invalid %d-digit number! Number: ", max);
            }
            else
            {
                if (length > max)
                {
                    printf("ERROR: String length must be no more than %d chars: ", max);
                }
                else if (length < min)
                {
                    printf("ERROR: String length must be between %d and %d chars: ", min, max);
                }
            }
        }
    }
}

void displayFormattedPhone(const char* phoneNum)
{
    int i, length = 0, quit = 1;
    if (phoneNum != NULL)
    {
        length = strlen(phoneNum);
        for (i = 0; i < length && quit; i++)
        {
            if (phoneNum[i] > 57 || phoneNum[i] < 48)
            {
                quit = 0;
            }
        }
        if (quit == 0 || length != 10)
        {
            printf("(___)___-____");
        }
        else
        {
            printf("(");
            for (i = 0; i < 3; i++)
            {
                printf("%c", phoneNum[i]);
            }
            printf(")");
            for (i = 3; i < 6; i++)
            {
                printf("%c", phoneNum[i]);
            }
            printf("-");
            for (i = 6; i < 10; i++)
            {
                printf("%c", phoneNum[i]);
            }
        }
    }
    else
    {
        printf("(___)___-____");
    }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////