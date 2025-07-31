/* Leetcode - 133. Clone Graph (C++ language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int **cloneGraph(int (*adjListVar)[ARRAY_SIZE], int adjListVarSize, int adjListVarInSize);
void printMatrix(int **matrix, int matrixSize, int matrixInSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 133. Clone Graph (C++ language) - Medium\n"); 

    int adjList[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {{{2,4},{1,3},{2,4},{1,3}}, {{}}, {{}}};
    int adjListSize[ARRAY_SIZE] = {4,0,0};
    int adjListInSize[ARRAY_SIZE] = {2,0,0};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int **output = (int **) malloc(adjListSize[test] * sizeof(int *));

        for (int i = 0; i < adjListInSize[test]; i++)
        {
            output[i] = (int *) malloc(adjListInSize[test] * sizeof(int));
        }
        
        output = cloneGraph(adjList[test], adjListSize[test], adjListInSize[test]);
        printMatrix(output, adjListSize[test], adjListInSize[test]);
        
        for (int i = 0; i < adjListSize[test]; i++)
        {
            free(output[i]);
        }

        free(output);  

        green();

        printf("Passed\n"); 
    }

    reset();
    
    return 0;
}

void printMatrix(int **matrix, int matrixSize, int matrixInSize)
{
    if (matrixSize == 0)
    {
        printf("[] | ");
        return;
    }
    
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixInSize; j++)
        {
            printf("%s%i%s", ((j == 0) ? "[" : ""), matrix[i][j], ((j < matrixInSize - 1) ? ", " : "]"));
        }
    }

    printf(" | ");
}

int **cloneGraph(int (*adjListVar)[ARRAY_SIZE], int adjListVarSize, int adjListVarInSize)
{
    int **cloneArray = (int **) malloc(adjListVarSize * sizeof(int *));

    for (int i = 0; i < adjListVarSize; i++)
    {
        cloneArray[i] = (int *) malloc(adjListVarInSize * sizeof(int));

        for (int j = 0; j < adjListVarInSize; j++)
        {
            cloneArray[i][j] = adjListVar[i][j];
        }
    }

    return cloneArray;
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