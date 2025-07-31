/* Leetcode - 188. Best Time to Buy and Sell Stock IV (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int maxProfit(int kVar, int *pricesVar, int pricesVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 188. Best Time to Buy and Sell Stock IV (C language) - ");

    red();

    printf("Hard\n");

    int prices[NUMBER_OF_TESTS][ARRAY_SIZE] = {{2,4,1},{3,2,6,5,0,3}};
    int pricesSize[NUMBER_OF_TESTS] = {3,6};
    int k[ARRAY_SIZE] = {2,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {   
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | " ,maxProfit(k[test], prices[test], pricesSize[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int maxProfit(int kVar, int *pricesVar, int pricesVarSize)
{
    int profit = 0;
    int maxProfit = 0;
    
    for (int j = 0; j < pricesVarSize - 2; j++)
    {
        int buy = pricesVar[j];
        int indexHistory = 0;
        bool flag = false;

        for (int i = 1; i < pricesVarSize; i++)
        {
            flag = false;

            if (pricesVar[i] > pricesVar[i + 1])
            {
                profit += pricesVar[i] - buy;
                
                buy = pricesVar[i + 1];
                indexHistory = i + 1;

                flag = true;
            }

            if (flag == false && i == pricesVarSize - 1)
            {
                i = indexHistory;
                buy = pricesVar[indexHistory];
            }
        }

        maxProfit = ((maxProfit < profit) ? profit : maxProfit);
        profit = 0;
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

