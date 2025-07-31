/* Leetcode - 102. Binary Tree Level Order Traversal (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE 20
#define OUTPUT_LENGTH 0
#define NUMBER_OF_TESTS 3

int outputInSizes[ARRAY_SIZE] = {};
int outputBigSize = 0;

int** levelOrder(int *rootVar, int rootVarSize);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 102. Binary Tree Level Order Traversal (C language) - Medium\n");

    int root[ARRAY_SIZE][ARRAY_SIZE] = {{3,9,20,0,0,15,7}, {1}, {0}};
    int rootSize[ARRAY_SIZE] = {7,1,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int **output = (int **)malloc(outputBigSize * sizeof(int *));
        for (int i = 0; i < outputBigSize; i++)
        {
            output[i] = (int *)malloc(ARRAY_SIZE * sizeof(int));
        }

        output = levelOrder(root[test], rootSize[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("[");

        for (int i = 0; i < outputBigSize; i++)
        {
            printArray(output[i], outputInSizes[i]);
        }

        printf("] | ");

        green();

        printf("Passed\n");

        for (int i = 0; i < outputBigSize; i++)
        {
            free(output[i]);
        }

        free(output);
    }

    reset();

    return 0;
}

void printArray(int *array, int arraySize)
{
    if (array[0] == 0 && arraySize == 1)
    {
        printf("[]");
        return;
    }
    
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "]"));
    }
}

int** levelOrder(int *rootVar, int rootVarSize)
{
    int depth = 0;
    int power = 1;
    int starter = rootVarSize;

    while (starter > 0)
    {
        starter -= power;
        power *= 2;
        depth++;
    }

    outputBigSize = depth;

    int **matrix = (int **)malloc(depth * sizeof(int *));
    for (int i = 0; i < depth; i++)
    {
        matrix[i] = (int *)malloc(ARRAY_SIZE * sizeof(int));
    }

    starter = 1;

    matrix[0][0] = rootVar[0];
    outputInSizes[0] = 1;

    int indexVar = 0;

    for (int i = 1; i < depth; i++)
    {
        for (int j = starter; j <= starter * 2; j++)
        {
            if (rootVar[j] != 0)
            {
                matrix[i][indexVar] = rootVar[j];
                indexVar++;
            }
        }

        outputInSizes[i] = indexVar;
        indexVar = 0;

        starter *= 2;
        starter += 1;
    }

    return matrix;
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