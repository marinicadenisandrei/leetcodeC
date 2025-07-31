/* Leetcode - 412. Fizz Buzz (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_TESTS 3
#define ARRAY_SIZE 20

void reset ();
void green ();
void yellow ();
void red ();

char** fizzBuzz(int nVar, int* returnSizeVar);
void printCharArray(char** arr, int arrSize);

int main()
{
    yellow();

    printf("Leetcode - 412. Fizz Buzz (C language) - ");

    green();

    printf("Easy\n");

    int n[ARRAY_SIZE] = {3,5,15};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int returnSize = 0;

        char** result = fizzBuzz(n[test], &returnSize);
        printCharArray(result, returnSize);

        for (int i = 0; i < returnSize; i++)
        {
            free(result[i]);
        }
        free(result);

        green();

        printf("Passed\n");
    }

    reset(0);
    
    return 0;
}

void printCharArray(char** arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%s%s%s", ((i == 0) ? "[" : ""), arr[i], ((i < arrSize - 1) ? ", " : "] | "));
    }
}

char** fizzBuzz(int nVar, int* returnSizeVar)
{
    char** result = (char**)malloc(ARRAY_SIZE * ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        result[i] = (char*)malloc(sizeof(char));
    }

    int resultSize = 0;

    for (int i = 1; i <= nVar; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            strcpy(result[resultSize++], "FizzBuzz");
        }
        else if (i % 3 == 0)
        {
            strcpy(result[resultSize++], "Fizz");
        }
        else if (i % 5 == 0)
        {
            strcpy(result[resultSize++], "Buzz");
        }
        else
        {
            char buff[ARRAY_SIZE];
            sprintf(buff, "%d", i);
            strcpy(result[resultSize++], buff);
        }
    }

    *returnSizeVar = resultSize;

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