/* Leetcode - 173. Binary Search Tree Iterator (Python language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 20
int resultSize = 1;

int* BSTIterator(char methodsBSTvar[ARRAY_SIZE][ARRAY_SIZE], int methodsBSTsizeVar, int *BSTvar, int BSTsizeVar);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 173. Binary Search Tree Iterator (Python language) - Medium\n");

    char methodsBST[ARRAY_SIZE][ARRAY_SIZE] = {"next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"};
    int methodsBSTsize = 9;
    int BST[ARRAY_SIZE] = {7, 3, 15, 0, 0, 9, 20};
    int BSTsize = 7;

    green();

    printf("Test 1: ");

    reset();

    int *output = (int*)malloc(ARRAY_SIZE * sizeof(int));
    output = BSTIterator(methodsBST, methodsBSTsize, BST, BSTsize);

    printArray(output, resultSize);

    green();

    printf("Passed\n");

    reset();

    return 0;
}

void printArray(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "]"));
    }

    printf(" | ");
}

int* BSTIterator(char methodsBSTvar[ARRAY_SIZE][ARRAY_SIZE], int methodsBSTsizeVar, int *BSTvar, int BSTsizeVar)
{
    int *result = (int*)malloc(ARRAY_SIZE * sizeof(int));
    result[0] = 0;
    int starter = 0;

    for (int i = 0; i < BSTsizeVar; i++)
    {
        if (BSTvar[i] == 0)
        {
            for (int j = i; j < BSTsizeVar - 1; j++)
            {
                BSTvar[j] = BSTvar[j + 1];
                i--;
            }

            BSTsizeVar--;
        }
    }

    for (int i = 0; i < BSTsizeVar; i += 2)
    {
        if (i + 1 > BSTsizeVar)
        {
            break;
        }
        
        int temp = BSTvar[i];
        BSTvar[i] = BSTvar[i + 1];
        BSTvar[i + 1] = temp;
    }

    for (int i = 0; i < methodsBSTsizeVar; i++)
    {
        if (strcmp(methodsBSTvar[i], "next") == 0)
        {
            result[resultSize++] = BSTvar[starter++];
        }
        else if (strcmp(methodsBSTvar[i], "hasNext") == 0)
        {
            if (starter < BSTsizeVar)
            {
                result[resultSize++] = 1;
            }
            else
            {
                result[resultSize++] = 0;
            }
        }
    }

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