#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void printMatrix(int matrix[ARRAY_SIZE][ARRAY_SIZE], int matrix_size);
void findObstacleAndPutNegativeOne(int matrix[ARRAY_SIZE][ARRAY_SIZE], int matrix_size);
void oneOnBoundaries(int matrix[ARRAY_SIZE][ARRAY_SIZE], int matrix_size);
void generatePaths(int matrix[ARRAY_SIZE][ARRAY_SIZE], int matrix_size);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 63. Unique Paths II (C language) - Medium\n");

    int obstacleGrid[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {{{0,0,0},{0,1,0},{0,0,0}}, {{0,1},{0,0}}};
    int obstacleGrid_inSize[ARRAY_SIZE] = {3,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        findObstacleAndPutNegativeOne(obstacleGrid[test], obstacleGrid_inSize[test]);
        oneOnBoundaries(obstacleGrid[test], obstacleGrid_inSize[test]);
        generatePaths(obstacleGrid[test], obstacleGrid_inSize[test]);
        
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", obstacleGrid[test][0][0]);

        green();

        printf("Passed\n");

        reset();
    }

    return 0;
}

void printMatrix(int matrix[ARRAY_SIZE][ARRAY_SIZE], int matrix_size)
{
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            printf("%s%i%s", ((j == 0) ? "[" : ""), matrix[i][j], ((j < matrix_size - 1) ? ", " : "]\n"));
        }
    }
}

void findObstacleAndPutNegativeOne(int matrix[ARRAY_SIZE][ARRAY_SIZE], int matrix_size)
{
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            if (matrix[i][j] == 1) 
            {
                matrix[i][j] = -1;
            }
        } 
    }  
}

void oneOnBoundaries(int matrix[ARRAY_SIZE][ARRAY_SIZE], int matrix_size)
{
    for (int i = 0; i < matrix_size; i++)
    {
        if (matrix[i][matrix_size - 1] != -1)
        {
            matrix[i][matrix_size - 1] = 1;
        }
    }

    for (int i = 0; i < matrix_size; i++)
    {
        if (matrix[matrix_size - 1][i] != -1)
        {
            matrix[matrix_size - 1][i] = 1;
        }
    }
}

void generatePaths(int matrix[ARRAY_SIZE][ARRAY_SIZE], int matrix_size)
{
    for (int i = matrix_size - 2; i >= 0; i--)
    {
        for (int j = matrix_size - 2; j >= 0; j--)
        {
            if (matrix[i][j] != -1)
            {
                if (matrix[i + 1][j] != -1 && matrix[i][j + 1] != -1)
                {
                    matrix[i][j] = matrix[i + 1][j] + matrix[i][j + 1];
                }
                else if (matrix[i + 1][j] == -1)
                {
                    matrix[i][j] = 0 + matrix[i][j + 1];
                }
                else if (matrix[i][j + 1] == -1)
                {
                    matrix[i][j] = matrix[i + 1][j] + 0;
                }
            }
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



