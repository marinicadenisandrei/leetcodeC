/* Leetcode - 229. Majority Element II (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int resultSize = 0;

int* majorityElement(int *numsVar, int numsVarSize);
bool elementInArray(int *array, int arraySize, int element);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 229. Majority Element II (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{3,2,3},{1},{1,2}};
    int numsSize[NUMBER_OF_TESTS] = {3,1,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int *output = majorityElement(nums[test], numsSize[test]);
        printArray(output, resultSize);
        resultSize = 0;

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

bool elementInArray(int *array, int arraySize, int element)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] == element)
        {
            return true;
        }
    }
    
    return false;
}

int* majorityElement(int *numsVar, int numsVarSize)
{
    int count = 0;
    int *result = (int *) malloc(ARRAY_SIZE * sizeof(int));

    for (int i = 0; i < numsVarSize; i++)
    {
        int ctemp = 0;

        for (int j = 0; j < numsVarSize; j++)
        {
            if (i != j && numsVar[i] == numsVar[j])
            {
                ctemp++;
            }
        }

        if (ctemp >= (int) numsVarSize / 3 && !elementInArray(result, resultSize, numsVar[i]))
        {
            result[resultSize++] = numsVar[i];
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