/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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
#define MIN_YEAR 2012 
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{

    const int JAN = 1, DEC = 12;
    int flag = 0, year, month, i;
    double morningRating, eveningRating, sumOfMorning = 0, sumOfEvening = 0, averageRatingMorning, averageRatingEvening;
    printf("General Well-being Log\n");
    printf("======================\n");
    while (flag == 0)
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d%d", &year, &month);
        if (year< MIN_YEAR || year>MAX_YEAR)
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
            if (month<JAN || month>DEC)
            {
                printf("   ERROR: Jan.(1) - Dec.(12)\n");
            }
        }
        else if (month<JAN || month>DEC)
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        else
        {
            flag = 1;
        }
    }
    printf("\n");
    printf("*** Log date set! ***\n");
    printf("\n");
    for (i = 0; i < LOG_DAYS; i++)
    {
        switch (month)
        {
        case 1:printf("%d-JAN-%.2d\n", year, i + 1);
            break;
        case 2:printf("%d-FEB-%.2d\n", year, i + 1);
            break;
        case 3:printf("%d-MAR-%.2d\n", year, i + 1);
            break;
        case 4:printf("%d-APR-%.2d\n", year, i + 1);
            break;
        case 5:printf("%d-MAY-%.2d\n", year, i + 1);
            break;
        case 6:printf("%d-JUN-%.2d\n", year, i + 1);
            break;
        case 7:printf("%d-JUL-%.2d\n", year, i + 1);
            break;
        case 8:printf("%d-AUG-%.2d\n", year, i + 1);
            break;
        case 9:printf("%d-SEP-%.2d\n", year, i + 1);
            break;
        case 10:printf("%d-OCT-%.2d\n", year, i + 1);
            break;
        case 11:printf("%d-NOV-%.2d\n", year, i + 1);
            break;
        case 12:printf("%d-DEC-%.2d\n", year, i + 1);
            break;
        }
        do {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morningRating);
            if (morningRating < 0.0 || morningRating>5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (morningRating < 0.0 || morningRating>5.0);
        sumOfMorning = sumOfMorning + morningRating;
        do {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &eveningRating);
            if (eveningRating < 0.0 || eveningRating>5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (eveningRating < 0.0 || eveningRating>5.0);
        printf("\n");
        sumOfEvening = sumOfEvening + eveningRating;
    }


        printf("Summary\n");
        printf("=======\n");
        printf("Morning total rating: %.3lf\n", sumOfMorning);
        printf("Evening total rating:  %.3lf\n", sumOfEvening);
        printf("----------------------------\n");
        printf("Overall total rating: %.3lf\n\n", sumOfMorning + sumOfEvening);
        averageRatingMorning = sumOfMorning / LOG_DAYS;
        averageRatingEvening = sumOfEvening / LOG_DAYS;
        printf("Average morning rating:  %.1lf\n", averageRatingMorning);
        printf("Average evening rating:  %.1lf\n", averageRatingEvening);
        printf("----------------------------\n");
        printf("Average overall rating:  %.1lf\n", (averageRatingMorning + averageRatingEvening) / 2);
   

    return 0;
}
