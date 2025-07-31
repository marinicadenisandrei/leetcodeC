/* Leetcode - 92. Reverse Linked List II (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reverseBetween(int *headVar, int headSize, int left, int right);
void printArray(int *arrayVar, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 92. Reverse Linked List II (C language) - Medium\n");

    int head[ARRAY_SIZE][ARRAY_SIZE] = {{1,2,3,4,5}, {5}};
    int headSize[ARRAY_SIZE] = {5,1};
    int left[ARRAY_SIZE] = {2,1};
    int right[ARRAY_SIZE] = {4,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        reverseBetween(head[test], headSize[test], left[test], right[test]);

        green();

        printf("Passed\n");
    }

    reset();
}

void printArray(int *arrayVar, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), *(arrayVar + i), ((i < arraySize - 1) ? ", " : "] | "));
    }
    
}

void reverseBetween(int *headVar, int headSize, int left, int right)
{
    for (int j = 0; j < right - left; j++)
    {
        for (int i = left - 1; i < right - j - 1; i++)
        {
            int temp = *(headVar + i);
            *(headVar + i) = *(headVar + i + 1);
            *(headVar + i + 1) = temp;
        }
    }

    printArray(headVar, headSize);
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