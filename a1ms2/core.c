/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
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

#include "core.h"


void clearInputBuffer(void)
{
    
    while (getchar() != '\n')
    {
        ; 
    }
}

void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


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


char inputCharOption(const char checkList[])
{
    int quit = 1, i;
    char input, output;
    do
    {
        scanf("%c", &input);
        for (i = 0; i < 6; i++)
        {
            if (input == checkList[i])
            {
                output = input;
                quit = 0;
                clearInputBuffer();
            }
        }
        if (quit == 1)
        {
            printf("ERROR: Character must be one of [%c%c%c%c%c%c]: ", checkList[0], checkList[1], checkList[2], checkList[3], checkList[4], checkList[5]);
            clearInputBuffer();
        }
    } while (quit);
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
        for (i = 0; string[i] != '\0'; i++)
        {
            if (string[i] != '\0')
            {
                length++;
            }
        }
        if (length >= min && length <= max)
        {
            for (i = 0; i < length; i++)
            {
                stringPtr[i] = string[i];
            }
            end = 0;
        }
        else
        {
            if (min == max)
            {
                printf("ERROR: String length must be exactly %d chars: ", max);
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
        for (i = 0; phoneNum[i] != '\0' && quit; i++)
        {
            if (phoneNum[i] != '\0')
            {
                length++;
            }
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