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
#pragma once
#define MAXNOOFPRODUCT 3
#define lbsToKg 2.20462
#define GRAMS 64

typedef struct {
    int sku;
    double price;
    int calories;
    double weight;
} CatFoodInfo;

typedef struct
{
    int sku2;
    double price2;
    int calories2;
    double weightLbs;
    double weightKg;
    int weightGram;
    double TotalServing;
    double costPerServing;
    double costCalPerServing;
} ReportData;

int getIntPositive(int* int_ptr);

double getDoublePositive(double* double_ptr);

void openingMessage(const int no_of_products);

CatFoodInfo getCatFoodInfo(const int seq_number);

void displayCatFoodHeader(void);

void displayCatFoodData(int sku, double* price, int calories, double* weight);

double convertLbsKg(double* pnd, double* kg);

int convertLbsG(double* pnd, int* Gram);

void convertLbs(const double*, double* e, int* f);

double calculateServings(const int, const int, double* g);

double calculateCostPerServing(double Price, double Total_Serving, double* Cost_Per_Serving);

double calculateCostPerCal(double price, double cal, double Total_serving, double* cost_per_cal);

ReportData calculateReportData(CatFoodInfo prod);

void displayReportHeader(void);

void displayReportData(ReportData data, int j);

void displayFinalAnalysis(int SKU, double price);

void start();