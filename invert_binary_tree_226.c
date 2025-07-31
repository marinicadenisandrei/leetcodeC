/* Leetcode - 226. Invert Binary Tree (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int* invertTree(int *rootVar, int rootVarSize);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 226. Invert Binary Tree (C language) - ");

    green();

    printf("Easy\n");

    int root[NUMBER_OF_TESTS][ARRAY_SIZE] = {{4,2,7,1,3,6,9},{2,1,3},{}};
    int rootSize[NUMBER_OF_TESTS] = {7,3,0};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {   
        green();

        printf("Test %i: ", test + 1);

        reset();

        int *output = invertTree(root[test], rootSize[test]);
        printArray(output, rootSize[test]);

        green();

        printf("Passed\n");
    }

    reset();
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
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "] | "));
    }
}

int* invertTree(int *rootVar, int rootVarSize)
{
    int *result = (int *) malloc(ARRAY_SIZE * sizeof(int));

    if (rootVarSize == 0)
    {
        return result;
    }

    int resultSize = 1;
    result[0] = rootVar[0];

    int first = 1;
    int last = 2;
    int power = 2;

    while (last < rootVarSize)
    {
        for (int i = last; i >= first; i--)
        {
            result[resultSize++] = rootVar[i];  
        }

        first += power;
        power *= 2;
        last += power;
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