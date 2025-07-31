/* Leetcode - 239. Sliding Window Maximum (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int* maxSlidingWindow(int *numsVar, int numsVarSize, int kVar, int *outputSize);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();
    
    printf("Leetcode - 239. Sliding Window Maximum (C language) - ");
    
    red();

    printf("Hard\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,3,-1,-3,5,3,6,7},{1}};
    int numsSize[NUMBER_OF_TESTS] = {8,1};
    int k[NUMBER_OF_TESTS] = {3,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int outputSize = 0;
        int *output = maxSlidingWindow(nums[test], numsSize[test], k[test], &outputSize);
        printArray(output, outputSize);
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

int* maxSlidingWindow(int *numsVar, int numsVarSize, int kVar, int *outputSize)
{
    int start = 0;
    int end = start + kVar;

    int *result = (int*)malloc(ARRAY_SIZE * sizeof(int));

    while (end <= numsVarSize)
    {   
        int max = 0;
        
        for (int i = start; i < end; i++)
        {
            if (max < numsVar[i])
            {
                max = numsVar[i];
            }
        }

        result[*outputSize] = max;
        (*outputSize)++;

        start++;
        end = start + kVar;
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