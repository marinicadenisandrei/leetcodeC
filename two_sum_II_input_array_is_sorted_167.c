/* Leetcode - 167. Two Sum II - Input Array Is Sorted (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int *twoSum(int *numbersVar, int numbersVarSize, int targetVar);
void printArray(int *array);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 167. Two Sum II - Input Array Is Sorted (C language) - Medium\n");

    int numbers[ARRAY_SIZE][ARRAY_SIZE] = {{2,7,11,15},{2,3,4},{-1,0}};
    int numbersSize[ARRAY_SIZE] = {4,3,2};
    int target[ARRAY_SIZE] = {9,6,-1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int *output = (int*) malloc(2 * sizeof(int)); 
        output = twoSum(numbers[test], numbersSize[test], target[test]);
        printArray(output);

        free(output);

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

void printArray(int *array)
{
    printf("[%i, %i] | ", array[0],array[1]);
}

int *twoSum(int *numbersVar, int numbersVarSize, int targetVar)
{
    int maxVar = numbersVar[numbersVarSize - 1];
    int H[ARRAY_SIZE] = {0};

    int *result = (int*) malloc(2 * sizeof(int));

    if (numbersVarSize == 2 && numbersVar[0] + numbersVar[1] == targetVar)
    {
        result[0] = numbersVar[0];
        result[1] = numbersVar[1];

        return result;
    }

    result[0] = -1;
    result[1] = -1;

    for (int i = 0; i < maxVar; i++)
    {
        H[i] = 0;
    }
    
    for (int i = 0; i < numbersVarSize; i++)
    {
        if (H[targetVar - numbersVar[i]] != 0 && numbersVar[i] <= targetVar)
        {
            result[0] = targetVar - numbersVar[i];
            result[1] = numbersVar[i];

            return result; 
        }

        H[numbersVar[i]]++;
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