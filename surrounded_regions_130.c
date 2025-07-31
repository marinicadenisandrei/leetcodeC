/* Leetcode - 130. Surrounded Regions (C language) - Medium */ 

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void solve(char boardVar[][ARRAY_SIZE], int boardVarSize, int boardVarColSize);
void printMatrixOfChars(char matrix[][ARRAY_SIZE], int matrixSize, int matrixColSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 130. Surrounded Regions (C language) - Medium\n");

    char board[][ARRAY_SIZE][ARRAY_SIZE] = {{{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}}, {{'X'}}};
    int boardSize[ARRAY_SIZE] = {4,1};
    int boardColSize[ARRAY_SIZE] = {4,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        solve(board[test], boardSize[test], boardColSize[test]);
        printMatrixOfChars(board[test], boardSize[test], boardColSize[test]);

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

void printMatrixOfChars(char matrix[][ARRAY_SIZE], int matrixSize, int matrixColSize)
{
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixColSize; j++)
        {
            printf("%s%c%s", ((j == 0) ? "[" : ""), matrix[i][j], ((j < matrixColSize - 1) ? ", " : "]"));
        }
    }

    printf(" | ");
}

void solve(char boardVar[][ARRAY_SIZE], int boardVarSize, int boardVarColSize)
{
    for (int i = 1; i < boardVarSize - 1; i++)
    {
        for (int j = 1; j < boardVarColSize - 1; j++)
        {
            if (boardVar[i][j] == 'O' && boardVar[i + 1][j] == 'X' || boardVar[i - 1][j] == 'X' || boardVar[i][j - 1] == 'X' || boardVar[i][j - 1] == 'X')
            {
                boardVar[i][j] = 'X';
            }
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