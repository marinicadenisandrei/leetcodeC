/* Leetcode - 59. Spiral Matrix II (C language) - Medium */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

struct history_row_column
{
    int row;
    int column;
};

void printMatrixOfIntegers(int matrix[ARRAY_SIZE][ARRAY_SIZE], int matrix_size);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 59. Spiral Matrix II (C language) - Medium\n");

    int nTest[ARRAY_SIZE] = {3, 1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int n = nTest[test];
        int n_copy = n;
        int matrix[ARRAY_SIZE][ARRAY_SIZE] = {};

        int row_var = 0;
        int col_var = n - 1;
        int factor = 0;

        struct history_row_column output[ARRAY_SIZE] = {};
        int size_output = 0;

        while (n > 0)
        {
            for (int i = 0 + factor; i < n; i++)
            {
                output[size_output].row = row_var;
                output[size_output].column = i;
                size_output++;
            }

            for (int i = 1 + factor; i <= n - 1; i++)
            {
                output[size_output].row = i;
                output[size_output].column = col_var;
                size_output++;
            }

            for (int i = n - 2; i >= 0 + factor; i--)
            {
                output[size_output].row = col_var;
                output[size_output].column = i;
                size_output++;
            }

            for (int i = n - 2 - factor; i > 0 + factor; i--)
            {
                output[size_output].row = i;
                output[size_output].column = row_var;
                size_output++;
            }
            
            row_var++;
            col_var--;
            factor++;
            n--;
        }

        for (int i = 0; i < size_output; i++)
        {
            matrix[output[i].row][output[i].column] = i + 1;
        }

        green();

        printf("Test %i: ", test + 1);

        reset();

        printMatrixOfIntegers(matrix, n_copy);

        green();

        printf("Passed\n");

        reset();
    }
    
    return 0;
}

void printMatrixOfIntegers(int matrix[ARRAY_SIZE][ARRAY_SIZE], int matrix_size)
{
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            printf("%s%i%s%s", ((j == 0) ? "[" : ""), matrix[i][j], ((j < matrix_size - 1) ? ", " : "]"), ((i == matrix_size - 1 && j == matrix_size - 1) ? " | " : ""));
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
