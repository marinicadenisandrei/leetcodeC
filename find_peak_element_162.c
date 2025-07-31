/* Leetcode - 162. Find Peak Element (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TEST 2

void reset ();
void green ();
void yellow ();
void red ();

int findPeakElement(int *numsVar, int numsVarSize);

int main()
{
    yellow();

    printf("Leetcode - 162. Find Peak Element (C language) - Medium\n");

    int nums[ARRAY_SIZE][ARRAY_SIZE] = {{1,2,3,1},{1,2,1,3,5,6,4}};
    int numsSize[ARRAY_SIZE] = {4,7};

    for (int test = 0; test < NUMBER_OF_TEST; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", findPeakElement(nums[test], numsSize[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int findPeakElement(int *numsVar, int numsVarSize)
{
    int peak = 0;
    int number = 0;

    for (int i = 0; i < numsVarSize - 2; i++)
    {
        if (numsVar[i] < numsVar[i + 1] && numsVar[i + 1] > numsVar[i + 2])
        {
            if (number < numsVar[i + 1])
            {
                number = numsVar[i + 1];
                peak = i + 1;
            }
        }
    }

    return peak;
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