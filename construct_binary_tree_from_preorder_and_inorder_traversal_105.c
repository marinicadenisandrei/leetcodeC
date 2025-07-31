/* Leetcode - 105. Construct Binary Tree from Preorder and Inorder Traversal (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int outputSize = 1;

int * buildTree(int *preorderVar, int preorderVarSize, int *inorderVar, int inorderVarSize);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 105. Construct Binary Tree from Preorder and Inorder Traversal (C language) - Medium\n");

    int preorder[ARRAY_SIZE][ARRAY_SIZE] = {{3,9,20,15,7}, {-1}};
    int preorderSize[ARRAY_SIZE] = {5,1};

    int inorder[ARRAY_SIZE][ARRAY_SIZE] = {{9,3,15,20,7}, {-1}};
    int inorderSize[ARRAY_SIZE] = {5, 1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int *result = (int *) malloc(ARRAY_SIZE * sizeof(int));

        result = buildTree(preorder[test], preorderSize[test], inorder[test], inorderSize[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printArray(result, outputSize);

        green();

        printf("Passed\n");

        free(result);  
        outputSize = 1;
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

int * buildTree(int *preorderVar, int preorderVarSize, int *inorderVar, int inorderVarSize)
{
    int *output = (int *) malloc(ARRAY_SIZE * sizeof(int));
    output[0] = preorderVar[0];

    if (preorderVarSize < 3)
    {
        return output;
    }

    int left[ARRAY_SIZE] = {0};
    int leftSize = 0;

    int right[ARRAY_SIZE] = {0};
    int rightSize = 0;

    bool flag = true;

    for (int i = 0; i < inorderVarSize; i++)
    {
        if (inorderVar[i] == output[0])
        {
            flag = false;
            continue;
        }

        if (flag)
        {
            left[leftSize] = inorderVar[i];
            leftSize++;
        }
        else
        {
            right[rightSize] = inorderVar[i];
            rightSize++;
        }  
    }

    int indexBinary = 1;
    bool leftFlag = true;
    bool rightFlag = true;

    int offset = 0;

    for (int i = 0; i < 2; i++)
    {
        leftFlag = false;
        rightFlag = false;
        
        for (int j = indexBinary; j <= indexBinary + ((indexBinary - 1) / 2); j++)
        {
            if (preorderVar[j] == 0)
            {
                continue;
            }
            
            for (int k = 0; k < leftSize; k++)
            {
                if (left[k] == preorderVar[j])
                {
                    output[outputSize] = preorderVar[j];
                    outputSize++;
                    leftFlag = true;
                    break;
                }
            }

            if (!leftFlag)
            {
                offset++;
                output[outputSize] = 0;
                outputSize++;
            }
        }

        for (int j = indexBinary + ((indexBinary - 1) / 2) + 1; j <= indexBinary * 2; j++)
        {
            if (preorderVar[j] == 0)
            {
                continue;
            }

            for (int k = 0; k < rightSize; k++)
            {
                if (right[k] == preorderVar[j])
                {
                    output[outputSize] = preorderVar[j];
                    outputSize++;
                    rightFlag = true;
                    break;
                }
            }

            if (!rightFlag)
            {
                offset++;
                output[outputSize] = 0;
                outputSize++;
            }
        }

        if (offset > 0)
        {
            for (int k = indexBinary; k < indexBinary + offset; k++)
            {
                output[outputSize] = preorderVar[k];
                outputSize++;
            }
        }
        
        
        indexBinary *= 2;
        indexBinary++;

        offset = 0;
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