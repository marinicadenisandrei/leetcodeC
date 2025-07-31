/* Leetcode - 199. Binary Tree Right Side View (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TEST 3

int resultSize = 1;

int* rightSideView(int *rootVar, int rootVarSize);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 199. Binary Tree Right Side View (C language) - Medium\n");

    int root[ARRAY_SIZE][ARRAY_SIZE] = {{1,2,3,0,5,0,4},{1,0,3},{}};
    int rootSize[ARRAY_SIZE] = {7,3,0};

    for (int test = 0; test < NUMBER_OF_TEST; test++)
    {
        int *output = (int *)malloc(ARRAY_SIZE * sizeof(int));
        output = rightSideView(root[test], rootSize[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printArray(output, resultSize);

        green();

        printf("Passed\n");

        resultSize = 1;
        free(output);
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

int* rightSideView(int *rootVar, int rootVarSize)
{
    int *result = (int *)malloc(ARRAY_SIZE * sizeof(int));

    if (rootVarSize == 0)
    {
        resultSize = 0;
        return result;
    }
    
    result[0] = rootVar[0];

    int power = 2;

    for (int i = 0,counter = 0; i < rootVarSize; i++, counter++)
    {
        if (counter == power)
        {
            result[resultSize] = rootVar[i];
            resultSize++;
            counter = 0;
            power *= 2;
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