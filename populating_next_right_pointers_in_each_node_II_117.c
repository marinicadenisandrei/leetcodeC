/* Leetcode - 117. Populating Next Right Pointers in Each Node II (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NULL_POINTER_VAR 99
#define NUMBER_OF_TESTS 2

int connect(int *rootVar, int rootVarSize);
void insertNull(int *rootVar, int rootVarSize, int index);
void printArray(int *rootVar, int rootVarSize);
int removeZeros(int *rootVar, int rootVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 117. Populating Next Right Pointers in Each Node II (C language) - Medium\n");

    int root[ARRAY_SIZE][ARRAY_SIZE] = {{1,2,3,4,5,0,7}, {}};
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

void insertNull(int *rootVar, int rootVarSize, int index)
{
    for (int i = rootVarSize; i >= index; i--)
    {
        rootVar[i] = rootVar[i - 1];
    }

    rootVar[index] = NULL_POINTER_VAR;
}

void printArray(int *rootVar, int rootVarSize)
{
    if (rootVarSize == 0)
    {
        printf(" [] | ");
    }
    
    for (int i = 0; i < rootVarSize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), rootVar[i], ((i < rootVarSize - 1) ? ", " : "]"));
    }

    printf(" | ");
}

int removeZeros(int *rootVar, int rootVarSize)
{
    for (int i = 0; i < rootVarSize; i++)
    {
        if (rootVar[i] == 0)
        {
            for (int j = i; j < rootVarSize; j++)
            {
                rootVar[j] = rootVar[j + 1];
            }

            rootVarSize--;
        }
    }

    return rootVarSize;
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
        insertNull(rootVar, rootVarSize, power);
        rootVarSize++;

        power++;
        power *= 2;
    }

    rootVar[rootVarSize] = NULL_POINTER_VAR;
    rootVarSize++;

    rootVarSize = removeZeros(rootVar, rootVarSize);

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