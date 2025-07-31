/* Leetcode - 189. Rotate Array (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void rotate(int *numsVar, int numsVarSize, int kVar);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 189. Rotate Array (C language) - Medium\n");
    
    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2,3,4,5,6,7}, {-1,-100,3,99}};
    int numsSize[NUMBER_OF_TESTS] = {7,2};
    int k[NUMBER_OF_TESTS] = {3,2};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        rotate(nums[test], numsSize[test], k[test]);
        printArray(nums[test], numsSize[test]);

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

void printArray(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "]"));
    }

    printf(" | ");
}

void rotate(int *numsVar, int numsVarSize, int kVar)
{
    for (int i = numsVarSize - 1; i >= 0; i--)
    {
        numsVar[i + kVar] = numsVar[i];
    }

    for (int i = numsVarSize, index = 0; i < numsVarSize + kVar; i++, index++)
    {
        numsVar[index] = numsVar[i];
    }
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