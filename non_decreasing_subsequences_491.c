/* Leetcode - 491. Non-decreasing Subsequences (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 100
#define NUMBER_OF_TESTS 2

int arrayExists(int **matrix, int *matrixInSize, int matrixSize, int *array, int arraySize);
int isNonDecreasing(int *array, int arraySize);
void findSubsequences(int *numsVar, int numsSizeVar, int **matrix, int *matrixInSize, int *matrixSize);
int **func(int *numsVar, int numsSizeVar, int *returnSize, int **returnColumnSizes);
void printMarix(int** matrix, int matrixSize, int* matrixInSize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 491. Non-decreasing Subsequences (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{4,6,7,7},{4,4,3,2,1}};
    int numsSize[NUMBER_OF_TESTS] = {4,5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int matrixSize = 0;
        int *matrixInSize = NULL;
        int **matrix = func(nums[test],
                            numsSize[test],
                            &matrixSize,
                            &matrixInSize);

        printMarix(matrix, matrixSize, matrixInSize);

        for (int i = 0; i < ARRAY_SIZE; i++) { free(matrix[i]); }
        free(matrix);
        free(matrixInSize);

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int arrayExists(int **matrix,
                int *matrixInSize,
                int matrixSize,
                int *array,
                int arraySize)
{
    for (int i = 0; i < matrixSize; i++)
    {
        if (matrixInSize[i] != arraySize)
        {
            continue;
        }

        int same = 1;

        for (int j = 0; j < arraySize; j++)
        {
            if (matrix[i][j] != array[j])
            {
                same = 0;
                break;
            }
        }

        if (same == 1)
        {
            return 1;
        }
    }

    return 0;
}

int isNonDecreasing(int *array, int arraySize)
{
    for (int i = 1; i < arraySize; i++)
    {
        if (array[i] < array[i - 1])
        {
            return 0;
        }
    }

    return 1;
}

void findSubsequences(int *numsVar,
                   int numsSizeVar,
                   int **matrix,
                   int *matrixInSize,
                   int *matrixSize)
{
    if (numsSizeVar < 2)
    {
        return;
    }

    for (int k = 0; k < numsSizeVar - 1; k++)
    {
        for (int i = k + 1; i < numsSizeVar; i++)
        {
            int tempArray[ARRAY_SIZE];
            int tempSize = 0;


            for (int j = k; j <= i; j++)
            {
                tempArray[tempSize++] = numsVar[j];
            }

            if (isNonDecreasing(tempArray, tempSize))
            {
                if (!arrayExists(matrix,
                                 matrixInSize,
                                 *matrixSize,
                                 tempArray,
                                 tempSize))
                {
                    for (int j = 0; j < tempSize; j++)
                    {
                        matrix[*matrixSize][j] = tempArray[j];
                    }

                    matrixInSize[*matrixSize] = tempSize;

                    (*matrixSize)++;
                }
            }
        }
    }

    if (numsSizeVar > 2)
    {
        int newNums[ARRAY_SIZE];
        int newSize = 0;

        newNums[newSize++] = numsVar[0];

        for (int i = 2; i < numsSizeVar; i++)
        {
            newNums[newSize++] = numsVar[i];
        }


        findSubsequences(newNums,
                      newSize,
                      matrix,
                      matrixInSize,
                      matrixSize);
    }
}


int **func(int *numsVar,
           int numsSizeVar,
           int *returnSize,
           int **returnColumnSizes)
{
    int **matrix = malloc(ARRAY_SIZE * sizeof(int *));
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        matrix[i] = malloc(ARRAY_SIZE * sizeof(int));
    }
    int *matrixInSize = malloc(ARRAY_SIZE * sizeof(int));

    *returnSize = 0;

    findSubsequences(numsVar,
                  numsSizeVar,
                  matrix,
                  matrixInSize,
                  returnSize);


    *returnColumnSizes = matrixInSize;

    return matrix;
}

void printMarix(int **matrix, int matrixSize, int *matrixInSize)
{
    printf("[");

    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixInSize[i]; j++)
        {
            printf("%s%d%s",
                   ((j == 0) ? "[" : ", "),
                   matrix[i][j],
                   ((j == matrixInSize[i] - 1) ? "]" : ""));
        }

        printf("%s", ((i == matrixSize - 1) ? "" : ", "));
    }

    printf("] | ");
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