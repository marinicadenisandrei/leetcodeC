/* Leetcode - 217. Contains Duplicate (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

bool containsDuplicate(int *nums, int numsSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();
    
    printf("Leetcode - 217. Contains Duplicate (C language) - ");

    green();

    printf("Easy\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2,3,1},{1,2,3,4},{1,1,1,3,3,4,3,2,4,2}};
    int numsSize[NUMBER_OF_TESTS] = {4,4,10};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", (containsDuplicate(nums[test], numsSize[test]) == 1) ? "true" : "false");

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

bool containsDuplicate(int *nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < numsSize; j++)
        {
            if (i != j && nums[i] == nums[j])
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