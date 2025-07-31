#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_TESTS 2
#define ARRAY_SIZE 20

int *deleteDuplicates(int arrayVar[ARRAY_SIZE], int arraySize);
int duplicatesNumber(int arrayVar[ARRAY_SIZE], int arraySize);
void printArray(int *arrayVar, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 82. Remove Duplicates from Sorted List II (C language) - Medium\n");

    int head[ARRAY_SIZE][ARRAY_SIZE] = {{1,2,3,3,4,4,5}, {1,1,1,2,3}};
    int headSize[ARRAY_SIZE] = {7,5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int *result = NULL;
        int resultSize = duplicatesNumber(head[test], headSize[test]);
        result = deleteDuplicates(head[test], headSize[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printArray(result, resultSize);

        green();

        printf("Passed\n");

        free(result);
    }
    
    reset();
    
    return 0;
}

int *deleteDuplicates(int arrayVar[ARRAY_SIZE], int arraySize)
{
    int *output = NULL;
    int n = 0;
    n = duplicatesNumber(arrayVar, arraySize);

    output = (int*)malloc(n * sizeof(int));
    int outputSize = 0;
    
    int counter = 0;
    int duplicate = 0;

    for (int i = 0; i < arraySize; i++)
    {
        for (int j = 0; j < arraySize; j++)
        {
            if (arrayVar[i] == arrayVar[j])
            {
                duplicate++;
            }
        }

        if (duplicate < 2)
        {
            output[outputSize] = arrayVar[i];
            outputSize++;
            counter++;
        }

        duplicate = 0;
    }
    
    return output;
}

int duplicatesNumber(int arrayVar[ARRAY_SIZE], int arraySize)
{
    int counter = 0;
    int duplicate = 0;

    for (int i = 0; i < arraySize; i++)
    {
        for (int j = 0; j < arraySize; j++)
        {
            if (arrayVar[i] == arrayVar[j])
            {
                duplicate++;
            }
        }

        if (duplicate < 2)
        {
            counter++;
        }

        duplicate = 0;
    }

    return counter;
}

void printArray(int *arrayVar, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), *(arrayVar + i), ((i < arraySize - 1) ? ", " : "] | "));
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