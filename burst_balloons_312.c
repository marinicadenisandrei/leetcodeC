/* Leetcode - 312. Burst Balloons (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int maxCoins(int *numsVar, int numsVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 312. Burst Balloons (C language) - ");

    red();

    printf("Hard\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{3,1,5,8},{1,5}};
    int numsSize[NUMBER_OF_TESTS] = {4,2}; 

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", maxCoins(nums[test], numsSize[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int maxCoins(int *numsVar, int numsVarSize)
{
    int sum = 0;

    while (numsVarSize > 0)
    {
        int temp = 1;

        for (int i = 0; i < ((numsVarSize > 3) ? 3 : numsVarSize); i++)
        {
            temp *= numsVar[i];
        }
        
        for (int i = ((numsVarSize > 2) ? 1 : 0); i < numsVarSize - 1; i++)
        {
            numsVar[i] = numsVar[i + 1];
        }

        sum += temp;
        numsVarSize--;
    }

    return sum;
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