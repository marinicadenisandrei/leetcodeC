/* Leetcode - 219. Contains Duplicate II (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

bool containsNearbyDuplicate(int *numsVar, int numsVarSize, int kVar);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 219. Contains Duplicate II (C language) - ");

    green();

    printf("Easy\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2,3,1},{1,0,1,1},{1,2,3,1,2,3}};
    int numsSize[NUMBER_OF_TESTS] = {4,4,6};
    int k[NUMBER_OF_TESTS] = {3,1,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", (containsNearbyDuplicate(nums[test], numsSize[test], k[test]) == 1) ? "true" : "false");

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

bool containsNearbyDuplicate(int *numsVar, int numsVarSize, int kVar)
{
    for (int i = 0; i < numsVarSize; i++)
    {
        for (int j = 0; j < numsVarSize; j++)
        {
            if (i != j && abs(i - j) <= kVar && numsVar[i] == numsVar[j])
            {
                return true;
            }
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