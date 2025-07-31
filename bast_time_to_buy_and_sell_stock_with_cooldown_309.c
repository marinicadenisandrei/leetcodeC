/* Leetcode - 309. Best Time to Buy and Sell Stock with Cooldown (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int maxProfit(int *pricesVar, int pricesVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 309. Best Time to Buy and Sell Stock with Cooldown (C language) - Medium\n");

    int prices[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2,3,0,2},{1}};
    int pricesSize[NUMBER_OF_TESTS] = {5,1};

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

int maxProfit(int *pricesVar, int pricesVarSize)
{
    int maxProfit = 0;

    for (int i = 0; i < pricesVarSize; i++)
    {
        int profit = 0;
        int start = pricesVar[i];

        for (int j = i; j < pricesVarSize - 1; j++)
        {
            if (pricesVar[j] < pricesVar[j + 1])
            {
                profit += (pricesVar[j + 1] - start);
                j += 2; 
                start = pricesVar[j + 1];
            }
        }
        
        maxProfit = ((maxProfit < profit) ? profit : maxProfit);
    }

    for (int i = 0; i < pricesVarSize; i++)
    {
        int profit = 0;
        int start = pricesVar[i];

        for (int j = i; j < pricesVarSize - 1; j++)
        {
            if (pricesVar[j] > pricesVar[j + 1])
            {
                profit += (pricesVar[j] - start);
                j += 2; 
                start = pricesVar[j + 1];
            }
        }
        
        maxProfit = ((maxProfit < profit) ? profit : maxProfit);
    }

    return maxProfit;    
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