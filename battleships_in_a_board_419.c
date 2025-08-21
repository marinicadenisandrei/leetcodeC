/* Leetcode - 419. Battleships in a Board (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int countBattleships(char boardVar[ARRAY_SIZE][ARRAY_SIZE][2], int boardSizeVar, int boardInSizeVar);

int main()
{
    yellow();

    printf("Leetcode - 419. Battleships in a Board (C language) - Medium\n");

    char board[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE][2] = {{{"X",".",".","X"},{".",".",".","X"},{".",".",".","X"}}, {{"."}}};
    int boardSize[NUMBER_OF_TESTS] = {3,1};
    int boardInSize[NUMBER_OF_TESTS] = {4,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", countBattleships(board[test], boardSize[test], boardInSize[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int countBattleships(char boardVar[ARRAY_SIZE][ARRAY_SIZE][2], int boardSizeVar, int boardInSizeVar)
{
    int battleshipsCounter = 0;

    for (int i = 0; i < boardSizeVar; i++)
    {
        for (int j = 0; j < boardInSizeVar; j++)
        {
            if (boardVar[i][j][0] == 'X')
            {
                battleshipsCounter++;

                for (int k = j; k < boardInSizeVar && boardVar[i][k]; k++)
                {
                    boardVar[i][k][0] = '.';
                }
                
                for (int k = i; k < boardSizeVar && boardVar[k][j]; k++)
                {
                    boardVar[k][j][0] = '.';
                }
            }   
        }
    }

    return battleshipsCounter;
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