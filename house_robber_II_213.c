/* Leetcode - 213. House Robber II (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int rob(int *numsVar, int numsVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 213. House Robber II (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{2,3,2},{1,2,3,1},{1,2,3}};
    int numsSize[NUMBER_OF_TESTS] = {3,4,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", rob(nums[test], numsSize[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int rob(int *numsVar, int numsVarSize)
{
    int maxVar = 0;
    
    for (int i = 0; i < numsVarSize; i++)
    {
        int sum = 0;

        for (int j = i; j < numsVarSize - ((numsVarSize % 2 == 1) ? 1 : 0); j += 2)
        {
            sum += numsVar[j];
        }

        if (sum > maxVar)
        {
            maxVar = sum;
            sum = 0;
        }
    }

    if (numsVar[numsVarSize - 1] > maxVar)
    {
        maxVar = numsVar[numsVarSize - 1];
    }

    return maxVar;
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