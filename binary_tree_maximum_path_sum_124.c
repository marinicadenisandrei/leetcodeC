/* Leetcode - 124. Binary Tree Maximum Path Sum (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int maxPathSum(int *rootVar, int rootVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 124. Binary Tree Maximum Path Sum (C language) - ");

    red();

    printf("Hard\n");

    int root[ARRAY_SIZE][ARRAY_SIZE] = {{1,2,3},{-10,9,20,0,0,15,7}};
    int rootSize[ARRAY_SIZE] = {3,7};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int result = maxPathSum(root[test], rootSize[test]);
        printf("%i | ", result);

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int maxPathSum(int *rootVar, int rootVarSize)
{
    int maxNode = rootVar[0] + rootVar[1] + rootVar[2];

    for (int i = 1; i < rootVarSize; i++)
    {
        if (rootVar[i] + rootVar[(i * 2) + 1] + rootVar [(i * 2) + 2] > maxNode)
        {
            maxNode = rootVar[i] + rootVar[(i * 2) + 1] + rootVar [(i * 2) + 2];
        }
    }

    return maxNode;
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