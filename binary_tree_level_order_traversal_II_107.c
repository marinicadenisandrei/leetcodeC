#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int resultSize = 0;
int resultSizeArray[ARRAY_SIZE] = {0};

int ** levelOrderBottom(int *rootVar, int rootVarSize);
int rootVarDepth(int *rootVar, int rootVarSize);
void printMatrix(int **matrix, int matrixSize, int *matrixInSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 107. Binary Tree Level Order Traversal II (C language) - Medium\n");

    int root[ARRAY_SIZE][ARRAY_SIZE] = {{3,9,20,0,0,15,7}, {1}, {}};
    int rootSize[ARRAY_SIZE] = {7,1,0};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int **result = levelOrderBottom(root[test], rootSize[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printMatrix(result, resultSize, resultSizeArray);

        green();

        printf("Passed\n");

        for (int i = 0; i < ARRAY_SIZE; i++) 
        {
            free(result[i]); 
        }

        free(result);

        resultSize = 0;
    }

    reset();
    
    return 0;
}

void printMatrix(int **matrix, int matrixSize, int *matrixInSize)
{
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixInSize[i]; j++)
        {
            printf("%s%i%s", ((j == 0) ? "[" : ""), matrix[i][j], ((j < matrixInSize[i] - 1)) ? ", " : "]");
        }
    }

    printf(" | ");
}

int rootVarDepth(int *rootVar, int rootVarSize)
{
    int power = 1;

    while (rootVarSize > 0)
    {
        rootVarSize -= pow(2,power);
        power++;
    }

    return power - 1;    
}

int ** levelOrderBottom(int *rootVar, int rootVarSize)
{   
    int **output = (int **) malloc(ARRAY_SIZE * sizeof(int *));
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        output[i] = (int *) malloc(ARRAY_SIZE * sizeof(int));
    }
    
    int index = rootVarDepth(rootVar, rootVarSize);

    while ((index * 2) > 1)
    {
        resultSizeArray[resultSize] = 0;

        for (int i = index; i <= index * 2; i++)
        {
            if (rootVar[i] != 0)
            {
                output[resultSize][resultSizeArray[resultSize]] = rootVar[i];
                resultSizeArray[resultSize]++;
            }
        }

        resultSize++;

        index--;
        index /= 2;
    }


    output[resultSize][0] = rootVar[0];
    resultSizeArray[resultSize] = 1;
    resultSize++;

    return output;
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