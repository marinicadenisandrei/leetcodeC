/* Leetcode - 51. N-Queens (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void printMatrixOfChars(char matrix[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int matrixSize);
void blockIndex(char matrix[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int matrixSize, int row, int col);
void makeMatrixEmpty(char matrix[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int matrixSize);
int checkForQueens(char matrix[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int matrixSize, int counter_queens);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 51. N-Queens (C language) - ");

    red();

    printf("Hard\n");

    int nTest[ARRAY_SIZE] = {4, 1};
    char queens[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        bool flag = true;
        bool flag_exit = false;
        int col_start = 0;

        int n = nTest[test];

        while (flag)
        {
            flag = false;

            for (int i = 0; i < n; i++)
            {
                flag = false;
                if (i == 0)
                {
                    blockIndex(queens[test], n, 0, col_start);
                    strcpy(queens[test][0][col_start], "Q");
                }
                else
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (strcmp(queens[test][i][j], "") == 0)
                        {
                            blockIndex(queens[test], n, i, j);
                            strcpy(queens[test][i][j], "Q");
                            flag = true;
                            break;
                        }
                    }

                    if (flag == false)
                    {
                        flag_exit = true;
                        flag = true;
                        break;
                    }
                }
            }

            col_start++;
            flag_exit = false;
            
            if (checkForQueens(queens[test], n, n) > 0)
            {
                makeMatrixEmpty(queens[test], n);
                flag = true;
            }
            else
            {
                flag = false;
                break;
            }
        }

        green();

        printf("Test %i: ", test + 1);

        reset();

        printMatrixOfChars(queens[test], n);
        printf(" | ");

        green();

        printf("Passed\n");

        reset();
    }
    
    return 0;
}

void printMatrixOfChars(char matrix[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int matrixSize)
{
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            printf("%s%s%s", ((j == 0) ? "[" : ""), matrix[i][j], ((j < matrixSize - 1) ? ", " : "]"));
        }
    }
}

void blockIndex(char matrix[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int matrixSize, int row, int col)
{
    int copy_row = row;
    int copy_col = col;

    for (int i = 0; i < matrixSize; i++)
    {
        strcpy(matrix[row][i], "X");
        strcpy(matrix[i][col], "X");
    }

    for (int i = 0; i < matrixSize; i++)
    {
        strcpy(matrix[row][col], "X");
        strcpy(matrix[row][copy_col], "X");
        row++;
        col++;
        copy_col--;
    }
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

int checkForQueens(char matrix[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int matrixSize, int counter_queens)
{
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            if (strcmp(matrix[i][j],"Q") == 0)
            {
                counter_queens--;
            }
        }
    }
    return counter_queens;
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