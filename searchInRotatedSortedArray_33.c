/* Leetcode - 33. Search in Rotated Sorted Array (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int searchElementInArray(int array[ARRAY_SIZE], int arraySize, int element);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 33. Search in Rotated Sorted Array (C language) - Medium\n");

    int nums[ARRAY_SIZE][ARRAY_SIZE] = {{4,5,6,7,0,1,2}, {4,5,6,7,0,1,2}, {1}};
    int numsSize[ARRAY_SIZE] = {7, 7, 1};
    int target[ARRAY_SIZE] = {0, 3, 0};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int result = searchElementInArray(nums[test], numsSize[test], target[test]);

        printf("%i | ", result);

        green();

        printf("Passed\n");

        reset();
    }
    
    return 0;
}

int searchElementInArray(int array[ARRAY_SIZE], int arraySize, int element)
{
    int *parray = array;

    for (int i = 0; i < arraySize; i++, parray++)
    {
        if (*parray == element)
        {
            return i;
        }
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