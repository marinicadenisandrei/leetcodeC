/* Leetcode - 103. Binary Tree Zigzag Level Order Traversal (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int outputInSize[ARRAY_SIZE];
int outputSize = 1;

int **zigzagLevelOrder(int *rootVar, int rootVarSize);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 103. Binary Tree Zigzag Level Order Traversal (C language) - Medium\n");

    int root[ARRAY_SIZE][ARRAY_SIZE] = {{3,9,20,0,0,15,7}, {1}, {}};
    int rootSize[ARRAY_SIZE] = {7,1,0};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);
        
        reset();

        if (rootSize[test] > 0)
        {
            int **result = (int **)malloc(outputInSize[outputSize] * sizeof(int *));
            for (int i = 0; i < outputInSize[outputSize]; i++)
            {
                result[i] = (int *)malloc(ARRAY_SIZE * sizeof(int));
            }

            result = zigzagLevelOrder(root[test], rootSize[test]);

            for (int i = 0; i < outputSize; i++)
            {
                printArray(result[i], outputInSize[i]);
            }

            printf(" | ");

            for (int i = 0; i < outputSize; i++)
            {
                free(result[i]);
            }

            free(result);
        }
        else
        {
            printf("[] | ");
        }

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
}

int **zigzagLevelOrder(int *rootVar, int rootVarSize)
{
    int depth = 0;
    int power = 1;
    int indexVar = 1;

    outputSize = 1;

    while (rootVarSize > 0)
    {
        rootVarSize -= power;
        power *= 2;
        depth++;
    }

    int **output = (int **)malloc((power / 2) * sizeof(int *));
    for (int i = 0; i < (power / 2); i++)
    {
        output[i] = (int *)malloc(ARRAY_SIZE * sizeof(int));
    }

    output[0][0] = rootVar[0];
    outputInSize[0] = 1;
    
    power = 0;

    for (int i = 0; i < depth - 1; i++)
    {
        if (i % 2 == 1)
        {
            for (int j = indexVar; j <= indexVar * 2; j++)
            {
                output[outputSize][power] = rootVar[j];
                power++;
            }

            outputInSize[outputSize] = power;
            power = 0;
            outputSize++;
        }
        else
        {
            for (int j = indexVar * 2; j >= indexVar ; j--)
            {
                output[outputSize][power] = rootVar[j];
                power++; 
            }

            outputInSize[outputSize] = power;
            power = 0;
            outputSize++;
        }

        indexVar *= 2;
        indexVar++;
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