/* Leetcode - 450. Delete Node in a BST (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

int* deleteNode(int* rootVar, int* rootSizeVar, int keyVar);
void printArr(int* arr, int arrSize);

int main()
{
    yellow();

    printf("Leetcode - 450. Delete Node in a BST (C language) - Medium\n");

    int root[NUMBER_OF_TESTS][ARRAY_SIZE] = {{5,3,6,2,4,0,7},{5,3,6,2,4,0,7},{}};
    int rootSize[NUMBER_OF_TESTS] = {7,7,0};
    int key[NUMBER_OF_TESTS] = {3,0,0};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int* newRoot = deleteNode(root[test], &rootSize[test], key[test]);
        printArr(newRoot, rootSize[test]);
        free(newRoot);

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

void printArr(int* arr, int arrSize)
{
    if (arrSize == 0)
    {
        printf("[] | ");
        return;
    }
    
    for (int i = 0; i < arrSize; i++)
    {
        printf("%s%i%s",
               (i == 0 ? "[" : ""),
               arr[i],
               (i < arrSize - 1) ? ", " : "] | ");
    }
}

int* deleteNode(int* rootVar, int* rootSizeVar, int keyVar)
{
    int* result = malloc(*rootSizeVar * sizeof(int));
    int resultSize = 0;

    if (keyVar == 0)
    {
        return rootVar;
    }
    
    for (int i = 0; i < *rootSizeVar; i++)
    {
        if (rootVar[i] != keyVar)
        {
            result[resultSize++] = rootVar[i];
        }
    }

    *rootSizeVar = resultSize;
    return result;
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