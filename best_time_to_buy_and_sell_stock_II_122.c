/* Leetcode - 122. Best Time to Buy and Sell Stock II (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20

int maxProfit(int* pricesVar, int pricesSizeVar);
bool ascendingOrder(int *array, int arraySize);
int profitAscending(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 122. Best Time to Buy and Sell Stock II (C language) - Medium\n");

    int prices[ARRAY_SIZE][ARRAY_SIZE] = {{7,1,5,3,6,4}, {1,2,3,4,5}, {7,6,4,3,1}};
    int pricesSize[ARRAY_SIZE] = {6, 5, 5};

    for (int test = 0; test < 3; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        int profit = maxProfit(prices[test], pricesSize[test]);

        reset();

        printf("%i | ", profit);

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

bool ascendingOrder(int *array, int arraySize)
{
    for (int i = 0; i < arraySize - 1; i++)
    {
        if (array[i + 1] - array[i] < 0)
        {
            return false;
        }
    }

    return true;
}

int profitAscending(int *array, int arraySize)
{
    int minVar = 0;
    int maxVar = 0;

    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] < minVar)
        {
            minVar = i;
        }
    }

    for (int i = minVar + 1; i < arraySize; i++)
    {
        if (array[i] > maxVar)
        {
            maxVar = i;
        }
    }

    return array[maxVar] - array[minVar];
}

int maxProfit(int* pricesVar, int pricesSizeVar)
{
    int profit = 0;

    if (ascendingOrder(pricesVar, pricesSizeVar))
    {
        return profitAscending(pricesVar, pricesSizeVar);
    }
    
    for (int i = 0; i < pricesSizeVar - 2; i++)
    {
        if (pricesVar[i + 1] - pricesVar[i] > 0 && pricesVar[i + 2] - pricesVar[i + 1] < 0)
        {
            profit += pricesVar[i + 1] - pricesVar[i];
        }
    }

    return profit;
}

void reset () {
  printf("\033[1;0m");
}

void green () {
  printf("\033[1;32m");
}

void yellow () {
  printf("\033[1;33m");
}

void red () {
  printf("\033[1;31m");
}