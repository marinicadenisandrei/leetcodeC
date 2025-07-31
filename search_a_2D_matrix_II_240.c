/* Leetcode - 240. Search a 2D Matrix II (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

bool searchMatrix(int matrixVar[ARRAY_SIZE][ARRAY_SIZE], int matrixVarSize, int matrixVarInSize, int targetVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 240. Search a 2D Matrix II (C language) - Medium\n");

    int matrix[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE] = {{{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}},
    {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}}}; 

    int matrixSize[NUMBER_OF_TESTS] = {5,5};
    int matrixInSize[NUMBER_OF_TESTS] = {5,5};
    int target[NUMBER_OF_TESTS] = {5,20};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", (searchMatrix(matrix[test], matrixSize[test], matrixInSize[test], target[test]) ? "true" : "false"));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

bool searchMatrix(int matrixVar[ARRAY_SIZE][ARRAY_SIZE], int matrixVarSize, int matrixVarInSize, int targetVar)
{
    for (int i = 0; i < matrixVarSize; i++)
    {
        for (int j = 0; j < matrixVarInSize; j++)
        {
            if (matrixVar[i][j] == targetVar)
            {
                return true;
            }
        }
    }
    
    return false;
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