/* Leetcode - 73. Set Matrix Zeroes (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void printMatrix(int matrix[ARRAY_SIZE][ARRAY_SIZE], int size_out, int size_in);
void setMatrixZero(int matrix[ARRAY_SIZE][ARRAY_SIZE], int size_out, int size_in);
void setZeros(int matrix[ARRAY_SIZE][ARRAY_SIZE], int size_out, int size_in, int row, int column);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 73. Set Matrix Zeroes (C language) - Medium\n");

    int matrix[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {{{1,1,1},{1,0,1},{1,1,1}}, {{0,1,2,0},{3,4,5,2},{1,3,1,5}}};

    int size_out_array[ARRAY_SIZE] = {3,3};
    int size_in_array[ARRAY_SIZE] = {3,4};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        setMatrixZero(matrix[test], size_out_array[test], size_in_array[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printMatrix(matrix[test], size_out_array[test], size_in_array[test]);

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

void printMatrix(int matrix[ARRAY_SIZE][ARRAY_SIZE], int size_out, int size_in)
{
    for (int i = 0; i < size_out; i++)
    {
        for (int j = 0; j < size_in; j++)
        {
            printf("%s%i%s", ((j == 0) ? "[" : ""), matrix[i][j], ((j < size_in - 1) ? ", " : "]"));
        }
    }

    printf(" | ");
}

void setMatrixZero(int matrix[ARRAY_SIZE][ARRAY_SIZE], int size_out, int size_in)
{
    int tempArray[ARRAY_SIZE] = {};
    int sizeTempArray = 0;

    for (int i = 0; i < size_out; i++)
    {
        for (int j = 0; j < size_in; j++)
        {
            if (matrix[i][j] == 0)
            {
                tempArray[sizeTempArray] = i;
                tempArray[sizeTempArray + 1] = j;

                sizeTempArray += 2;
            }
        }
    }

    for (int i = 0; i < sizeTempArray; i+=2) setZeros(matrix, size_out, size_in, tempArray[i], tempArray[i+1]);
}

void setZeros(int matrix[ARRAY_SIZE][ARRAY_SIZE], int size_out, int size_in, int row, int column)
{
    for (int i = 0; i < size_in; i++)
    {
        matrix[row][i] = 0;
    }

    for (int i = 0; i < size_out; i++)
    {
        matrix[i][column] = 0;
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