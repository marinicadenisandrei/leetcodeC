/* Leetcode - 222. Count Complete Tree Nodes (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int countNodes(int *rootVar, int rootVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 222. Count Complete Tree Nodes (C language) - ");

    green();

    printf("Easy\n");
    
    int root[ARRAY_SIZE][ARRAY_SIZE] = {{1,2,3,4,5,6},{},{1}};
    int rootSize[ARRAY_SIZE] = {6,0,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", countNodes(root[test], rootSize[test]));

        green();  
        
        printf("Passed\n");
    }

    reset();

    return 0;
}

int countNodes(int *rootVar, int rootVarSize)
{
    int count = 0;

    for (int i = 0; i < rootVarSize; i++)
    {
        count += ((rootVar[i] != 0) ? 1 : 0);
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