/* Leetcode - 448. Find All Numbers Disappeared in an Array (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int* findDisappearedNumbers(int* numsVar, int numsSizeVar, int* resultSize);
void printArray(int* arr, int arrSize);

int main()
{
    yellow();

    printf("Leetcode - 448. Find All Numbers Disappeared in an Array (C language) - ");

    green();

    printf("Easy\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{4,3,2,7,8,2,3,1},{1,1}};
    int numsSize[NUMBER_OF_TESTS] = {8,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int resultSize = 0;
        int* result = findDisappearedNumbers(nums[test], numsSize[test], &resultSize);

        printArray(result, resultSize);
        free(result);

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

void printArray(int* arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), arr[i], ((i < arrSize - 1) ? ", " : "] | "));   
    }
}

int* findDisappearedNumbers(int* numsVar, int numsSizeVar, int* resultSize)
{
    int* result = malloc(ARRAY_SIZE * sizeof(int));
    if (!result) {
        perror("malloc failed");
        exit(1);
    }

    *resultSize = 0;
    int start = 1;

    while (start <= numsSizeVar)
    {
        bool flag = true;

        for (int i = 0; i < numsSizeVar; i++)
        {
            if (numsVar[i] == start)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            result[(*resultSize)++] = start;
        }

        start++;
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