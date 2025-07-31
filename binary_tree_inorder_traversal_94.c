/* Leetcode - 94. Binary Tree Inorder Traversal (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3
static int RESULT_SIZE = 1;

int  *inorderTraversal(int *rootVar, int rootVarSize);
void printArray(int *arrayVar, int arraySize);
void shiftAndAddZeros(int *arrayVar, int arraySize, int indexShift);
bool elementInArray(int *arrayVar, int arraySize, int element);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 94. Binary Tree Inorder Traversal (C language) - ");

    green();

    printf("Easy\n");

    int root[ARRAY_SIZE][ARRAY_SIZE] = {{1,0,2,3}, {}, {1}};
    int rootSize[ARRAY_SIZE] = {4,0,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int *result = inorderTraversal(root[test], rootSize[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printArray(result, RESULT_SIZE);

        green();

        printf("Passed\n");

        free(result); 

        RESULT_SIZE = 1;
    }

    reset();

    return 0;
}

bool elementInArray(int *arrayVar, int arraySize, int element)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (*(arrayVar + i) == element)
        {
            return true;
        }
    }

    return false;
}

void printArray(int *arrayVar, int arraySize)
{
    if (*arrayVar == 0 && arraySize == 1)
    {
        printf("[] | ");
    }
    else
    {
        for (int i = 0; i < arraySize; i++)
        {
            printf("%s%i%s", ((i == 0) ? "[" : ""), *(arrayVar + i), ((i < arraySize - 1) ? ", " : "] | "));
        }
    }
}

int  *inorderTraversal(int *rootVar, int rootVarSize)
{
    int *result = (int*)malloc(ARRAY_SIZE * sizeof(int));

    result[0] = *(rootVar);

    bool flag = true;

    for (int i = 0; i < rootVarSize; i++)
    {
        if (*(rootVar + i) == 0)
        {
            flag = false;

            shiftAndAddZeros(rootVar, rootVarSize, (i * 2) + 1);

            rootVarSize += 2;
        }

        for (int j = 0; j < rootVarSize; j++)
        {
            flag = (*(rootVar + j) != 0 ? true : false);
        }

        if (flag == false)
        {
            break;
        }
    }

    int leftIndex = 1;
    int rightIndex = 2;

    for (int i = 1; i < rootVarSize; i++)
    { 
        for (int j = (i * 2) + 2; j > (i * 2); j--)
        {
            if (*(rootVar + j) != 0 && !elementInArray(result, RESULT_SIZE, *(rootVar + j)))
            {
                *(result + RESULT_SIZE) = *(rootVar + j);
                RESULT_SIZE++;
            }
        }

        if (*(rootVar + i) != 0 && !elementInArray(result, RESULT_SIZE, *(rootVar + i)))
        {
            *(result + RESULT_SIZE) = *(rootVar + i);
            RESULT_SIZE++;
        }
    }
    
    return result;
}

void shiftAndAddZeros(int *arrayVar, int arraySize, int indexShift)
{
    for (int i = arraySize + 1; i >= indexShift; i--)
    {
        *(arrayVar + i) = *(arrayVar + i - 2);
    }

    *(arrayVar + indexShift) = 0;
    *(arrayVar + indexShift + 1) = 0;
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