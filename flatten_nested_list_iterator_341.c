/* Leetcode - 341. Flatten Nested List Iterator (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int resultSize = 0;

void reset ();
void green ();
void yellow ();
void red ();

int* NestedIterator(int nestedListVar[ARRAY_SIZE][ARRAY_SIZE], int *nestedListSizesVar, int nestedListSizeVar);
void printArray(int *array, int arraySize);

int main()
{
    yellow();

    printf("Leetcode - 341. Flatten Nested List Iterator (C language) - Medium\n");

    int nestedList[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE] = {{{1,1},{2},{1,1}},{{1},{4},{6}}};
    int nestedListSizes[NUMBER_OF_TESTS][ARRAY_SIZE] = {{2,1,2},{1,1,1}};
    int nestedListSize[NUMBER_OF_TESTS] = {3,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);
        
        reset();

        int *output = NestedIterator(nestedList[test], nestedListSizes[test], nestedListSize[test]);
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

int* NestedIterator(int nestedListVar[ARRAY_SIZE][ARRAY_SIZE], int *nestedListSizesVar, int nestedListSizeVar)
{
    int *result = (int*)malloc(ARRAY_SIZE * sizeof(int));

    for (int i = 0; i < nestedListSizeVar; i++)
    {
        for (int j = 0; j < nestedListSizesVar[i]; j++)
        {
            result[resultSize++] = nestedListVar[i][j];
        }
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