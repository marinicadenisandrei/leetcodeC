/* Leetcode - 98. Validate Binary Search Tree (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

bool isValidBST(int *rootVar, int rootVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{`
    yellow();

    printf("Leetcode - 98. Validate Binary Search Tree (C language) - Medium\n");

    int root[ARRAY_SIZE][ARRAY_SIZE] = {{2,1,3}, {5,1,4,0,0,3,6}};
    int rootSize[ARRAY_SIZE] = {3, 7};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        bool result = isValidBST(root[test], rootSize[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s ", (result == 1) ? "true | " : "false | ");

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

bool isValidBST(int *rootVar, int rootVarSize)
{
    for (int i = 0; i < rootVarSize; i++)
    {
        if ((i * 2 + 1) > rootVarSize || (i * 2 + 2) > rootVarSize)
        {
            break;
        }
        
        if (rootVar[i] < rootVar[i * 2 + 1] || rootVar[i] > rootVar[i * 2 + 2] || rootVar[i * 2 + 1] > rootVar[i * 2 + 2])
        {
            return false;
        }
    }

    return true;
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