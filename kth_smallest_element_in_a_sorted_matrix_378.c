/* Leetcode - 378. Kth Smallest Element in a Sorted Matrix (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int kthSmallest(int matrixVar[ARRAY_SIZE][ARRAY_SIZE], int matrixSizeVar, int matrixInSizeVar, int kVar);

int main()
{
    yellow();

    printf("Leetcode - 378. Kth Smallest Element in a Sorted Matrix (C language) - Medium\n");

    int matrix[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE] = {{{1,5,9},{10,11,13},{12,13,15}},{{-5}}};
    int matrixSize[NUMBER_OF_TESTS] = {3,1};
    int matrixInSize[NUMBER_OF_TESTS] = {3,1};

    int k[NUMBER_OF_TESTS] = {8,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", kthSmallest(matrix[test], matrixSize[test], matrixInSize[test], k[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int kthSmallest(int matrixVar[ARRAY_SIZE][ARRAY_SIZE], int matrixSizeVar, int matrixInSizeVar, int kVar)
{
    int c = 0;

    for (int i = 0; i < matrixSizeVar; i++)
    {
        for (int j = 0; j < matrixInSizeVar; j++)
        {
            if (c == kVar - 1)
            {
                return matrixVar[i][j];
            }
            
            c++;   
        }
    }
    
    return -1;
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