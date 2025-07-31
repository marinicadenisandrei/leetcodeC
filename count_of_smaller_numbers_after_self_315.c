/* Leetcode - 315. Count of Smaller Numbers After Self (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int* countSmaller(int *numsVar, int numsVarSize);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 315. Count of Smaller Numbers After Self (C language) - ");

    red();

    printf("Hard\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{5,2,6,1},{-1},{-1,-1}};
    int numsSize[NUMBER_OF_TESTS] = {4,1,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printArray(countSmaller(nums[test], numsSize[test]), numsSize[test]);

        green();

        printf("Passed\n");
    }

    reset();
}

void printArray(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "] | "));
    }
}

int* countSmaller(int *numsVar, int numsVarSize)
{
    int *result = (int*)malloc(numsVarSize * sizeof(int));
    
    for (int i = 0; i < numsVarSize; i++)
    {
        result[i] = 0;

        for (int j = i; j < numsVarSize; j++)
        {
            if (i != j && numsVar[i] > numsVar[j])
            {
                result[i]++;
            } 
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