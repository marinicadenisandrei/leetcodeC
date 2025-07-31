/* Leetcode - 268. Missing Number (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int missingNumber(int *numsVar, int numsVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 268. Missing Number (C language) - ");

    green();

    printf("Easy\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{3,0,1},{0,1},{9,6,4,2,3,5,7,0,1}};
    int numsSize[NUMBER_OF_TESTS] = {3,2,9};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", missingNumber(nums[test], numsSize[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int missingNumber(int *numsVar, int numsVarSize)
{
    bool flag = true;
    int counter = 0;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < numsVarSize - 1 - counter; i++)
        {
            if (numsVar[i] > numsVar[i + 1])
            {
                int temp = numsVar[i];
                numsVar[i] = numsVar[i + 1];
                numsVar[i + 1] = temp;

                flag = true;
            }
        }
        
        counter++;
    }
    

    for (int i = 0; i < numsVarSize; i++)
    {
        if (numsVar[i + 1] - numsVar[i] > 1)
        {
            return numsVar[i] + 1;
        }
    }
    

    return numsVar[numsVarSize - 1] + 1;
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