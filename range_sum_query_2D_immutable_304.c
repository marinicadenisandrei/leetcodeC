/* Leetcode - 304. Range Sum Query 2D - Immutable (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

void reset ();
void green ();
void yellow ();
void red ();

typedef struct {
    int *matrix;
    int matrixSize;
    int matrixColSize;
} NumMatrix;

NumMatrix* createNumMatrix(int **matrix, int matrixSize, int matrixColSize)
{
    NumMatrix *numMatrix = (NumMatrix *)malloc(sizeof(NumMatrix));
    numMatrix->matrixSize = matrixSize;
    numMatrix->matrixColSize = matrixColSize;

    numMatrix->matrix = (int *)malloc(matrixSize * matrixColSize * sizeof(int));

    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixColSize; j++)
        {
            numMatrix->matrix[i * matrixColSize + j] = matrix[i][j];
        }
    }
    
    return numMatrix;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    int sumVar = 0;

    for (int i = row1; i <= row2; i++) 
    {
        for (int j = col1; j <= col2; j++) 
        {
            sumVar += obj->matrix[i * obj->matrixColSize + j];
        }
    }

    return sumVar;
}

int main()
{
    yellow();

    printf("Leetcode - 304. Range Sum Query 2D - Immutable (C language) - Medium\n");

    int matrixArray[5][5] = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };

    int rows = 5;
    int cols = 5;

    int **matrix = (int**)malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = matrixArray[i][j];
        }        
    }
    
    NumMatrix *numMatrix = createNumMatrix(matrix, rows, cols);

    green();

    printf("Test 1: ");

    reset();

    printf("%d, ", numMatrixSumRegion(numMatrix, 2, 1, 4, 3));
    printf("%d, ", numMatrixSumRegion(numMatrix, 1, 1, 2, 2));
    printf("%d | ", numMatrixSumRegion(numMatrix, 1, 2, 2, 4));

    green();

    printf("Passed\n");

    reset();

    return 0;
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