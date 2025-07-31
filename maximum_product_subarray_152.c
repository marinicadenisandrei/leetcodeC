#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int maxProduct(int *numsVar, int numsVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 152. Maximum Product Subarray (C language) - Medium\n");

    int nums[ARRAY_SIZE][ARRAY_SIZE] = {{2,3,-2,4},{-2,0,1}};
    int numsSize[ARRAY_SIZE] = {4,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", maxProduct(nums[test], numsSize[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int maxProduct(int *numsVar, int numsVarSize)
{
    int maxVar = 0;
    int sumVar = 1;

    for (int i = 0; i < numsVarSize; i++)
    {
        for (int j = i; j < numsVarSize; j++)
        {
            sumVar *= numsVar[j];
            maxVar = ((maxVar < sumVar) ? sumVar : maxVar);
        }

        sumVar = 0;
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