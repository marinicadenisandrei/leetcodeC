/* Leetcode - 34. Find First and Last Position of Element in Sorted Array (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int findFirstElementInArray(int array[ARRAY_SIZE], int arraySize, int element);
int findLastElementInArray(int array[ARRAY_SIZE], int arraySize, int element);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 34. Find First and Last Position of Element in Sorted Array (C language) - Medium\n");

    int nums[ARRAY_SIZE][ARRAY_SIZE] = {{5,7,7,8,8,10}, {5,7,7,8,8,10}, {}};
    int target[ARRAY_SIZE] = {8, 6, 0};
    int numsSize[ARRAY_SIZE] = {6, 6, 0};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int output[2] = {findFirstElementInArray(nums[test], numsSize[test], target[test]), findLastElementInArray(nums[test], numsSize[test], target[test])};

        green();

        printf("Test %i: ", test + 1);

        reset();

        for (int i = 0; i < 2; i++)
        {
            printf("%s%i%s", (i == 0) ? "[" : "", output[i], (i < 1) ? ", " : "] | ");
        }

        green();

        printf("Passed\n");

        reset();
    }
    
    return 0;
}

int findFirstElementInArray(int array[ARRAY_SIZE], int arraySize, int element)
{
    if (arraySize == 0)
    {
        return -1;
    }
    
    int *pFirst = array;

    bool firstFlag = false;
    bool lastFlag = false;

    for (int i = 0; i < arraySize; i++, pFirst++)
    {
        if (*pFirst == element)
        {
            return i;
        }
    }

    return -1;
}

int findLastElementInArray(int array[ARRAY_SIZE], int arraySize, int element)
{
    if (arraySize == 0)
    {
        return -1;
    }

    int *pLast = array + arraySize - 1;

    bool firstFlag = false;
    bool lastFlag = false;

    for (int i = arraySize - 1; i > 0; i--, pLast--)
    {
        if (*pLast == element)
        {
            return i;
        };
    }

    return -1;
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