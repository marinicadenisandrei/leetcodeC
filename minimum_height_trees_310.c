/* Leetcode - 310. Minimum Height Trees (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int resultSize = 0;

int* findMinHeightTrees(int nVar, int edgesVar[ARRAY_SIZE][2], int edgesVarSize);
bool itemInArray(int *array, int arraySize, int item);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 310. Minimum Height Trees (C language) - Medium\n");

    int n[NUMBER_OF_TESTS] = {4,6};
    int edges[NUMBER_OF_TESTS][ARRAY_SIZE][2] = {{{1,0},{1,2},{1,3}},{{3,0},{3,1},{3,2},{3,4},{5,4}}};
    int edgesSize[NUMBER_OF_TESTS] = {3,5};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int *output = findMinHeightTrees(n[test], edges[test], edgesSize[test]);
        printArray(output, resultSize);

        free(output);
        resultSize = 0;

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

void printArray(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "] | "));
    }
}

bool itemInArray(int *array, int arraySize, int item)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] == item)
        {
            return true;
        }
    }

    return false;
}

int* findMinHeightTrees(int nVar, int edgesVar[ARRAY_SIZE][2], int edgesVarSize)
{
    int *result = (int *)malloc(ARRAY_SIZE * sizeof(int));

    for (int j = 0; j < edgesVarSize; j++)
    {
        int finder = edgesVar[j][0];

        for (int i = 1; i < edgesVarSize; i++)
        {
            if (edgesVar[i][0] == finder + 1 && edgesVar[i][1] == finder + 2 && i != j)
            {
                if (!itemInArray(result, resultSize, finder) && finder != 0)
                {
                    result[resultSize++] = finder;
                }
                
                if (!itemInArray(result, resultSize, edgesVar[i][0]) && edgesVar[i][0] != 0)
                {
                    result[resultSize++] = edgesVar[i][0];
                }

                finder = edgesVar[i][0];
            }
            else if (edgesVar[i][1] == finder + 1 && edgesVar[i][0] == finder + 2 && i != j)
            {
                if (!itemInArray(result, resultSize, finder) && finder != 0)
                {
                    result[resultSize++] = finder;
                }
                
                if (!itemInArray(result, resultSize, edgesVar[i][1]) && edgesVar[i][1] != 0)
                {
                    result[resultSize++] = edgesVar[i][1];
                }

                finder = edgesVar[i][1];
            }
        }
    }

    if (resultSize == 0)
    {
        result[resultSize++] = edgesVar[0][0];
    }
    
    return result;
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
