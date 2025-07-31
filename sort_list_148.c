/* Leetcode - 148. Sort List (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int sortList(int *headVar, int headVarSize);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 148. Sort List (C language) - Medium\n");

    int head[ARRAY_SIZE][ARRAY_SIZE] = {{4,2,1,3},{-1,5,3,4,0}};
    int headSize[ARRAY_SIZE] = {4,5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        sortList(head[test], headSize[test]);
        printArray(head[test], headSize[test]);
        
        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int sortList(int *headVar, int headVarSize)
{
    bool flag = true;
    int counter = 0;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < headVarSize - 1 - counter; i++)
        {
            if (headVar[i] > headVar[i + 1])
            {
                int temp = headVar[i];
                headVar[i] = headVar[i + 1];
                headVar[i + 1] = temp;

                flag = true;
            }
        }

        counter++;
    }
}

void printArray(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "]"));
    }

    printf(" | ");
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