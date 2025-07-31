/* Leetcode - 123. Best Time to Buy and Sell Stock III (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int maxProfit(int *pricesVar, int pricesVarSize);
bool ascendingArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 123. Best Time to Buy and Sell Stock III (C language) - ");

    red();

    printf("Hard\n");

    int prices[ARRAY_SIZE][ARRAY_SIZE] = {{3,3,5,0,0,3,1,4},{1,2,3,4,5}};
    int pricesSize[ARRAY_SIZE] = {8,5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {   
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", maxProfit(prices[test], pricesSize[test]));

        green();
        
        printf("Passed\n");
    }

    reset();
    
    return 0;
}

bool descendingArray(int *array, int arraySize)
{
    for (int i = 0; i < arraySize - 1; i++)
    {
        if (array[i + 1] - array[i] > 0)
        {
            return false;
        }
    }

    return true;
}

int maxProfit(int *pricesVar, int pricesVarSize)
{
    int profit = 0;
    int minIndex = 0;

    if (descendingArray(pricesVar, pricesVarSize))
    {
        return 0;    
    }
    
    for (int i = 1; i < pricesVarSize; i++)
    {
        if (pricesVar[minIndex] > pricesVar[i])
        {
            minIndex = i;
        }
    }

    for (int i = minIndex + 1; i < pricesVarSize; i++)
    {
        if (pricesVar[i] > pricesVar[minIndex] && pricesVar[i + 1] < pricesVar[i])
        {
            profit += pricesVar[i] - pricesVar[minIndex];
            minIndex = i + 1;
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