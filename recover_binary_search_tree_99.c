/* Leetcode - 99. Recover Binary Search Tree (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void recoverTree(int *rootVar, int rootVarSize);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 99. Recover Binary Search Tree (C language) - Medium\n");

    int root[ARRAY_SIZE][ARRAY_SIZE] = {{1,3,0,0,2},{3,1,4,0,0,2}};
    int rootSize[ARRAY_SIZE] = {5,6};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        recoverTree(root[test], rootSize[test]);
        printArray(root[test], rootSize[test]);

        green();

        printf("Passed\n");
    }

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

void recoverTree(int *rootVar, int rootVarSize)
{
    int offset = 3;
    int factor = 0;

    int flag = true;

    while (offset < rootVarSize && flag)
    {
        int n = rootVar[0];
        flag = false;

        int left[ARRAY_SIZE] = {};
        left[0] = rootVar[1];
        int leftSize = 1;
        
        int leftIndex[ARRAY_SIZE] = {};
        leftIndex[0] = 1;

        int right[ARRAY_SIZE] = {};
        right[0] = rootVar[2];
        int rightSize = 1;

        int rightIndex[ARRAY_SIZE] = {};
        rightIndex[0] = 2;

        for (int i = offset; i <= (offset * 2) / 2 + 1; i++)
        {
            left[leftSize] = rootVar[i];
            leftIndex[leftSize] = i;
            leftSize++;
        }

        for (int i = (offset * 2) / 2 + 2; i <= offset * 2; i++)
        {
            right[rightSize] = rootVar[i];
            rightIndex[rightSize] = i;
            rightSize++;
        }
        
        if (flag == false)
        {
            for (int i = 0; i < leftSize; i++)
            {
                if (left[i] > n)
                {
                    int temp = rootVar[0];
                    rootVar[0] = rootVar[leftIndex[i]];
                    rootVar[leftIndex[i]] = temp;

                    flag = true;

                    break;
                }
            }
        }
        
        if (flag == false)
        {
            for (int i = 0; i < rightSize; i++)
            {
                if (right[i] < n && right[i] != 0)
                {
                    int temp = rootVar[0];
                    rootVar[0] = rootVar[rightIndex[i]];
                    rootVar[rightIndex[i]] = temp;
                    flag = true;
                    break;
                }
            }
        }
        
        offset *= 2;
        offset++;
        factor++;
    }
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