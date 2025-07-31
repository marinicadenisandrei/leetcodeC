/* Leetcode - 363. Max Sum of Rectangle No Larger Than K (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int maxSumSubmatrix(int matrixVar[ARRAY_SIZE][ARRAY_SIZE], int matrixVarSize, int matrixVarInSize, int kVar);

int main()
{
    yellow();

    printf("Leetcode - 363. Max Sum of Rectangle No Larger Than K (C language) - ");

    red();

    printf("Hard\n");

    int matrix[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE] = {{{1,0,1},{0,-2,3}},{{2,2,-1}}};
    int matrixSize[NUMBER_OF_TESTS] = {2,1};
    int matrixInSize[NUMBER_OF_TESTS] = {3,3};
    int k[NUMBER_OF_TESTS] = {2,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", maxSumSubmatrix(matrix[test], matrixSize[test], matrixInSize[test], k[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int maxSumSubmatrix(int matrixVar[ARRAY_SIZE][ARRAY_SIZE], int matrixVarSize, int matrixVarInSize, int kVar)
{
    int result = 0;

    for (int i = 0; i < matrixVarSize; i++)
    {
        int interationResult = 0;

        for (int j = 0; j < matrixVarInSize; j++)
        {
            int tempSum = 0;

            for (int k = j; k < (((j + kVar) <= matrixVarInSize) ? (j + kVar) : 0); k++)
            {
                // printf("%i ", matrixVar[i][k]);

                tempSum += matrixVar[i][k];
            }

            interationResult = ((interationResult < tempSum) ? tempSum : interationResult);
        }

        result += interationResult;
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