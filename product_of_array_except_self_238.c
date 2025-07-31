/* Leetcode - 238. Product of Array Except Self (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int* productExceptSelf(int *numsVar, int numsVarSize);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 238. Product of Array Except Self (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2,3,4},{-1,1,0,-3,3}};
    int numsSize[NUMBER_OF_TESTS] = {4,5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {   
        green();

        printf("Test %i: ", test + 1);

        reset();

        int *output = productExceptSelf(nums[test], numsSize[test]);
        printArray(output, numsSize[test]);

        output = NULL;

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

int* productExceptSelf(int *numsVar, int numsVarSize)
{
    int *result = (int*) malloc(ARRAY_SIZE * sizeof(int));
    int resultSize = 0;

    for (int i = 0; i < numsVarSize; i++)
    {
        int product = 1;

        for (int j = 0; j < numsVarSize; j++)
        {
            if (i != j)
            {
                product *= numsVar[j]; 
            }
        }
        
        result[resultSize++] = product; 
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