/* Leetcode - 62. Unique Paths (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void printMatrixOfInt(int matrix[ARRAY_SIZE][ARRAY_SIZE], int row, int column);
void oneToMargins(int matrix[ARRAY_SIZE][ARRAY_SIZE], int row, int column);
void calculatePaths(int matrix[ARRAY_SIZE][ARRAY_SIZE], int row, int column);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 62. Unique Paths (C language) - Medium\n");

    const int mTest[ARRAY_SIZE] = {3,3};
    const int nTest[ARRAY_SIZE] = {7,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        const int m = mTest[test];
        const int n = nTest[test];

        int matrix[ARRAY_SIZE][ARRAY_SIZE] = {};

        oneToMargins(matrix, m, n);
        calculatePaths(matrix, m, n);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", matrix[0][0]);

        green();

        printf("Passed\n");

        reset();
    }

    return 0;
}

void printMatrixOfInt(int matrix[ARRAY_SIZE][ARRAY_SIZE], int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%s%i%s", ((j == 0) ? "[" : ""), matrix[i][j], ((j < column - 1) ? ", " : "]\n"));
        }
    }
}

void oneToMargins(int matrix[ARRAY_SIZE][ARRAY_SIZE], int row, int column)
{
    for (int i = 0; i < column; i++)
    {
        matrix[row - 1][i] = 1;
    }

    for (int i = 0; i < row; i++)
    {
        matrix[i][column - 1] = 1;
    }
}

void calculatePaths(int matrix[ARRAY_SIZE][ARRAY_SIZE], int row, int column)
{
    for (int i = row - 2; i >= 0; i--)
    {
        for (int j = column - 2; j >= 0; j--)
        {
            matrix[i][j] = matrix[i][j + 1] + matrix[i + 1][j];
        }
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