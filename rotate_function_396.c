/* Leetcode - 396. Rotate Function (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int maxRotateFunction(int* numsVar, int numsSizeVar);

int main()
{
    yellow();
    
    printf("Leetcode - 396. Rotate Function (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{4,3,2,6},{100}};
    int numsSize[NUMBER_OF_TESTS] = {4,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", maxRotateFunction(nums[test], numsSize[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int maxRotateFunction(int* numsVar, int numsSizeVar)
{
    int maxValue = 0;
    int tempResult = 0;

    for (int i = 0; i < numsSizeVar; i++)
    {
        tempResult += (numsVar[i] * i);
    }
    
    maxValue = tempResult;

    for (int i = 0; i < numsSizeVar - 1; i++)
    {
        int temp = numsVar[numsSizeVar - 1];
        tempResult = 0;

        for (int j = numsSizeVar - 1; j > 0; j--)
        {
            numsVar[j] = numsVar[j - 1];
        }
        
        numsVar[0] = temp;

        for (int j = 0; j < numsSizeVar; j++)
        {
            tempResult += (numsVar[j] * j); 
        }
        
        maxValue = ((maxValue < tempResult) ? tempResult : maxValue);
    }

    return maxValue;
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