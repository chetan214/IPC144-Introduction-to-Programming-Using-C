/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
    double smallShirtPrice, mediumShirtPrice, largeShirtPrice, subTotalOfPatShirt, totalPriceOfPatSize, onePatShirtPrice, oneSalShirtPrice, subTotalOfSalShirt, totalPriceOfSalSize, oneTomShirtPrice, subTotalOfTomShirt, totalPriceOfTomSize , subTotal, totalTax, grandTotal, averageCostOfShirtExcludingTax, averageCostOfShirtIncludingTax;
    double tonniesBalance, looniesBalance, quartersBalance, dimesBalance, nickelsBalance, penniesBalance;
    int noOfPatShirts, taxOfPatShirt, taxOfSalShirt, taxOfTomShirt, noOfSalShirts, noOfTomShirts, toonies, loonies, quarters, dimes, nickels, pennies;
    const double TAX = 0.13;
    const char patSize = 'S' , tomSize = 'L', salSize = 'M';

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
                    scanf("%d", &noOfPatShirts);
                    printf("\n");
    
                    printf("Tommy's shirt size is '%c'\n", tomSize);
                    printf("Number of shirts Tommy is buying: ");
                    scanf("%d", &noOfTomShirts);
                    printf("\n");

                    printf("Sally's shirt size is '%c'\n", salSize);
                    printf("Number of shirts Sally is buying: ");
                    scanf("%d", &noOfSalShirts);
                    printf("\n");
                    
    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
   
    // Patty's Shirt 
    onePatShirtPrice = smallShirtPrice;
    subTotalOfPatShirt = noOfPatShirts * (smallShirtPrice * 100);
    taxOfPatShirt = (subTotalOfPatShirt * TAX + 0.5);
    totalPriceOfPatSize = subTotalOfPatShirt + taxOfPatShirt;
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, onePatShirtPrice, noOfPatShirts, (double)subTotalOfPatShirt / 100, (double)taxOfPatShirt / 100, (double)totalPriceOfPatSize / 100);
    
    // Sally's Shirt 
    oneSalShirtPrice = mediumShirtPrice;
    subTotalOfSalShirt = noOfSalShirts * (mediumShirtPrice * 100);
    taxOfSalShirt = (subTotalOfSalShirt * TAX + 0.5);
    totalPriceOfSalSize = subTotalOfSalShirt + taxOfSalShirt;
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, oneSalShirtPrice, noOfSalShirts, (double)subTotalOfSalShirt / 100, (double)taxOfSalShirt / 100, (double)totalPriceOfSalSize / 100);
    
    // Tommy's Shirt
    oneTomShirtPrice = largeShirtPrice;
    subTotalOfTomShirt = noOfTomShirts * (largeShirtPrice * 100);
    taxOfTomShirt = (subTotalOfTomShirt * TAX + 0.5);
    totalPriceOfTomSize = subTotalOfTomShirt + taxOfTomShirt;
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, oneTomShirtPrice, noOfTomShirts, (double)subTotalOfTomShirt / 100, (double)taxOfTomShirt / 100, (double)totalPriceOfTomSize / 100);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    subTotal = subTotalOfPatShirt + subTotalOfSalShirt + subTotalOfTomShirt;
    totalTax = taxOfPatShirt + taxOfSalShirt + taxOfTomShirt;
    grandTotal = totalPriceOfPatSize + totalPriceOfSalSize + totalPriceOfTomSize;
    printf("%33.4lf %9.4lf %9.4lf\n\n", (double)subTotal/100, (double)totalTax/100, (double)grandTotal/100);
    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");
    
    //Sales Excluding Tax

    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", subTotal / 100);
    toonies = (int)(subTotal / 100) * 100 / 200;
    tonniesBalance = (int)((subTotal / 100) * 100) - (toonies * 200);
    printf("Toonies  %3d %9.4lf\n", toonies, (double)tonniesBalance / 100);
    loonies = (int)tonniesBalance / 100;
    looniesBalance = (int)tonniesBalance - (loonies * 100);
    printf("Loonies  %3d %9.4lf\n", loonies, (double)looniesBalance / 100);
    quarters = (int)looniesBalance / 25;
    quartersBalance = (int)looniesBalance - (quarters * 25);
    printf("Quarters %3d %9.4lf\n", quarters, (double)quartersBalance / 100);
    dimes = (int)quartersBalance / 10;
    dimesBalance = (int)quartersBalance - (dimes * 10);
    printf("Dimes    %3d %9.4lf\n", dimes, (double)dimesBalance / 100);
    nickels = (int)dimesBalance / 5;
    nickelsBalance = (int)dimesBalance - (nickels * 5);
    printf("Nickels  %3d %9.4lf\n",nickels, (double)nickelsBalance / 100);
    pennies = (int)nickelsBalance / 1;
    penniesBalance = (int)nickelsBalance - (pennies * 1);
    printf("Pennies  %3d %9.4lf\n", pennies, (double)penniesBalance / 100);
    printf("\n");
    //Average cost/shirt(Excluding Tax)
    averageCostOfShirtExcludingTax = subTotal/(noOfPatShirts+noOfSalShirts+noOfTomShirts);
    
    printf("Average cost/shirt: $%.4lf\n", (double)averageCostOfShirtExcludingTax/100);
    printf("\n");
    //Sales Including Tax
    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", grandTotal/100);
    toonies = (int)(grandTotal / 100) * 100 / 200;
    tonniesBalance = (int)((grandTotal / 100) * 100) - (toonies * 200);
    printf("Toonies  %3d %9.4lf\n", toonies, (double)tonniesBalance / 100);
    loonies = (int)tonniesBalance / 100;
    looniesBalance = (int)tonniesBalance - (loonies * 100);
    printf("Loonies  %3d %9.4lf\n", loonies, (double)looniesBalance / 100);
    quarters = (int)looniesBalance / 25;
    quartersBalance = (int)looniesBalance - (quarters * 25);
    printf("Quarters %3d %9.4lf\n", quarters, (double)quartersBalance / 100);
    dimes = (int)quartersBalance / 10;
    dimesBalance = (int)quartersBalance - (dimes * 10);
    printf("Dimes    %3d %9.4lf\n", dimes, (double)dimesBalance / 100);
    nickels = (int)dimesBalance / 5;
    nickelsBalance = (int)dimesBalance - (nickels * 5);
    printf("Nickels  %3d %9.4lf\n", nickels, (double)nickelsBalance / 100);
    pennies = (int)nickelsBalance/1;
    penniesBalance = (int)nickelsBalance - (pennies *1);
    printf("Pennies  %3d %9.4lf\n", pennies, (double)penniesBalance/100);
    printf("\n");
    //Average cost/shirt(Including Tax)
    averageCostOfShirtIncludingTax = grandTotal / (noOfPatShirts + noOfSalShirts + noOfTomShirts);

    printf("Average cost/shirt: $%.4lf\n", (double)averageCostOfShirtIncludingTax / 100);

    return 0;
}