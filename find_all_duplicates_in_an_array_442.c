/* Leetcode - 442. Find All Duplicates in an Array (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

int* findDuplicates(int* numsVar, int numsSizeVar, int* resultSizeVar);
void printArray(int* arr, int arrSize);

int main(void)
{
    yellow();
    
    printf("Leetcode - 442. Find All Duplicates in an Array (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{4,3,2,7,8,2,3,1},{1,1,2},{1}};
    int numsSize[NUMBER_OF_TESTS] = {8,3,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int resultSize = 0;
        int* duplicates = findDuplicates(nums[test], numsSize[test], &resultSize);

        printArray(duplicates, resultSize);

        free(duplicates);

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

void printArray(int* arr, int arrSize)
{
    printf("[");
    for (int i = 0; i < arrSize; i++)
    {
        printf("%d%s", arr[i], (i < arrSize - 1) ? ", " : "");
    }
    printf("] | ");
}

int* findDuplicates(int* numsVar, int numsSizeVar, int* resultSizeVar)
{
    int* result = malloc(numsSizeVar * sizeof(int));
    if (!result) {                        
        *resultSizeVar = 0;
        return NULL;
    }

    *resultSizeVar = 0;

    for (int i = 0; i < numsSizeVar; i++)
    {
        for (int j = i + 1; j < numsSizeVar; j++)
        {
            if (numsVar[i] == numsVar[j])
            {
                bool alreadyAdded = false;
                for (int k = 0; k < *resultSizeVar; k++)
                {
                    if (result[k] == numsVar[i])
                    {
                        alreadyAdded = true;
                        break;
                    }
                }

                if (!alreadyAdded)
                {
                    result[*resultSizeVar] = numsVar[i];
                    (*resultSizeVar)++;
                }
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