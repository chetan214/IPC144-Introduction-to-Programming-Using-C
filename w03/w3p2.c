/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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

int main()
{
    // You must use this variable in #3 data analysis section!
    const double GRAMS_IN_LBS = 453.5924;

    int coffeeBagWeightOne, coffeeBagWeightTwo, coffeeBagWeightThree, noOfDailyServings;
    char coffeeTypeOne, coffeeTypeTwo, coffeeTypeThree, coffeeWithCreamOne, coffeeWithCreamTwo, coffeeWithCreamThree, coffeeStrength, servedWithCream;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n");
    printf("\n");
    printf("Enter the coffee product information being sold today...\n");
    printf("\n");
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c",&coffeeTypeOne);
    printf("Bag weight (g): ");
    scanf("%d",&coffeeBagWeightOne);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c",&coffeeWithCreamOne);
    printf("\n");
    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c",&coffeeTypeTwo);
    printf("Bag weight (g): ");
    scanf("%d",&coffeeBagWeightTwo);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffeeWithCreamTwo);
    printf("\n");
    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c",&coffeeTypeThree);
    printf("Bag weight (g): ");
    scanf("%d",&coffeeBagWeightThree);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffeeWithCreamThree);
    printf("\n");
    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",(coffeeTypeOne == 'l' || coffeeTypeOne == 'L'), (coffeeTypeOne == 'm' || coffeeTypeOne == 'M'), (coffeeTypeOne == 'r' || coffeeTypeOne == 'R'),coffeeBagWeightOne, coffeeBagWeightOne/GRAMS_IN_LBS, (coffeeWithCreamOne == 'Y' || coffeeWithCreamOne == 'y'));
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",(coffeeTypeTwo == 'l' || coffeeTypeTwo == 'L'), (coffeeTypeTwo == 'm' || coffeeTypeTwo == 'M'), (coffeeTypeTwo == 'r' || coffeeTypeTwo == 'R'), coffeeBagWeightTwo, coffeeBagWeightTwo / GRAMS_IN_LBS, (coffeeWithCreamTwo == 'Y' || coffeeWithCreamTwo == 'y'));
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",(coffeeTypeThree == 'l' || coffeeTypeThree == 'L'), (coffeeTypeThree == 'm' || coffeeTypeThree == 'M'), (coffeeTypeThree == 'r' || coffeeTypeThree == 'R'), coffeeBagWeightThree, coffeeBagWeightThree / GRAMS_IN_LBS, (coffeeWithCreamThree == 'Y' || coffeeWithCreamThree == 'y'));
    printf("\n");
    printf("Enter how you like your coffee...\n");
    printf("\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &coffeeStrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &servedWithCream);
    printf("Typical number of daily servings: ");
    scanf("%d", &noOfDailyServings);
    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n");
    printf("\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", ((coffeeTypeOne == 'l' || coffeeTypeOne == 'L') && (coffeeStrength == 'l' || coffeeStrength == 'L')) || ((coffeeTypeOne == 'm' || coffeeTypeOne == 'M') && (coffeeStrength == 'm' || coffeeStrength == 'M')) || ((coffeeTypeOne == 'r' || coffeeTypeOne == 'R') && (coffeeStrength == 'r' || coffeeStrength == 'R')), ((noOfDailyServings >= 1 && noOfDailyServings <= 4) && coffeeBagWeightOne == 250) || ((noOfDailyServings >= 5 && noOfDailyServings <= 9) && coffeeBagWeightOne == 500) || ((noOfDailyServings >= 10) && coffeeBagWeightOne == 1000), (((servedWithCream == 'y' || servedWithCream == 'Y') && (coffeeWithCreamOne == 'y' || coffeeWithCreamOne == 'Y'))));
    printf(" 2|       %d         |      %d      |   %d   |\n", ((coffeeTypeTwo == 'l' || coffeeTypeTwo == 'L') && (coffeeStrength == 'l' || coffeeStrength == 'L')) || ((coffeeTypeTwo == 'm' || coffeeTypeTwo == 'M') && (coffeeStrength == 'm' || coffeeStrength == 'M')) || ((coffeeTypeTwo == 'r' || coffeeTypeTwo == 'R') && (coffeeStrength == 'r' || coffeeStrength == 'R')), ((noOfDailyServings >= 1 && noOfDailyServings <= 4) && coffeeBagWeightTwo == 250) || ((noOfDailyServings >= 5 && noOfDailyServings <= 9) && coffeeBagWeightTwo == 500) || ((noOfDailyServings >= 10) && coffeeBagWeightTwo == 1000), (((servedWithCream == 'y' || servedWithCream == 'Y') && (coffeeWithCreamTwo == 'y' || coffeeWithCreamTwo == 'Y'))));
    printf(" 3|       %d         |      %d      |   %d   |\n", ((coffeeTypeThree == 'l' || coffeeTypeThree == 'L') && (coffeeStrength == 'l' || coffeeStrength == 'L')) || ((coffeeTypeThree == 'm' || coffeeTypeThree == 'M') && (coffeeStrength == 'm' || coffeeStrength == 'M')) || ((coffeeTypeThree == 'r' || coffeeTypeThree == 'R') && (coffeeStrength == 'r' || coffeeStrength == 'R')), ((noOfDailyServings >= 1 && noOfDailyServings <= 4) && coffeeBagWeightThree == 250) || ((noOfDailyServings >= 5 && noOfDailyServings <= 9) && coffeeBagWeightThree == 500) || ((noOfDailyServings >= 10) && coffeeBagWeightThree == 1000), (((servedWithCream == 'y' || servedWithCream == 'Y') && (coffeeWithCreamThree == 'y' || coffeeWithCreamThree == 'Y'))));
    printf("\n");
    printf("Enter how you like your coffee...\n");
    printf("\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &coffeeStrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &servedWithCream);
    printf("Typical number of daily servings: ");
    scanf("%d", &noOfDailyServings);
    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n");
    printf("\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", ((coffeeTypeOne == 'l' || coffeeTypeOne == 'L') && (coffeeStrength == 'l' || coffeeStrength == 'L')) || ((coffeeTypeOne == 'm' || coffeeTypeOne == 'M') && (coffeeStrength == 'm' || coffeeStrength == 'M')) || ((coffeeTypeOne == 'r' || coffeeTypeOne == 'R') && (coffeeStrength == 'r' || coffeeStrength == 'R')), ((noOfDailyServings >= 1 && noOfDailyServings <= 4) && coffeeBagWeightOne == 250) || ((noOfDailyServings >= 5 && noOfDailyServings <= 9) && coffeeBagWeightOne == 500) || ((noOfDailyServings >= 10) && coffeeBagWeightOne == 1000), (((servedWithCream == 'y' || servedWithCream == 'Y') && (coffeeWithCreamOne == 'y' || coffeeWithCreamOne == 'Y')) || ((servedWithCream == 'n' || servedWithCream == 'N') && (coffeeWithCreamOne == 'n' || coffeeWithCreamOne == 'N'))));
    printf(" 2|       %d         |      %d      |   %d   |\n", ((coffeeTypeTwo == 'l' || coffeeTypeTwo == 'L') && (coffeeStrength == 'l' || coffeeStrength == 'L')) || ((coffeeTypeTwo == 'm' || coffeeTypeTwo == 'M') && (coffeeStrength == 'm' || coffeeStrength == 'M')) || ((coffeeTypeOne == 'r' || coffeeTypeTwo == 'R') && (coffeeStrength == 'r' || coffeeStrength == 'R')), ((noOfDailyServings >= 1 && noOfDailyServings <= 4) && coffeeBagWeightTwo == 250) || ((noOfDailyServings >= 5 && noOfDailyServings <= 9) && coffeeBagWeightTwo == 500) || ((noOfDailyServings >= 10) && coffeeBagWeightTwo == 1000), (((servedWithCream == 'y' || servedWithCream == 'Y') && (coffeeWithCreamTwo == 'y' || coffeeWithCreamTwo == 'Y')) || ((servedWithCream == 'n' || servedWithCream == 'N') && (coffeeWithCreamTwo == 'n' || coffeeWithCreamTwo == 'N'))));
    printf(" 3|       %d         |      %d      |   %d   |\n", ((coffeeTypeThree == 'l' || coffeeTypeThree == 'L') && (coffeeStrength == 'l' || coffeeStrength == 'L')) || ((coffeeTypeThree == 'm' || coffeeTypeThree == 'M') && (coffeeStrength == 'm' || coffeeStrength == 'M')) || ((coffeeTypeOne == 'r' || coffeeTypeThree == 'R') && (coffeeStrength == 'r' || coffeeStrength == 'R')), ((noOfDailyServings >= 1 && noOfDailyServings <= 4) && coffeeBagWeightThree == 250) || ((noOfDailyServings >= 5 && noOfDailyServings <= 9) && coffeeBagWeightThree == 500) || ((noOfDailyServings >= 10) && coffeeBagWeightThree == 1000), (((servedWithCream == 'y' || servedWithCream == 'Y') && (coffeeWithCreamThree == 'y' || coffeeWithCreamThree == 'Y')) || ((servedWithCream == 'n' || servedWithCream == 'N') && (coffeeWithCreamThree == 'n' || coffeeWithCreamThree == 'N'))));
    printf("\n");
    printf("Hope you found a product that suits your likes!\n");
    return 0;
}