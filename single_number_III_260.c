/* Leetcode - 260. Single Number III (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int* singleNumber(int *numsVar, int numsVarSize, int *resultSize);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 260. Single Number III (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2,1,3,2,5},{-1,0},{0,1}};
    int numsSize[NUMBER_OF_TESTS] = {6,2,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int resultSize = 0;
        int *output = singleNumber(nums[test], numsSize[test], &resultSize);
        printArray(output, resultSize);

        free(output);

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
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "] | "));
    }
}

int* singleNumber(int *numsVar, int numsVarSize, int *resultSize)
{
    int *result = (int*)malloc(sizeof(int) * numsVarSize);
    bool flag = false;

    for (int i = 0; i < numsVarSize; i++)
    {
        flag = false;

        for (int j = 0; j < numsVarSize; j++)
        {
            if (i != j && numsVar[i] == numsVar[j])
            {
                flag = true;
                break;
            }
        }

        if (!flag)
        {
            result[(*resultSize)++] = numsVar[i];
        }
    }

    return result;
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