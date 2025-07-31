/* Leetcode - 116. Populating Next Right Pointers in Each Node (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NULL_POINTER 99
#define NUMBER_OF_TESTS 2


int connect(int *rootVar, int rootVarSize);
void insertAtSpecifiedIndex(int *array, int arraySize, int element);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 116. Populating Next Right Pointers in Each Node (C language) - Medium\n");

    int root[ARRAY_SIZE][ARRAY_SIZE] = {{1,2,3,4,5,6,7}, {}};
    int rootSize[ARRAY_SIZE] = {7,0};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        rootSize[test] = connect(root[test], rootSize[test]);
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

void insertAtSpecifiedIndex(int *array, int arraySize, int element)
{
    for (int i = arraySize; i >= element; i--)
    {
        array[i] = array[i - 1];
    }

    array[element] = NULL_POINTER;
}

int connect(int *rootVar, int rootVarSize)
{
    if (rootVarSize == 0)
    {
        return 0;
    }
    
    int power = 1;

    while (power < rootVarSize)
    {
        insertAtSpecifiedIndex(rootVar, rootVarSize, power);
        rootVarSize++;
        power++;
        power *= 2;
    }

    rootVar[rootVarSize] = NULL_POINTER;
    rootVarSize++;

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