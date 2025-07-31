/* Leetcode - 327. Count of Range Sum (C language) - Hard  */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int countRangeSum(int *numsVar, int numsVarSize, int lowerVar, int upperVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 327. Count of Range Sum (C language) - ");

    red();

    printf("Hard\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{-2,5,-1},{0}};
    int numsSize[NUMBER_OF_TESTS] = {3,1};

    int lower[NUMBER_OF_TESTS] = {-2,0};
    int upper[NUMBER_OF_TESTS] = {2,0};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", countRangeSum(nums[test], numsSize[test], lower[test], upper[test]));

        green();

        printf("Passed\n");
    }

    reset();
}

int countRangeSum(int *numsVar, int numsVarSize, int lowerVar, int upperVar)
{
    int sumVar = 0;
    int counter = 0;

    for (int i = 0; i < numsVarSize; i++)
    {
        for (int j = i; j < numsVarSize; j++)
        {
            sumVar += numsVar[j];

            if (sumVar >= lowerVar && sumVar <= upperVar)
            {
                counter++;
            }
        }  

        sumVar = 0;
    }

    return counter;
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