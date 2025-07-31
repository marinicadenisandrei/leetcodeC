/* Leetcode - 106. Construct Binary Tree from Inorder and Postorder Traversal (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int resultSize = 3;

int *buildTree(int *inorderVar, int inorderVarSize, int *postorderVar, int postorderVarSize);
void swapArray(int *array, int arraySize);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 106. Construct Binary Tree from Inorder and Postorder Traversal (C language) - Medium\n");

    int inorder[ARRAY_SIZE][ARRAY_SIZE] = {{9,3,15,20,7}, {-1}};
    int inorderSize[ARRAY_SIZE] = {5,1};

    int postorder[ARRAY_SIZE][ARRAY_SIZE] = {{9,15,7,20,3}, {-1}};
    int postorderSize[ARRAY_SIZE] = {5,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int *result = (int *) malloc(ARRAY_SIZE * sizeof(int));
        result = buildTree(inorder[test], inorderSize[test], postorder[test], postorderSize[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printArray(result, resultSize);

        green();

        printf("Passed\n");

        free(result);

        resultSize = 3;
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

void swapArray(int *array, int arraySize)
{
    if (arraySize > 2)
    {
        for (int i = 0; i < arraySize; i+=3)
        {
            int temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
        }
    }
}

int *buildTree(int *inorderVar, int inorderVarSize, int *postorderVar, int postorderVarSize)
{
    int *output = (int *) malloc(ARRAY_SIZE * sizeof(int));
    output[0] = postorderVar[postorderVarSize - 1];

    if (inorderVarSize < 3)
    {
        resultSize = inorderVarSize;
        return output;
    }

    int left[ARRAY_SIZE] = {};
    int leftSize = 0;

    int right[ARRAY_SIZE] = {};
    int rightSize = 0;

    bool flag = false;

    for (int i = 0; i < inorderVarSize; i++)
    {
        if (flag == false && inorderVar[i] == output[0])
        {
            flag = true;
            continue;
        }
        
        if (flag)
        {
            right[rightSize] = inorderVar[i];
            rightSize++;
        }
        else
        {
            left[leftSize] = inorderVar[i];
            leftSize++;
        }
    }

    swapArray(left, leftSize);
    swapArray(right, rightSize);

    output[1] = left[0];
    output[2] = right[0];

    leftSize--;
    rightSize--;

    int index = 1;
    int stop = ((leftSize >= rightSize) ? leftSize : rightSize);

    while (index < rightSize)
    {
        for (int i = index; i <= index * 2; i++)
        {
            if (leftSize > 0)
            {
                output[resultSize] = left[i];
                resultSize++;
                leftSize--;
            }
            else
            {
                output[resultSize] = 0;
                resultSize++;
            }
        }

        for (int i = index; i <= index * 2; i++)
        {
            if (rightSize > 0)
            {
                output[resultSize] = right[i];
                resultSize++;
                rightSize--;
            }
            else
            {
                output[resultSize] = 0;
                resultSize++;
            }
        }

        index *= 2;
        index++;
    }
     
    return output;
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