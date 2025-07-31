/* Leetcode - 79. Word Search (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void printMatrixChar(char matrix[ARRAY_SIZE][ARRAY_SIZE], int matrixSize, int matrixInSize);
bool exist(char matrix[ARRAY_SIZE][ARRAY_SIZE], int matrixSize, int matrixInSize, char word[ARRAY_SIZE]);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 79. Word Search (C language) - Medium\n");

    char board[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {
        {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}},
        {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}},
        {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}}};

    char word[ARRAY_SIZE][ARRAY_SIZE] = {"ABCCED", "SEE", "ABCB"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        bool result = exist(board[test], 3, 4, word[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s%s", ((result == true) ? "true" : "false"), " | ");

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

void printMatrixChar(char matrix[ARRAY_SIZE][ARRAY_SIZE], int matrixSize, int matrixInSize)
{
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixInSize; j++)
        {
            printf("%s%c%s", ((j == 0) ? "[" : ""), matrix[i][j], ((j < matrixInSize - 1) ? ", " : "]\n"));
        }
    }   
}

bool exist(char matrix[ARRAY_SIZE][ARRAY_SIZE], int matrixSize, int matrixInSize, char word[ARRAY_SIZE])
{
    bool flag = false;

    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixInSize; j++)
        {
            if (matrix[i][j] == word[0])
            {
                int row = i;
                int col = j;

                matrix[row][col] = 'X';

                for (int k = 1; k < strlen(word); k++)
                {
                    if (word[k] == matrix[row][col - 1])
                    {
                        col -= 1;
                    }
                    else if (word[k] == matrix[row][col + 1])
                    {
                        col += 1;
                    }
                    else if (word[k] == matrix[row + 1][col])
                    {
                        row += 1;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }

                    flag = true;

                    matrix[row][col] = 'X';
                }
            }
        }

        if (flag)
        {
            break;
        }
            
    }

    return flag;
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