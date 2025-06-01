#pragma once
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

#ifndef CORE_H
#define CORE_H


void clearInputBuffer(void);

void suspend(void);


int inputInt();

int inputIntPositive();

int inputIntRange(const int, const int);

char inputCharOption(const char[]);

void inputCString(char*, const int, const int);

void displayFormattedPhone(const char*);

#endif 