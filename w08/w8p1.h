/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  : Chetan Arora
Student ID#: 100976240
Email      : carora18@myseneca.ca
Section    : ZRA

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#pragma once
#define MAXNOOFPRODUCT 3
#define GRAMS 64



typedef struct {
    int sku;
    double price;
    int calories;
    double weight;
} CatFoodInfo;


int getIntPositive(int* int_ptr);

double getDoublePositive(double* double_ptr);

void openingMessage(const int no_of_products);

CatFoodInfo getCatFoodInfo(const int seq_number);

void displayCatFoodHeader(void);

void displayCatFoodData(int sku, double* price, int calories, double* weight);

void start();