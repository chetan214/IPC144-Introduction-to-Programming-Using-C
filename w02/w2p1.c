/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
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

int main()
{
    double smallShirtPrice, mediumShirtPrice, largeShirtPrice, Sub_total, Total;
    int noOfPattyShirts, tax;
    const double TAX = 0.13;
    const char patSize ='S';

    printf("Set Shirt Prices\n");
    printf("================\n");

    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &smallShirtPrice);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &mediumShirtPrice);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &largeShirtPrice);
    printf("\n");
    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", smallShirtPrice);
    printf("MEDIUM : $%.2lf\n", mediumShirtPrice);
    printf("LARGE  : $%.2lf\n", largeShirtPrice);
    printf("\n");
    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &noOfPattyShirts);
    printf("\n");
    printf("Patty's shopping cart...\n");

    printf("Contains : %d shirts\n", noOfPattyShirts);

    Sub_total = noOfPattyShirts * (smallShirtPrice*100);
    
    printf("Sub-total: $%.4lf\n",(double)Sub_total/100);
    tax = (Sub_total * TAX+0.5);
    printf("Taxes    : $%8.4lf\n",(double)tax/100);
    Total = Sub_total + tax;
    printf("Total    : $%.4lf\n",(double)Total/100);
    return 0;
}