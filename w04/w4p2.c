/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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

int main(void)
{
    int askForApple, askForOrange, askForPears, askForTomatoes, askForCabbages, selectedItem, anotherShopping = 1;
    int flag = 0;

    while (flag == 0 && anotherShopping != 0)
    {
        printf("Grocery Shopping\n");
        printf("================\n");

    do
    {
            printf("How many APPLES do you need? : ");
            scanf("%d", &askForApple);
            if (askForApple < 0)
            {
            printf("ERROR: Value must be 0 or more.\n");
            }
            } while (askForApple < 0);
            printf("\n");

    do
    {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &askForOrange);
            if (askForOrange < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            } while (askForOrange < 0);
            printf("\n");

    do
    {
            printf("How many PEARS do you need? : ");
            scanf("%d", &askForPears);
            if (askForPears < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            } while (askForPears < 0);
            printf("\n");

    do
    {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &askForTomatoes);
            if (askForTomatoes < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            } while (askForTomatoes < 0);
            printf("\n");

    do
    {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &askForCabbages);
            if (askForCabbages < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            } while (askForCabbages < 0);
            printf("\n");

            printf("--------------------------\n");
            printf("Time to pick the products!\n");
            printf("--------------------------\n\n");

                while (askForApple > 0)
                {
                while (askForApple != 0)
                {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &selectedItem);

                if (selectedItem > askForApple)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", askForApple);
                }
                else if (selectedItem <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (selectedItem < askForApple)
                {
                    askForApple = askForApple - selectedItem;
                    printf("Looks like we still need some APPLES...\n");
                }
                else if (selectedItem == askForApple)
                {
                    askForApple = askForApple - selectedItem;
                    printf("Great, that's the apples done!\n\n");
                }
                }
                }

                while (askForOrange > 0)
                {
                while (askForOrange != 0)
                {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &selectedItem);

                if (selectedItem > askForOrange)
                {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", askForOrange);
                }
                else if (selectedItem <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (selectedItem < askForOrange)
                {
                    askForOrange = askForOrange - selectedItem;
                    printf("Looks like we still need some ORANGES...\n");
                }
                else if (selectedItem == askForOrange)
                {
                    askForOrange = askForOrange - selectedItem;
                    printf("Great, that's the oranges done!\n\n");
                }
                }
                }

                while (askForPears > 0)
                {
                while (askForPears != 0)
                {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &selectedItem);

                if (selectedItem > askForPears)
                {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", askForPears);
                }
                else if (selectedItem <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (selectedItem < askForPears)
                {
                    askForPears = askForPears - selectedItem;
                    printf("Looks like we still need some PEARS...\n");
                }
                else if (selectedItem == askForPears)
                {
                    askForPears = askForPears - selectedItem;
                    printf("Great, that's the pears done!\n\n");
                }
                }
                }

                while (askForTomatoes > 0)
                {
                while (askForTomatoes != 0)
                {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &selectedItem);

                if (selectedItem > askForTomatoes)
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", askForTomatoes);
                }
                else if (selectedItem <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (selectedItem < askForTomatoes)
                {
                    askForTomatoes = askForTomatoes - selectedItem;
                    printf("Looks like we still need some TOMATOES...\n");
                }
                else if (selectedItem == askForTomatoes)
                {
                    askForTomatoes = askForTomatoes - selectedItem;
                    printf("Great, that's the tomatoes done!\n\n");
                }
                }
                }

                while (askForCabbages > 0)
                {
                while (askForCabbages != 0)
                {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &selectedItem);

                if (selectedItem > askForCabbages)
                {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", askForCabbages);
                }
                else if (selectedItem <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (selectedItem < askForCabbages)
                {
                    askForCabbages = askForCabbages - selectedItem;
                    printf("Looks like we still need some CABBAGES...\n");
                }
                else if (selectedItem == askForCabbages)
                {
                    askForCabbages = askForCabbages - selectedItem;
                    printf("Great, that's the cabbages done!\n\n");
                }
                }
                }
        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &anotherShopping);
        printf("\n");
    }

    printf("Your tasks are done for today - enjoy your free time!");
    printf("\n");
    return 0;
}
