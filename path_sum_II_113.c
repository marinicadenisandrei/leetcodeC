/* Leetcode - 113. Path Sum II (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 50
#define NUMBER_OF_TESTS 3

int **pathSum(int *rootVar, int rootVarSize, int targetSumVar);
void shiftTwoAndZeros(int *array, int arraySize, int index);
void printArray(int *array, int arraySize);
int returnDepth(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int resultSize = 0;
int depthLevel = 0;

int main(void)
{
    yellow();

    printf("Leetcode - 113. Path Sum II (C language) - Medium\n");

    int root[ARRAY_SIZE][ARRAY_SIZE] = {{5,4,8,11,0,13,4,7,2,0,0,5,1}, {1,2,3}, {1,2}};
    int rootSize[ARRAY_SIZE] = {13,3,2};
    int targetSum[ARRAY_SIZE] = {22, 5, 0};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int **output = (int **) malloc(resultSize * sizeof(int *));
        output = pathSum(root[test], rootSize[test], targetSum[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        if (resultSize > 0)
        {
            for (int i = 0; i < resultSize; i++)
            {
                printArray(output[i], depthLevel);
            }

            printf(" | ");
        }
        else
        {
            printf("[] | ");
        }

        green();

        printf("Passed\n");

        free(output);
        resultSize = 0;
        depthLevel = 0;
    }

    reset();

    return 0;
}

int returnDepth(int *array, int arraySize)
{
    int power = 1;

    while (arraySize > 0)
    {
        arraySize -= power;
        power *= 2;
    }

    return power / 2;
}

void printArray(int *array, int arraySize)
{
    if (resultSize == 0)
    {
        printf("[]");
        return;
    }
    
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "]"));
    }
}

void shiftTwoAndZeros(int *array, int arraySize, int index)
{    
    for (int i = arraySize; i >= (index * 2); i--)
    {
        array[i + 2] = array[i];
    }

    array[(index * 2) + 1] = 0;
    array[(index * 2) + 2] = 0;
}

int **pathSum(int *rootVar, int rootVarSize, int targetSumVar)
{
    int newSize = rootVarSize;

    for (int i = 0; i < rootVarSize; i++)
    {
        if (rootVar[i] == 0 && ((i * 2) + 2) <= rootVarSize)
        {
            shiftTwoAndZeros(rootVar, rootVarSize, i);
            newSize += 2;
        }
    }

    int depth = returnDepth(rootVar, rootVarSize);
    depthLevel = depth / 2;
    int **result = (int **) malloc(depth * sizeof(int *));

    for (int i = 0; i < depth; i++)
    {
        result[i] = (int *) malloc(depth * sizeof(int));
    }    

    for (int i = 0; i < depth; i++)
    {
        int temp = newSize - i;
        int sum = 0;

        for (int j = 0; j < depth/2; j++)
        {
            sum += rootVar[temp-1];
            result[resultSize][(depth/2) - 1 - j] = rootVar[temp-1];
            temp /= 2;
        }

        if (sum == targetSumVar)
        {
            resultSize++;
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