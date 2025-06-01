/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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
#include<stdio.h>
#include "w8p2.h"

int getIntPositive(int* x)
{
    int value;
    scanf("%d", &value);
    while (value <= 0)
    {
        printf("ERROR: Enter a positive value: ");
        scanf("%d", &value);
    }
    if (x != NULL)
        *x = value;
    return value;
}

double getDoublePositive(double* x)
{
    double value;
    scanf("%lf", &value);
    while (value <= 0)
    {
        printf("ERROR: Enter a positive value: ");
        scanf("%lf", &value);
    }
    if (x != NULL)
        *x = value;
    return value;
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

double convertLbsKg(double* pnd, double* kg)
{
    double o = *pnd / lbsToKg;
    if (kg != NULL)
    {
        *kg = o;
    }
    return o;
}

int convertLbsG(double* pnd, int* Gram)
{
    double t = *pnd;
    double ew = convertLbsKg(&t, &ew) * 1000;
    if (Gram != NULL)
    {
        *Gram = ew;
    }
    return ew;
}

void convertLbs(const double* pnd, double* kg, int* g)
{
    *kg = *pnd / lbsToKg;
    *g = *pnd / lbsToKg * 1000;
}

double calculateServings(int gram_serving, int weight_gram, double* Total_serving)
{
    *Total_serving = ((double)weight_gram / gram_serving);
    return *Total_serving;
}

double calculateCostPerServing(double Price, double Total_Serving, double* Cost_Per_Serving)
{
    *Cost_Per_Serving = Price / Total_Serving;
    return *Cost_Per_Serving;
}

double calculateCostPerCal(double price, double cal, double Total_serving, double* cost_per_cal)
{
    *cost_per_cal = (price / cal) / Total_serving;
    return *cost_per_cal;
}

ReportData calculateReportData(CatFoodInfo prod)
{
    ReportData report = { 0 };
    report.sku2 = prod.sku;
    report.price2 = prod.price;
    report.TotalServing = calculateServings(GRAMS, convertLbsG(&prod.weight, &report.weightGram), &report.TotalServing);
    report.costPerServing = calculateCostPerServing(prod.price, report.TotalServing, &report.costPerServing);
    report.weightLbs = prod.weight;
    report.costCalPerServing = calculateCostPerCal(prod.price, prod.calories, report.TotalServing, &report.costCalPerServing);
    report.calories2 = prod.calories;
    report.weightKg = convertLbsKg(&prod.weight, &report.weightKg);
    report.weightGram = convertLbsG(&prod.weight, &report.weightGram);
    return report;
}

void displayReportHeader(void)
{
    printf("\nAnalysis Report (Note: Serving = %dg)\n", GRAMS);
    printf("---------------\n");
    printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
    printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

void displayReportData(ReportData Data, int t)
{
    int i = 0;
    if (i == t)
    {
        printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf ***\n", Data.sku2, Data.price2, Data.weightLbs, Data.weightKg, Data.weightGram, Data.calories2, Data.TotalServing, Data.costPerServing, Data.costCalPerServing);
    }
    else
    {
        printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf\n", Data.sku2, Data.price2, Data.weightLbs, Data.weightKg, Data.weightGram, Data.calories2, Data.TotalServing, Data.costPerServing, Data.costCalPerServing);
    }
}

void diplayFinalAnalysis(int SKU, double price)
{
    printf("\nFinal Analysis");
    printf("\n--------------");
    printf("\nBased on the comparison data, the PURRR-fect economical option is:\nSKU:00%d Price: $%.2lf\n\nHappy shopping!\n", SKU, price);
}

void start()
{
    CatFoodInfo prod[MAXNOOFPRODUCT] = { {0} };
    int num_products = 3, i;
    openingMessage(num_products);
    for (i = 0; i < num_products; i++)
    {
        prod[i] = getCatFoodInfo(i + 1);
    }
    displayCatFoodHeader();
    for (i = 0; i < num_products; i++)
    {
        displayCatFoodData(prod[i].sku, &prod[i].price, prod[i].calories, &prod[i].weight);
    }
    ReportData report[MAXNOOFPRODUCT] = { { 0 } };
    for (i = 0; i < num_products; i++)
    {
        report[i] = calculateReportData(prod[i]);
    }
    displayReportHeader();
    int j, t;
    i = 0;
    for (i = 0; i < num_products; i++)
    {
        for (j = 0; j < num_products; j++)
        {
            if (report[i].costPerServing > report[j].costPerServing)
            {
                t = j;
            }
        }
        j = 0;
    }
    for (i = 0; i < num_products; i++)
    {
        if (i != 0)
        {
            displayReportData(report[i], t - i);
        }
        else
        {
            displayReportData(report[i], t);
        }
    }
    diplayFinalAnalysis(prod[t].sku, prod[t].price);
    return;
}