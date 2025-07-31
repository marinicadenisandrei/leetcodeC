/* Leetcode - 19. Remove Nth Node From End of List (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define ARRAY_SIZE 10
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

int remnoveNthNodeFromArray(int *array, int sizeArray, int indexNode);
void printArray(int *array, int sizeArray);

int main(void)
{
    yellow();

    printf("Leetcode - 19. Remove Nth Node From End of List (C language) - Medium\n");
    
    int head[ARRAY_SIZE][ARRAY_SIZE] = {{1,2,3,4,5}, {1,2}, {1}};
    int sizeHeadTest[ARRAY_SIZE] = {5,2,1};
    int nTest[ARRAY_SIZE] = {2,1,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int sizeHead = sizeHeadTest[test];
        int n = nTest[test];

        sizeHead = remnoveNthNodeFromArray(head[test], sizeHead, n);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printArray(head[test], sizeHead);

        printf(" | ");

        green();

        printf("Passed\n");

        reset();
    }

    return 0;
}

int remnoveNthNodeFromArray(int *array, int sizeArray, int indexNode)
{   
    array += (sizeArray - indexNode);

    for (int i = 0; i < indexNode; i++, array++)
    {
        *array = *(array + 1);
    }

    sizeArray--;
    
    return sizeArray;
}

void printArray(int *array, int sizeArray)
{
    printf("%s", (sizeArray == 0) ? "[]" : "");
    
    for (int i = 0; i < sizeArray; i++, array++)
    {
        printf("%s%d%s", (i == 0) ? "[" : "", *array, (i + 1 < sizeArray) ? ", " : "]");
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