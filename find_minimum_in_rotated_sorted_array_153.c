#include <stdio.h>
/* Leetcode - 153. Find Minimum in Rotated Sorted Array (C language) - Medium */

#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int findMin(int *numsVar, int numsVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 153. Find Minimum in Rotated Sorted Array (C language) - Medium\n");

    int nums[ARRAY_SIZE][ARRAY_SIZE] = {{3,4,5,1,2},{4,5,6,7,0,1,2},{11,13,15,17}};
    int numsSize[ARRAY_SIZE] = {5,7,4};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", findMin(nums[test], numsSize[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int findMin(int *numsVar, int numsVarSize)
{
    int min = numsVar[0];

    for (int i = 1; i < numsVarSize; i++)
    {
        min = ((min > numsVar[i]) ? numsVar[i] : min);
    }
    
    return min;
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