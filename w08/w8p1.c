/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
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

#define TEST_NEG	-1
#define TEST_ZERO	0
#define TEST_INT	24
#define TEST_DBL	82.5

#include <stdio.h>

#include "w8p1.h"

int testIntFunction(void);
int testDoubleFunction(void);

int getIntPositive(int* x)
{
    int positiveValue;
    scanf("%d", &positiveValue);

    while (positiveValue <= 0)
    {
        printf("ERROR: Enter a positive value: ");
        scanf("%d", &positiveValue);
    }

    if (x != NULL)
        *x = positiveValue;
    return positiveValue;
}

double getDoublePositive(double* x)
{
    double positiveValue;
    scanf("%lf", &positiveValue);
    while (positiveValue <= 0)
    {
        printf("ERROR: Enter a positive value: ");
        scanf("%lf", &positiveValue);
    }
    if (x != NULL)
        *x = positiveValue;
    return positiveValue;
}

void openingMessage(const int numProducts)
{
    printf("Cat Food Cost Analysis\n");
    printf("======================\n");
    printf("\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", numProducts);
    printf("NOTE: A 'serving' is %dg\n", GRAMS);

}

CatFoodInfo getCatFoodInfo(const int seqenceNum)
{
    CatFoodInfo prod = { 0 };
    printf("\nCat Food Product #%d\n""--------------------\n", seqenceNum);
    printf("SKU           : ");
    getIntPositive(&prod.sku);
    printf("PRICE         : $");
    getDoublePositive(&prod.price);
    printf("WEIGHT (LBS)  : ");
    getDoublePositive(&prod.weight);
    printf("CALORIES/SERV.: ");
    getIntPositive(&prod.calories);
    return prod;
}

void displayCatFoodHeader(void)
{
    printf("\n");
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

void displayCatFoodData(int sku, double* price, int calories, double* weight)
{
    printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}

void start()
{
    CatFoodInfo prod[MAXNOOFPRODUCT] = { {0} };
    int i;
    openingMessage(MAXNOOFPRODUCT);
    for (i = 0; i < MAXNOOFPRODUCT; i++)
    {
        prod[i] = getCatFoodInfo(i + 1);
    }
    displayCatFoodHeader();
    for (i = 0; i < MAXNOOFPRODUCT; i++)
    {
        displayCatFoodData(prod[i].sku, &prod[i].price, prod[i].calories, &prod[i].weight);
    }
}