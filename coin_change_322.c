/* Leetcode - 322. Coin Change (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int coinChange(int *coinsVar, int coinsVarSize, int amountVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 322. Coin Change (C language) - Medium\n");

    int coins[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2,5}, {2}, {1}};
    int coinsSize[NUMBER_OF_TESTS] = {3,1,1};
    int amount[NUMBER_OF_TESTS] = {11,3,0};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", coinChange(coins[test], coinsSize[test], amount[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int coinChange(int *coinsVar, int coinsVarSize, int amountVar)
{
    if (amountVar == 0)
    {
        return 0;
    }

    int count = 0;

    while (amountVar > 0)
    {
        if (amountVar - coinsVar[coinsVarSize - 1] >= 0)
        {
            amountVar -= coinsVar[coinsVarSize - 1];
            count++;
        }
        else
        {
            coinsVarSize--;
        }

        if (coinsVarSize == 0)
        {
            break;
        }
    }

    if (amountVar == 0)
    {
        return count;
    }
    
    return -1;
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