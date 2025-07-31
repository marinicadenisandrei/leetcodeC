/* Leetcode - 329. Longest Increasing Path in a Matrix (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int longestIncreasingPath(int matrixVar[ARRAY_SIZE][ARRAY_SIZE], int matrixVarSize, int matrixVarInSize);

int main()
{   
    yellow();

    printf("Leetcode - 329. Longest Increasing Path in a Matrix (C language) - ");

    red();

    printf("Hard\n");

    int matrix[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE] = {{{9,9,4},{6,6,8},{2,2,1}},{{3,4,5},{3,2,6},{2,2,1}}};
    int matrixSize[NUMBER_OF_TESTS] = {3,3};
    int matrixInSize[NUMBER_OF_TESTS] = {3,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", longestIncreasingPath(matrix[test], matrixSize[test], matrixInSize[test]));

        green();

        printf("Passed\n");
    }
    
    reset();
    
    return 0;
}

int longestIncreasingPath(int matrixVar[ARRAY_SIZE][ARRAY_SIZE], int matrixVarSize, int matrixVarInSize)
{
    int i = matrixVarSize - 1;
    int j = matrixVarInSize - 1;
    int counter = 0;

    while (i > 0 && j > 0)
    {
        if (matrixVar[i - 1][j] < matrixVar[i][j - 1])
        {
            i--;
            counter++;
        }
        else
        {
            j--;
            counter++;
        }
    }

    if (i == 0)
    {
        for (int k = j; k > 0; k--)
        {
            if (matrixVar[i][k] <= matrixVar[i][k - 1])
            {
                counter++;
            }
            
        }
    }
    else
    {
        for (int k = i; k > 0; k--)
        {
            if (matrixVar[k][j] <= matrixVar[k - 1][j])
            {
                counter++;
            }
        }
    }

    return counter;
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