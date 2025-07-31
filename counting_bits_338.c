/* Leetcode - 338. Counting Bits (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int* countBits(int nVar, int *resultSize);
int countOnesInBinary(int num);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 338. Counting Bits (C language) - ");

    green();

    printf("Easy\n");

    int n[NUMBER_OF_TESTS] = {2,5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();
        
        printf("Test %i: ", test + 1);

        reset();

        int resultSize = 0;
        int *result = countBits(n[test], &resultSize);

        printArray(result, resultSize);

        free(result);

        green();

        printf("Passed\n");
    }

    reset();
     
    return 0;
}

void printArray(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", (i == 0 ? "[" : ""), array[i], (i < arraySize - 1) ? ", " : "] | ");
    }
}

int* countBits(int nVar, int *resultSize)
{
    int *result = (int *)malloc((nVar + 1) * sizeof(int));
    if (result == NULL)
    {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    *resultSize = 0;
    for (int i = 0; i <= nVar; i++)
    {
        result[(*resultSize)++] = countOnesInBinary(i);
    }

    return result;
}

int countOnesInBinary(int num)
{
    int count = 0;
    while (num > 0)
    {
        count += (num & 1);
        num >>= 1;
    }
    return count;
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