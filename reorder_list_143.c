/* Leetcode - 143. Reorder List (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reorderList(int *headVar, int headVarSize);
void insertInArray(int *array, int arraySize, int index, int element);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 143. Reorder List (C language) - Medium\n");

    int head[ARRAY_SIZE][ARRAY_SIZE] = {{1,2,3,4},{1,2,3,4,5}};
    int headSize[ARRAY_SIZE] = {4,5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        reorderList(head[test], headSize[test]);
        printArray(head[test], headSize[test]);

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

void insertInArray(int *array, int arraySize, int index, int element)
{
    for (int i = arraySize - 1; i >= index; i--)
    {
        array[i + 1] = array[i];
    }

    array[index] = element;
}

void printArray(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "]"));
    }

    printf(" | ");
}

void reorderList(int *headVar, int headVarSize)
{
    int i = 1;

    while (headVarSize - i > 1)
    {
        insertInArray(headVar, headVarSize, i, headVar[headVarSize - 1]);
        i += 2;
    }
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