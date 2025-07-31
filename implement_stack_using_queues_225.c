/* Leetcode - 225. Implement Stack using Queues (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 20

int resultSize = 1;
int* MyStack(char methodsVar[ARRAY_SIZE][ARRAY_SIZE], int numbersVar[ARRAY_SIZE][1], const int sizeVar);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 225. Implement Stack using Queues (C language) - ");

    green();

    printf("Easy\n");

    char methods[ARRAY_SIZE][ARRAY_SIZE] = {"MyStack", "push", "push", "top", "pop", "empty"};
    int numbers[ARRAY_SIZE][1] = {{},{1},{2},{},{},{}};
    int size = 6;

    int *output = MyStack(methods, numbers, size);

    printf("Test 1: ");

    reset();

    printf("[");

    for (int i = 0; i < resultSize; i++)
    {
        printf("%i%s", output[i], ((i < resultSize - 1) ? ", " : "] | "));
    }
    
    green();

    printf("Passed\n");

    reset();

    return 0;
}

int* MyStack(char methodsVar[ARRAY_SIZE][ARRAY_SIZE], int numbersVar[ARRAY_SIZE][1], const int sizeVar)
{
    int *result = (int*) malloc(sizeVar * sizeof(int));
    result[0] = -1;

    int acumulation[sizeVar];
    int acumulationSize = 0;

    for (int i = 1; i < sizeVar; i++)
    {
        if (strcmp(methodsVar[i], "push") == 0)
        {
            result[resultSize++] = -1;
            acumulation[acumulationSize++] = numbersVar[i][0];
        }
        else if (strcmp(methodsVar[i], "top") == 0)
        {
            result[resultSize++] = acumulation[acumulationSize - 1];
        }
        else if (strcmp(methodsVar[i], "pop") == 0)
        {
            result[resultSize++] = acumulation[acumulationSize - 1];
            acumulationSize--;
        }
        else if (strcmp(methodsVar[i], "empty") == 0)
        {
            if (acumulationSize > 0)
            {
                result[resultSize++] = 0;
            }
            else
            {
                result[resultSize++] = 1;
            }
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