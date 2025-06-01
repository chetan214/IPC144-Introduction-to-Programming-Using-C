#pragma once

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

int my_strlen(const char* s);

char* my_strcpy(char* strDest, const char* strSrc);

void clearInputBuffer(void);

void suspend(void);

int inputInt(void);

int inputIntPositive(void);

int inputIntRange(int lower_limit, int upper_limit);

char inputCharOption(const char* valid_characters);

void inputCString(char* inputString, int minLen, int maxLen);

void displayFormattedPhone(const char* phone_number);