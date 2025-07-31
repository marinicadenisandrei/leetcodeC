/* Leetcode - 85. Maximal Rectangle (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define CHARACTER_ARRAY 2
#define NUMBER_OF_TESTS 3

int maximalRectangle(const char matrixVar[ARRAY_SIZE][ARRAY_SIZE][CHARACTER_ARRAY],const int matrixSize, const int matrixInSize);
void printMatrixOfChars(const char matrixVar[ARRAY_SIZE][ARRAY_SIZE][CHARACTER_ARRAY], const int matrixSize, const int matrixInSize);
int sumOfElements(const char matrixVar[ARRAY_SIZE][ARRAY_SIZE][CHARACTER_ARRAY], int startRow, int endRow, int startCol, int endCol);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{   
    yellow();

    printf("Leetcode - 85. Maximal Rectangle (C language) - ");

    red();

    printf("Hard\n");

    char matrix[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE][CHARACTER_ARRAY] = {{{"1","0","1","0","0"},{"1","0","1","1","1"},{"1","1","1","1","1"},{"1","0","0","1","0"}}, {{"0"}}, {{"1"}}};

    int matrixSize[ARRAY_SIZE] = {4, 1, 1};
    int matrixInSize[ARRAY_SIZE] = {5, 1, 1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int result = maximalRectangle(matrix[test], matrixSize[test], matrixInSize[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", result);

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

int sumOfElements(const char matrixVar[ARRAY_SIZE][ARRAY_SIZE][CHARACTER_ARRAY], int startRow, int endRow, int startCol, int endCol)
{
    int sum = 0;

    for (int i = startRow; i <= endRow; i++)
    {
        for (int j = startCol; j <= endCol; j++)
        {
            if (matrixVar[i][j][0] == '1')
            {
                sum += 1;
            }
            else
            {
                return 0;
            }
        }
    }

    return sum;
}

void printMatrixOfChars(const char matrixVar[ARRAY_SIZE][ARRAY_SIZE][CHARACTER_ARRAY], const int matrixSize, const int matrixInSize)
{
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixInSize; j++)
        {
            printf("%s%s%s", ((j == 0) ? "[" : ""), matrixVar[i][j], ((j < matrixInSize - 1) ? ", " : "]\n"));
        }
    }
}

int maximalRectangle(const char matrixVar[ARRAY_SIZE][ARRAY_SIZE][CHARACTER_ARRAY],const int matrixSize, const int matrixInSize)
{
    int max = 0;
    int row_end = 0;
    int col_end = 0;

    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixInSize; j++)
        {
            if (matrixVar[i][j][0] == '1')
            {
                int endi = 0;
                int endj = 0;

                for (int k = j; k < matrixSize; k++)
                {
                    if (matrixVar[k][j][0] != '1')
                    {
                        endi = k - 1;
                        break;
                    }

                    if (k == matrixSize - 1)
                    {
                        endi = matrixSize - 1;
                    }
                }

                for (int k = j; k < matrixInSize; k++)
                {
                    if (matrixVar[i][k][0] != '1')
                    {
                        endj = k - 1;
                        break;
                    }

                    if (k == matrixInSize - 1)
                    {
                        endj = matrixInSize - 1;
                    }
                }

                max = ((sumOfElements(matrixVar, i, endi, j, endj) > max ? sumOfElements(matrixVar, i, endi, j, endj) : max));  
            }
        }
    }   

    return max;
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