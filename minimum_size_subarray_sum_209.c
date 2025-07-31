/* Leetcode - 209. Minimum Size Subarray Sum (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int minSubArrayLen(int *numsVar, int numsVarSize, int targetVar);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 209. Minimum Size Subarray Sum (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{2,3,1,2,4,3},{1,4,4},{1,1,1,1,1,1,1,1}};
    int numsSize[NUMBER_OF_TESTS] = {6,3,8};
    int target[NUMBER_OF_TESTS] = {7,4,11};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", minSubArrayLen(nums[test], numsSize[test], target[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int minSubArrayLen(int *numsVar, int numsVarSize, int targetVar)
{
    int sum = 0;
    int count = 0;
    int result = 99;

    for (int i = 0; i < numsVarSize; i++)
    {
        for (int j = i; j < numsVarSize; j++)
        {
            sum += numsVar[j];
            count++;

            if (sum == targetVar)
            {
                if (result > count)
                {
                    result = count;
                }
            }
        }

        count = 0;
        sum = 0;
    }

    if (result != 99)
    {
        return result;
    }
    
    return 0;
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
