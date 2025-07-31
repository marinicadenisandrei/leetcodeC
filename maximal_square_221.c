/* Leetcode - 221. Maximal Square (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3
#define CHAR_SIZE 2

int maximalSquare(char matrixVar[ARRAY_SIZE][ARRAY_SIZE][CHAR_SIZE], int matrixVarSize, int matrixVarInSize);
bool checkZeroes(char matrixVar[ARRAY_SIZE][ARRAY_SIZE][CHAR_SIZE], int topLeft, int topRight, int end);
int min(int a, int b);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 221. Maximal Square (C language) - Medium\n");

    char matrix[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE][CHAR_SIZE] = {{{"1","0","1","0","0"},{"1","0","1","1","1"},{"1","1","1","1","1"},{"1","0","0","1","0"}}, {{"0","1"},{"1","0"}},{{"0"}}};
    int matrixSize[NUMBER_OF_TESTS] = {4,2,1};
    int matrixInSize[NUMBER_OF_TESTS] = {5,2,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", maximalSquare(matrix[test], matrixSize[test], matrixInSize[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int min(int a, int b)
{
    return ((a < b) ? a : b);
}

bool checkZeroes(char matrixVar[ARRAY_SIZE][ARRAY_SIZE][CHAR_SIZE], int topLeft, int topRight, int end)
{
    for (int i = topLeft; i <= end; i++)
    {
        for (int j = topLeft; j <= topRight; j++)
        {
            if (strcmp(matrixVar[i][j], "0") == 0)
            {
                return false;
            }
        }
    }

    return true;
}

int maximalSquare(char matrixVar[ARRAY_SIZE][ARRAY_SIZE][CHAR_SIZE], int matrixVarSize, int matrixVarInSize)
{
    int maxVar = 0;

    for (int i = 0; i < matrixVarSize; i++)
    {
        for (int j = 0; j < matrixVarInSize; j++)
        {
            if (strcmp(matrixVar[i][j], "1") == 0)
            {
                int start_left = i;
                int end_left = 0;
                int end_bottom = 0;

                int c1 = 0;
                int c2 = 0;

                for (int k = j; k < matrixVarInSize; k++)
                {
                    c1++;

                    if (strcmp(matrixVar[i][k], "0") == 0)
                    {
                        end_left = k - 1;
                        break;
                    }
                    else if (k == matrixVarInSize - 1)
                    {
                        end_left = k;
                        break;
                    }
                }

                for (int k = i; k < matrixVarSize; k++)
                {
                    c2++;

                    if (strcmp(matrixVar[k][j], "0") == 0)
                    {
                        end_bottom = k - 1;
                        break;
                    }
                    else if (k == matrixVarSize - 1)
                    {
                        end_bottom = k;
                        break;
                    }
                }

                if (checkZeroes(matrixVar, start_left, end_left, end_bottom))
                {
                    maxVar = ((maxVar < ((min(c1, c2) * 2))) ? (min(c1, c2) == 1 ? 1 : min(c1, c2) * 2) : maxVar);
                    
                }
            }
        }
    }

    return maxVar;
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