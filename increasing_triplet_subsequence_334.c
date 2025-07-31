/* Leetcode - 334. Increasing Triplet Subsequence (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

bool increasingTriplet(int *numsVar, int numsVarSize);

void reset ();
void green ();
void yellow ();
void red ();

bool main()
{
    yellow();

    printf("Leetcode - 334. Increasing Triplet Subsequence (C language) - Medium");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2,3,4,5},{5,4,3,2,1},{2,1,5,0,4,6}};
    int numsSize[NUMBER_OF_TESTS] = {5,5,6};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", (increasingTriplet(nums[test], numsSize[test]) == 1 ?  "true" : "false"));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

bool increasingTriplet(int *numsVar, int numsVarSize)
{
    for (int i = 0; i < numsVarSize - 2; i++)
    {
        if (numsVar[i] < numsVar[i + 1] && numsVar[i + 1] < numsVar[i + 2])
        {
            return true;
        }
    }
    
    return false;
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