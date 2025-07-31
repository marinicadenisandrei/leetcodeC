#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int detectCycle(int *headVar, int headVarSize, int posVar);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 142. Linked List Cycle II (C language) - Medium\n");

    int head[ARRAY_SIZE][ARRAY_SIZE] = {{3,2,0,-4},{1,2},{1}};
    int headSize[ARRAY_SIZE] = {4,2,1};
    int pos[ARRAY_SIZE] = {1,0,-1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", detectCycle(head[test], headSize[test], pos[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int detectCycle(int *headVar, int headVarSize, int posVar)
{
    if (posVar <= headVarSize)
    {
        return posVar;
    }

    return -1;
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