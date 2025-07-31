/* Leetcode - 347. Top K Frequent Elements (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int* topKFrequent(int *numsVar, int numsSizeVar, int kVar);
bool elementInArray(int *array, int arraySize, int element);
void displayArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 347. Top K Frequent Elements (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,1,1,2,2,3},{1}};
    int numsSize[NUMBER_OF_TESTS] = {6,1};
    int k[NUMBER_OF_TESTS] = {2,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int *result = topKFrequent(nums[test], numsSize[test], k[test]);
        displayArray(result, k[test]);
        free(result);

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

void displayArray(int *array, int arraySize)
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

int* topKFrequent(int *numsVar, int numsSizeVar, int kVar)
{
    int *result=(int*)malloc(numsSizeVar * sizeof(int));
    int resultSize = 0;

    int noDuplicates[ARRAY_SIZE] = {};
    int noDuplicatesSize = 0;
    
    int occForNoDuplicates[ARRAY_SIZE] = {};

    bool flag = true;
    int c = 0;

    for (int i = 0; i < numsSizeVar; i++)
    {
        if (!elementInArray(noDuplicates, noDuplicatesSize, numsVar[i]))
        {
            noDuplicates[noDuplicatesSize] = numsVar[i];
            int counter = 0;

            for (int j = 0; j < numsSizeVar; j++)
            {
                if (numsVar[j] == numsVar[i])
                {
                    counter++;
                }
                
            }
            
            occForNoDuplicates[noDuplicatesSize++] = counter;
        }
    }

    while (flag)
    {
        flag = false;

        for (int i = 0; i < noDuplicatesSize - 1 - c; i++)
        {
            if (occForNoDuplicates[i] < occForNoDuplicates[i + 1])
            {
                int temp = occForNoDuplicates[i];
                occForNoDuplicates[i] = occForNoDuplicates[i + 1];
                occForNoDuplicates[i + 1] = temp;

                temp = noDuplicates[i];
                noDuplicates[i] = noDuplicates[i + 1];
                noDuplicates[i + 1] = temp;

                flag = true;
            }
        }

        c++;
    }
    
    for (int i = 0; i < kVar; i++)
    {
        result[resultSize++] = noDuplicates[i];
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