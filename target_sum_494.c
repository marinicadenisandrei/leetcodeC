/* Leetcode - 494. Target Sum (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int findTargetSumWays(int* nums, int numsSize, int index, int sum, int target);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 494. Target Sum (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,1,1,1,1},{1}};
    int numsSize[NUMBER_OF_TESTS] = {5,1};
    int target[NUMBER_OF_TESTS] = {3,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int result = findTargetSumWays(nums[test], numsSize[test], 0, 0, target[test]);
        printf("%i | ", result);

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int findTargetSumWays(int* nums, int numsSize, int index, int sum, int target)
{
    if (index == numsSize)
    {
        if (target == sum)
        {
            return 1;
        }
        
        return 0;
    }
    
    return findTargetSumWays(nums, numsSize, index + 1, sum + nums[index], target)
        + findTargetSumWays(nums, numsSize, index + 1, sum - nums[index], target);
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