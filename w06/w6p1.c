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
#define LIMIT 10

int main(void)
{
	const double minimumMonthlyIncome = 500.00, maximumMonthlyIncome = 400000.00;
	int flag[] = { 0,0,0,0,0 };
	int priority[10];
	int listItems, i;
	char financed[100];
	double costOfItem[LIMIT], totalValue = 0.0, netMonthlyIncome;

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");
	printf("\n");

	while (flag[0] == 0)

	{
		printf("Enter your monthly NET income: $");
		scanf("%lf", &netMonthlyIncome);

		if (netMonthlyIncome < minimumMonthlyIncome)
		{
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
			printf("\n");
		}

		else if (netMonthlyIncome > maximumMonthlyIncome)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
			printf("\n");
		}

		else
		{
			flag[0] = 1;
		}
	}

	printf("\n");

	while (flag[1] == 0)
	{
		printf("How many wish list items do you want to forecast?: ");
		scanf("%d", &listItems);
		if (listItems < 1 || listItems > 10)
		{
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
			printf("\n");
		}
		else
		{
			flag[1] = 1;
		}
	} 

	for (i = 0; i < listItems; i++)
	{
		printf("\n");
		printf("Item-%d Details:\n", i + 1);
	
		while(flag[2]==0)
		{
			printf("   Item cost: $");
			scanf("%lf", &costOfItem[i]);
			if (costOfItem[i] < 100.00)
			{
				printf("      ERROR: Cost must be at least $100.00\n");
			}
			else
			{
				flag[2] = 1;
			}
		} 
	
		while (flag[3] == 0)
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &priority[i]);
			if (priority[i] < 1 || priority[i] > 3)
			{
				printf("      ERROR: Value must be between 1 and 3\n");
			}
			else
			{
				flag[3] = 1;
			}
		} 

		while (flag[4] == 0)
		{
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &financed[i]);
			if (financed[i] != 'y' && financed[i] != 'n')
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}
			else
			{
				flag[4] = 1;
			}
		} 
		flag[2] = 0;
		flag[3] = 0;
		flag[4] = 0;
	
	}


	printf("\n");
	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	
	for (i = 0; i < listItems; i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], financed[i], costOfItem[i]);
		totalValue += costOfItem[i];
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", totalValue);
	printf("Best of luck in all your future endeavours!");
	printf("\n");

	return 0;
}
