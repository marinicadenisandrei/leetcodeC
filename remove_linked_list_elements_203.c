#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void removeElements(int *headVar, int *headVarSize, int valVar);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 203. Remove Linked List Elements (C language) - ");

    green();

    printf("Easy\n");

    int head[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2,6,3,4,5,6},{},{7,7,7,7}};
    int headSize[NUMBER_OF_TESTS] = {7,0,4};
    int val[NUMBER_OF_TESTS] = {6,1,7};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        removeElements(head[test], &headSize[test], val[test]);
        printArray(head[test], headSize[test]);

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
    }
    
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "] | "));
    }
}

void removeElements(int *headVar, int *headVarSize, int valVar)
{
    for (int i = 0; i < *headVarSize; i++)
    {
        if (headVar[i] == valVar)
        {
            for (int j = i; j < *headVarSize; j++)
            {
                headVar[j] = headVar[j + 1];
            }

            (*headVarSize)--;
            i--;
        }
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