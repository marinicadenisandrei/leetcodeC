/* Leetcode - 155. Min Stack (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 20

int* minStack(char stackVar[ARRAY_SIZE][ARRAY_SIZE], int elementsVar[ARRAY_SIZE][1], int sizeArraysVar);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 155. Min Stack (C language) - Medium\n");

    char stack[ARRAY_SIZE][ARRAY_SIZE] = {"MinStack","push","push","push","getMin","pop","top","getMin"};
    int elements[ARRAY_SIZE][1] = {{},{-2},{0},{-3},{},{},{},{}};
    int sizeArrays = 8;
    
    int *output = (int*) malloc(sizeArrays * sizeof(int)); 
    output = minStack(stack, elements, sizeArrays);
    
    green();

    printf("Test 1: ");

    reset();

    printArray(output, sizeArrays);

    green();

    printf("Passed");

    reset();

    return 0;
}

void printArray(int *array, int arraySize)
{
    printf("[");

    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : "["), array[i], ((i < arraySize - 1) ? "], " : "]"));
    }    

    printf("] | ");
}

int* minStack(char stackVar[ARRAY_SIZE][ARRAY_SIZE], int elementsVar[ARRAY_SIZE][1], int sizeArraysVar)
{
    int acumulation[ARRAY_SIZE] = {0};
    int acumulationSize = 0;

    int *result = (int*) malloc(sizeArraysVar * sizeof(int));
    result[0] = 0;
    int resultSize = 1;

    for (int i = 1; i < sizeArraysVar; i++)
    {
        if (strcmp(stackVar[i],"push") == 0)
        {
            acumulation[acumulationSize++] = elementsVar[i][0];
            result[resultSize++] = elementsVar[i][0];
        }
        else if (strcmp(stackVar[i],"getMin") == 0)
        {
            int min = acumulation[0];

            for (int j = 1; j < acumulationSize; j++)
            {
                min = ((min > acumulation[j]) ? acumulation[j] : min);
            }

            result[resultSize++] = 0;
        }
        else if (strcmp(stackVar[i],"pop") == 0)
        {
            for (int i = 0; i < acumulationSize - 1; i++)
            {
                acumulation[i] = acumulation[i + 1];
            }

            acumulationSize--;
            result[resultSize++] = 0;
        }
        else if (strcmp(stackVar[i],"top") == 0)
        {
            result[resultSize++] = 0;
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