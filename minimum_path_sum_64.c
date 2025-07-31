// Leetcode - 64. Minimum Path Sum (C language) - Medium

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void printMatrix(int matrix[ARRAY_SIZE][ARRAY_SIZE], int size_out, int size_in);
int returnMinSum(int matrix[ARRAY_SIZE][ARRAY_SIZE], int row, int col, int sum);
int minOfTwoInt(int a, int b);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 64. Minimum Path Sum (C language) - Medium\n");

    int grid[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {{{1,3,1},{1,5,1},{4,2,1}},{{1,2,3},{4,5,6}}};
    int grid_out_size[ARRAY_SIZE] = {3, 2};
    int grid_in_size[ARRAY_SIZE] = {3, 3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int sum = grid[test][grid_out_size[test] - 1][grid_in_size[test] - 1];
        int minSum = returnMinSum(grid[test], grid_out_size[test] - 1, grid_in_size[test] - 1, sum);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", minSum);

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
            printf("%s%i%s", ((j == 0) ? "[" : ""), matrix[i][j], (j < size_in - 1) ? ", " : "]");
        }

        printf("\n");
    }
}

int minOfTwoInt(int a, int b)
{
    if (a < b)
    {
        return a;
    }

    return b;
}

int returnMinSum(int matrix[ARRAY_SIZE][ARRAY_SIZE], int row, int col, int sum)
{
    if (row != 0 && col != 0)
    {
        int min = minOfTwoInt(matrix[row - 1][col], matrix[row][col - 1]);
        sum += min;

        if (min == matrix[row - 1][col])
        {
            return returnMinSum(matrix, row - 1, col, sum);
        }
        else
        {
            return returnMinSum(matrix, row, col - 1, sum);
        }
    }
    
    else if (row == 0)
    {
        for (int i = col - 1; i >= 0; i--)
        {
            sum += matrix[0][i];
        } 

        return sum;
    }    
    else if (col == 0)
    {
        for (int i = row - 1; i >= 0; i--)
        {
            sum += matrix[i][0];
        }

        return sum;
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