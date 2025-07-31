/* Leetcode - 206. Reverse Linked List (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3   

void reverseList(int *headVar, int headVarSize);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 206. Reverse Linked List (C language) - ");

    green();

    printf("Easy\n");

    int head[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2,3,4,5},{1,2},{}};
    int headSize[NUMBER_OF_TESTS] = {5,2,0};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        reverseList(head[test], headSize[test]);
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

void reverseList(int *headVar, int headVarSize)
{
    int i = 0;
    int j = headVarSize - 1;
    
    while (i < j)
    {
        int temp = headVar[i];
        headVar[i] = headVar[j];
        headVar[j] = temp;

        i++;
        j--;   
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