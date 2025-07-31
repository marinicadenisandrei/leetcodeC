/* Leetcode - 138. Copy List with Random Pointer (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define HEAD_IN_SIZE 2
#define NUMBER_OF_TESTS 3

int **copyRandomList(int headVar[][HEAD_IN_SIZE], int headVarSize);
void printMatrix(int **matrix, int matrixSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 138. Copy List with Random Pointer (C language) - Medium\n");

    int head[ARRAY_SIZE][ARRAY_SIZE][HEAD_IN_SIZE] = {{{7,0},{13,0},{11,4},{10,2},{1,0}}, {{1,1},{2,1}}, {{3,0},{3,0},{3,0}}};
    int headSize[ARRAY_SIZE] = {5,2,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int **newList = (int **) malloc(headSize[test] * sizeof(int *));
        for (int i = 0; i < headSize[test]; i++)
        {
            newList[i] = (int *) malloc(HEAD_IN_SIZE * sizeof(int));
        }
        
        newList = copyRandomList(head[test], headSize[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printMatrix(newList, headSize[test]);

        green();

        printf("Passed\n");

        for (int i = 0; i < headSize[test]; i++)
        {
            free(newList[i]);
        }

        free(newList);
    }

    reset();
}

void printMatrix(int **matrix, int matrixSize)
{
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < HEAD_IN_SIZE; j++)
        {
            printf("%s%i%s", ((j == 0) ? "[" : "") ,matrix[i][j] , ((j < HEAD_IN_SIZE - 1) ? ", " : "]")); 
        }
    }

    printf(" | ");
}

int **copyRandomList(int headVar[][HEAD_IN_SIZE], int headVarSize)
{
    int **newList = (int **) malloc(headVarSize * sizeof(int *));

    for (int i = 0; i < headVarSize; i++)
    {
        newList[i] = (int *) malloc(HEAD_IN_SIZE * sizeof(int));
    }

    for (int i = 0; i < headVarSize; i++)
    {
        for (int j = 0; j < HEAD_IN_SIZE; j++)
        {
            newList[i][j] = headVar[i][j]; 
        }
    }

    return newList;
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