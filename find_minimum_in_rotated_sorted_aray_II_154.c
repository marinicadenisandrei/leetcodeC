/* Leetcode - 154. Find Minimum in Rotated Sorted Array II (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int findMin(int *numsVar, int numsVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{   
    yellow();

    printf("Leetcode - 154. Find Minimum in Rotated Sorted Array II (C language) - ");

    red();

    printf("Hard\n");

    int nums[ARRAY_SIZE][ARRAY_SIZE] = {{1,3,5},{2,2,2,0,1}};
    int numsSize[ARRAY_SIZE] = {3,5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ",findMin(nums[test], numsSize[test]));

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
        min = ((numsVar[i] < min) ? numsVar[i] : min);
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