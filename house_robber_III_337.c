/* Leetcode - 337. House Robber III (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int rob(int *rootVar, int rootVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 337. House Robber III (C language) - Medium\n");

    int root[NUMBER_OF_TESTS][ARRAY_SIZE] = {{3,2,3,0,3,0,1},{3,4,5,1,3,0,1}};
    int rootSize[NUMBER_OF_TESTS] = {7,7};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", rob(root[test], rootSize[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int rob(int *rootVar, int rootVarSize)
{
    int sumVar = rootVar[0];
    int continuePoint = 1;
    int index = 1;


    for (int i = 0; i < rootVarSize; i++)
    {
        if ((i * 2) + 1 > rootVarSize - 1)
        {
            break;
        }

        if (index == continuePoint)
        {
            sumVar += (rootVar[(i * 2) + 1] > rootVar[(i * 2) + 2] ? rootVar[(i * 2) + 1] : rootVar[(i * 2) + 2]);

            continuePoint *= 2;
            index = 0;
        }

        index++;
    }


    return sumVar;
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