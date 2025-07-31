/* Leetcode - 220. Contains Duplicate III (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

bool containsNearbyAlmostDuplicate(int *numsVar, int numsVarSize, int indexDiffVar, int valueDiffVar);

int main(void)
{
    yellow();

    printf("Leetcode - 220. Contains Duplicate III (C language) - ");

    red();

    printf("Hard\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2,3,1},{1,5,9,1,5,9}};
    int numsSize[NUMBER_OF_TESTS] = {4,6};
    int indexDiff[NUMBER_OF_TESTS] = {3,2};
    int valueDiff[NUMBER_OF_TESTS] = {0,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", ((containsNearbyAlmostDuplicate(nums[test], numsSize[test], indexDiff[test], valueDiff[test]) == true) ? " true" : "false"));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

bool containsNearbyAlmostDuplicate(int *numsVar, int numsVarSize, int indexDiffVar, int valueDiffVar)
{
    for (int i = 0; i < numsVarSize; i++)
    {
        for (int j = 0; j < numsVarSize; j++)
        {
            if (i != j && abs(i - j) <= indexDiffVar && abs(numsVar[i] - numsVar[j]) <= valueDiffVar)
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