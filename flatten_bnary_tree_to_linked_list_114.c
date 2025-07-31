/* Leetcode - 114. Flatten Binary Tree to Linked List (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int flatten(int *rootVar, int rootVarSize);
void insertElementAtSpecificIndex(int *rootVar, int rootVarSize, int indexElement);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 114. Flatten Binary Tree to Linked List (C language) - Medium\n");

    int root[ARRAY_SIZE][ARRAY_SIZE] = {{1,2,5,3,4,0,6}, {}, {0}};
    int rootSize[ARRAY_SIZE] = {7,0,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        rootSize[test] = flatten(root[test], rootSize[test]);
        printArray(root[test], rootSize[test]);

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

void printArray(int *array, int arraySize)
{
    if (arraySize == 0)
    {
        printf("[] | ");
        return;
    }
    
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "]"));
    }

    printf(" | ");
}

void insertElementAtSpecificIndex(int *rootVar, int rootVarSize, int indexElement)
{
    for (int i = rootVarSize - 1; i >= indexElement; i--)
    {
        rootVar[i + 1] = rootVar[i];
    }

    rootVar[indexElement] = 0;
}

int flatten(int *rootVar, int rootVarSize)
{
    for (int i = 0; i < rootVarSize; i++)
    {
        if (rootVar[i] != 0 && rootVar[i + 1] != 0)
        {
            insertElementAtSpecificIndex(rootVar, rootVarSize, i + 1);
            rootVarSize++;
        }
    }

    return rootVarSize;
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