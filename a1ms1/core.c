
/*/////////////////////////////////////////////////////////////////////////
						Assignment 1 - Milestone 1
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
	while (getchar() != '\n') {
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
	int value;
	char newline;
	do
	{
		scanf("%d%c", &value, &newline);
		if (newline != '\n')
		{
			clearInputBuffer();
			printf("Error! Input a whole number: ");
		}
	} while (newline != '\n');
	return value;
}

int inputIntPositive()
{
	int input;
	do
	{
		input = inputInt();
		
		if (input < 1)
		{
			printf("ERROR! Value must be > 0: ");
		}
	} while (input < 1);
	return input;
}

int inputIntRange(int floor, int ceiling) {
	int temp, valid = 0;
	do {
		valid = 1;
		temp = inputInt();
		if (temp < floor || temp > ceiling)
		{
			printf("ERROR! Value must be between -3 and 11 inclusive: ");
			valid = 0;
		}
	} while (!valid);
	return temp;
}

char inputCharOption(const char* validChars) {
	char c;
	int found = 0, i;
	do {
		scanf(" %c", &c);
		for (i = 0; !found && validChars[i] != '\0'; i++)
		{
			if (c == validChars[i])
			{
				found = 1;
			}
		}
		if (!found)
		{
			printf("ERROR: Character must be one of [%s]: ", validChars);
		}
		clearInputBuffer();
	} while (!found);
	return c;
}
void inputCString(char* myString, int floor, int ceiling)
{
	char string[50];
	int valid = 0, i, length;
	do {
		scanf("%49[^\n]", string);
		for (i = 0; string[i] != '\0'; i++);
		if ((floor == ceiling) && (floor != i)) {
			printf("ERROR: String length must be exactly %d chars: ", floor);
		}
		else if (i > ceiling) {
			printf("ERROR: String length must be no more than %d chars: ", ceiling);
		}
		else if (i < floor) {
			printf("ERROR: String length must be between %d and %d chars: ", floor, ceiling);
		}
		else {
			valid = 1;
		}
		clearInputBuffer();
	} while (!valid);
	length = i;
	for (i = 0; i <= length; i++) {
		myString[i] = string[i];
	}
}

void displayFormattedPhone(const char* phoneNumber) {
	int size = 0, nonDigit = 0;
	if (phoneNumber == NULL) {
		printf("(___)___-____");
	}
	else {
		for (size = 0; !nonDigit && phoneNumber[size] != '\0'; size++) {
			if (phoneNumber[size] < '0' || phoneNumber[size] > '9') {
				nonDigit = 1;
			}
		}
		if (nonDigit || size != 10) {
			printf("(___)___-____");
		}
		else {
			printf("(%c%c%c)%c%c%c-%c%c%c%c",
				phoneNumber[0], phoneNumber[1],
				phoneNumber[2], phoneNumber[3],
				phoneNumber[4], phoneNumber[5],
				phoneNumber[6], phoneNumber[7],
				phoneNumber[8], phoneNumber[9]);

		}
	}
}
