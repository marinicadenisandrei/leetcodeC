/* Leetcode - 86. Partition List (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 2
#define ARRAY_SIZE 20

void partition(int *headVar, int headVarSize, int xVar);
int locateIndex(int *headVar, int headVarSize, int xVar);
void printArray(const int *headVar, int headVarSize);
void bubbleSort(int *headvar, int headVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{   
    yellow();

    printf("Leetcode - 86. Partition List (C language) - Medium\n");

    int head[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,4,3,2,5,2}, {2,1}};
    int headSize[ARRAY_SIZE] = {6,2};
    int x[ARRAY_SIZE] = {3,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        partition(head[test], headSize[test], x[test]);

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

void bubbleSort(int *headvar, int headVarSize)
{
    int flag = true;
    int counter = 0;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < headVarSize - 1 - counter; i++)
        {
            if (*(headvar + i) > *(headvar + i + 1))
            {
                int temp = *(headvar + i);
                *(headvar + i) = *(headvar + i + 1);
                *(headvar + i + 1) = temp;

                flag = true;
            }
        }

        counter++;
    }
}

void printArray(const int *headVar, int headVarSize)
{
    for (int i = 0; i < headVarSize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), *(headVar + i), ((i < headVarSize - 1) ? ", " : "] | "));
    }
}

int locateIndex(int *headVar, int headVarSize, int xVar)
{
    for (int i = 0; i < headVarSize; i++)
    {
        if (*(headVar + i) == xVar)
        {
            return i;
        }
    } 
}

void partition(int *headVar, int headVarSize, int xVar)
{
    int index = locateIndex(headVar, headVarSize, xVar);
    int flag = true;

    while (flag)
    {
        flag = false;

        for (int i = headVarSize - 1; i > index; i--)
        {
            if (*(headVar + i) < xVar)
            {
                int temp = *(headVar + i);
                *(headVar + i) = *(headVar + i - 1);
                *(headVar + i - 1) = temp;

                flag = true;
            }
        }

        index++;
    }

    bubbleSort(headVar, index - 1);

    printArray(headVar, headVarSize);
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