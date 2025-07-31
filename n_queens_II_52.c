/* Leetcode - 52. N-Queens II (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void printMatrix(char matrix[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int matrixSize);
void blockPaths(char matrix[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int matrixSize, int row, int col);
int nextQueen(char matrix[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int matrixSize, int row);
void makeMatrixEmpty(char matrix[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int matrixSize);
bool checkRightOutput(char matrix[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int matrixSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 52. N-Queens II (C language) - ");

    red();

    printf("Hard\n");

    char queens[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {};
    int nTest[ARRAY_SIZE] = {4, 1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int n = nTest[test];
        int index_start = 0;
        int index_col;

        bool flag = true;
        int counter_output = 0;

        while (flag)
        {
            flag = false;

            for (int i = 0; i < n; i++)
            {
                if (i == 0)
                {
                    
                    blockPaths(queens[test], n, 0, index_start);
                    strcpy(queens[test][0][index_start], "Q");
                }
                else
                {
                    nextQueen(queens[test], n, i);
                    index_col = nextQueen(queens[test], n, i);

                    if (index_col == 999)
                    {
                        index_col = 0;

                        makeMatrixEmpty(queens[test], n);
                        break;
                    }
                    
                    blockPaths(queens[test], n, i, index_col);
                    strcpy(queens[test][i][index_col], "Q");
                }
            }
            
            if (checkRightOutput(queens[test], n) == true)
            {
                counter_output++;
            }
        
            if (index_start < 5)
            {
                index_start++;
                flag = true;
                makeMatrixEmpty(queens[test], n);
            }
            else
            {
                flag = false;
            }
        }

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", counter_output);

        green();

        printf("Passed\n");

        reset();
    }

    return 0;
}

void printMatrix(char matrix[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int matrixSize)
{
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            printf("%s%s%s", ((j == 0) ? "[" : ""), matrix[i][j], ((j < matrixSize - 1) ? ", " : "]\n"));
        }
    }
}

void blockPaths(char matrix[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int matrixSize, int row, int col)
{
    int copy_row  = row;
    int copy_col = col;

    for (int i = 0; i < matrixSize; i++)
    {
        strcpy(matrix[row][i], "X");
        strcpy(matrix[i][col], "X"); 
    }

    for (int i = 0; i < matrixSize; i++)
    {
        strcpy(matrix[row + i][col + i], "X");
        strcpy(matrix[row + i][col - i], "X");
    }
    
}

int nextQueen(char matrix[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int matrixSize, int row)
{
    for (int i = 0; i < matrixSize; i++)
    {
        if (strcmp(matrix[row][i], "X") != 0)
        {
            return i;
        }
    }

    return 999;
}

void makeMatrixEmpty(char matrix[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int matrixSize)
{
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            strcpy(matrix[i][j], "");
        }
    }
}

bool checkRightOutput(char matrix[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int matrixSize)
{
    int counter = 0;

    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            if (strcmp(matrix[i][j], "Q") == 0)
            {
                counter ++;
            }
        }
    }

    if (counter == matrixSize)
    {
        return true;
    }
    else
    {
        return false;
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
