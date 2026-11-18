/* Leetcode - 498. Diagonal Traverse (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int *findDiagonalOrder(int matVar[ARRAY_SIZE][ARRAY_SIZE], int matSizeVar, int matInSizeVar, int *returnSize);
void printArr(int arr[ARRAY_SIZE], int arrSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 498. Diagonal Traverse (C language) - Medium\n");

    int mat[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE] = {
        {{1,2,3}, {4,5,6}, {7,8,9}},
        {{1,2},{3,4}}
    };
    
    int matSize[NUMBER_OF_TESTS] = {3,2};
    int matInSize[NUMBER_OF_TESTS] = {3,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int resultSize = 0;
        int *result = findDiagonalOrder(mat[test], matSize[test], matInSize[test], &resultSize);

        printArr(result, resultSize);

        free(result);

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

int *findDiagonalOrder(int matVar[ARRAY_SIZE][ARRAY_SIZE], int matSizeVar, int matInSizeVar, int *returnSize)
{
    int shifted[ARRAY_SIZE][2 * ARRAY_SIZE] = {{0}};
    int maxShiftedSize = matSizeVar + matInSizeVar - 1;

    for (int i = 0; i < matSizeVar; i++)
    {
        int shiftedInSize = 0;

        for (int j = 0; j < i; j++)
        {
            shifted[i][shiftedInSize++] = 0;
        }

        for (int j = 0; j < matInSizeVar; j++)
        {
            shifted[i][shiftedInSize++] = matVar[i][j];
        }
    }

    int *result = malloc(matSizeVar * matInSizeVar * sizeof(int));
    int resultSize = 0;

    if (result == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    int state = 0;

    for (int i = 0; i < maxShiftedSize; i++)
    {
        if (state == 0)
        {
            for (int j = matSizeVar - 1; j >= 0; j--)
            {
                if (i - j >= 0 && i - j < matInSizeVar)
                {
                    result[resultSize++] = shifted[j][i];
                }
            }
        }
        else
        {
            for (int j = 0; j < matSizeVar; j++)
            {
                if (i - j >= 0 && i - j < matInSizeVar)
                {
                    result[resultSize++] = shifted[j][i];
                }
            }
        }

        state = (state == 0) ? 1 : 0;
    }

    *returnSize = resultSize;
    return result;
}

void printArr(int arr[ARRAY_SIZE], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ","), arr[i], ((i == arrSize - 1) ? "] | " : "")); 
    }
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