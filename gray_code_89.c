/* Leetcode - 89. Gray Code (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

static int resultSize = 0;

int* grayCode(int nVar);
int binaryToInteger(char binaryString[ARRAY_SIZE], int binarySize);
void printArray(int * arrayVar, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 89. Gray Code (C language) - Medium\n");

    int n[ARRAY_SIZE] = {2,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int* result = NULL;
        result = grayCode(n[test]);

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

void printArray(int * arrayVar, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), *(arrayVar + i), ((i < arraySize - 1) ? ", " : "] | "));
    }
    
}

int binaryToInteger(char binaryString[ARRAY_SIZE], int binarySize)
{
    int decimal = 0;
    int power = 0;

    for (int i = binarySize - 1; i >= 0; i--)
    {
        decimal += (binaryString[i] - '0') * pow(2,power);
        power++;
    }   

    return decimal;
}

int* grayCode(int nVar)
{
    int* result = (int*)malloc(sizeof(int));
    resultSize = 0;

    char startingChar[ARRAY_SIZE] = "";
    
    for (int i = 0; i < nVar; i++)
    {
        startingChar[i] = '0';
    }

    result[resultSize] = binaryToInteger(startingChar, nVar);
    resultSize++;

    for (int i = nVar - 1; i >= 0; i--)
    {
        startingChar[i] = '1';
        result[resultSize] = binaryToInteger(startingChar, nVar);
        resultSize++;
    }

    for (int i = nVar - 1; i > 0; i--)
    {
        startingChar[i] = '0';
        result[resultSize] = binaryToInteger(startingChar, nVar);
        resultSize++;
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

