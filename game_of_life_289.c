/* Leetcode - 289. Game of Life (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int** gameOfLife(int boardVar[ARRAY_SIZE][ARRAY_SIZE], int boardSizeVar, int boardInSize);
int validateIndex(int iVar, int jVar, int bigSize, int inSize);
void printTwoDArray(int **array, int arraySize, int arrayInSize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 289. Game of Life (C language) - Medium\n");

    int board[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE] = {{{0,1,0},{0,0,1},{1,1,1},{0,0,0}},{{1,1},{1,0}}};
    int boardSize[NUMBER_OF_TESTS] = {4,2};
    int boardInSize[NUMBER_OF_TESTS] = {3,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int **result = gameOfLife(board[test], boardSize[test], boardInSize[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printTwoDArray(result, boardSize[test], boardInSize[test]);

        green();

        printf("Passed \n");

        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            free(result[i]);
        }

        free(result);
    }

    reset();
  
    return 0;
}

void printTwoDArray(int **array, int arraySize, int arrayInSize)
{
    printf("[");

    for (int i = 0; i < arraySize; i++)
    {
        for (int j = 0; j < arrayInSize; j++)
        {
            printf("%s%i%s", ((j == 0) ? "[" : ""), array[i][j], ((j < arrayInSize - 1) ? ", " : ((i < arrayInSize - 1) ? "] " : "]")));
        }
    }

    printf("] | ");
}

int** gameOfLife(int boardVar[ARRAY_SIZE][ARRAY_SIZE], int boardSizeVar, int boardInSize)
{
    int **newBoard = (int **) malloc(ARRAY_SIZE * sizeof(int *));

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        newBoard[i] = (int*) malloc(ARRAY_SIZE * sizeof(int));
    }
    
    for (int i = 0; i < boardSizeVar; i++)
    {
        for (int j = 0; j < boardInSize; j++)
        {
            newBoard[i][j] = boardVar[i][j];
        }
    }

    for (int i = 0; i < boardSizeVar; i++)
    {
        for (int j = 0; j < boardInSize; j++)
        {
            int A[8] = {0};

            A[0] = ((validateIndex(i - 1, j - 1, boardSizeVar, boardInSize) == 1) ? boardVar[i - 1][j - 1] : -1);
            A[1] = ((validateIndex(i - 1, j, boardSizeVar, boardInSize) == 1) ? boardVar[i - 1][j] : -1);
            A[2] = ((validateIndex(i - 1, j + 1, boardSizeVar, boardInSize) == 1) ? boardVar[i - 1][j + 1] : -1);
            A[3] = ((validateIndex(i, j + 1, boardSizeVar, boardInSize) == 1) ? boardVar[i][j + 1] : -1);
            A[4] = ((validateIndex(i + 1, j + 1, boardSizeVar, boardInSize) == 1) ? boardVar[i + 1][j + 1] : -1);
            A[5] = ((validateIndex(i + 1, j, boardSizeVar, boardInSize) == 1) ? boardVar[i + 1][j] : -1);
            A[6] = ((validateIndex(i + 1, j - 1, boardSizeVar, boardInSize) == 1) ? boardVar[i + 1][j - 1] : -1);
            A[7] = ((validateIndex(i, j - 1, boardSizeVar, boardInSize) == 1) ? boardVar[i][j - 1] : -1);
            
            int count_zero = 0;
            int count_one = 0;

            for (int k = 0; k < 8; k++)
            {
                if (A[k] == 0)
                {
                    count_zero++;
                }

                if (A[k] == 1)
                {
                    count_one++;
                }
            }

            if (boardVar[i][j] == 1 && count_one < 2)
            {
                newBoard[i][j] = 0;
            }
            else if (boardVar[i][j] == 1 && (count_one == 2 || count_one == 3))
            {
                newBoard[i][j] = 1;
            }
            else if (boardVar[i][j] == 1 && count_one > 3)
            {
                newBoard[i][j] = 0;
            }
            else if (boardVar[i][j] == 0 && count_one == 3)
            {
                newBoard[i][j] = 1;
            }
        }   
    }

    return newBoard;
}

int validateIndex(int iVar, int jVar, int bigSize, int inSize)
{
    if (iVar < 0 || iVar > bigSize || jVar < 0 || jVar > inSize)
    {
        return 0;
    }
    
    return 1;
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