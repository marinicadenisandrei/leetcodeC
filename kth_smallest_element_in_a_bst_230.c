#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int kthSmallest(int *rootVar, int rootVarSize, int kVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 230. Kth Smallest Element in a BST (C language) - Medium\n");
    
    int root[NUMBER_OF_TESTS][ARRAY_SIZE] = {{3,1,4,0,2},{5,3,6,2,4,0,0,1}};
    int rootSize[NUMBER_OF_TESTS] = {5,8};
    int k[NUMBER_OF_TESTS] = {1,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", kthSmallest(root[test], rootSize[test], k[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int kthSmallest(int *rootVar, int rootVarSize, int kVar)
{
    bool flag = true;

    while (flag)
    {
        flag  = false;
        int counter = 0;

        for (int i = 0; i < rootVarSize - 1 - counter; i++)
        {
            if (rootVar[i] > rootVar[i + 1])
            {
                int temp = rootVar[i];
                rootVar[i] = rootVar[i + 1];
                rootVar[i + 1] = temp;

                flag = true;
                break;
            }
        }

        counter++;
    }

    int counter = 0;

    for (int i = 0; i < rootVarSize; i++)
    {
        if (rootVar[i] != 0)
        {
            counter++;
        }
        
        if (counter == kVar)
        {
            return rootVar[i];  
        }
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