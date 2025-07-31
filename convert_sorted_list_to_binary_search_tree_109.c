/* Leetcode - 109. Convert Sorted List to Binary Search Tree (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int resultSize = 1;

int *sortedListToBST(int *headVar, int headVarSize);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 109. Convert Sorted List to Binary Search Tree (C language) - Medium\n");

    int head[ARRAY_SIZE][ARRAY_SIZE] = {{-10,-3,0,5,9}, {}};
    int headSize[ARRAY_SIZE] = {5, 0};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int *result = (int *) malloc(resultSize * sizeof(int));
        result = sortedListToBST(head[test], headSize[test]);
        
        green();

        printf("Test %i: ", test + 1);

        reset();

        printArray(result, resultSize);

        green();

        printf("Passed\n");

        free(result);
        resultSize = 0;
    }

    reset();
    
    return 0;
}

void printArray(int *array, int arraySize)
{
    if (arraySize == 0)
    {
        printf("[] | ");
        return;
    }
    
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "]"));
    }   

    printf(" | ");
}

int *sortedListToBST(int *headVar, int headVarSize)
{
    int *output = (int *) malloc(ARRAY_SIZE * sizeof(int)); 

    if (headVarSize == 0)
    {
        return output;
    }
    
    int mid = (headVarSize / 2);
    output[0] = headVar[mid];

    int leftStart = mid - 1;
    int rightStart = headVarSize - 1;

    int power = 1;
    
    for (int i = 0; i < 2; i++)
    {
        if (leftStart >= (power / 2))
        {
            for (int j = 0; j < power; j++)
            {
                output[resultSize] = headVar[leftStart];
                output[resultSize + 1] = headVar[rightStart];

                leftStart--;
                rightStart--;

                resultSize += 2;
            }
        }
        else
        {
            for (int j = 0; j < power / 2; j++)
            {
                output[resultSize] = headVar[leftStart];
                output[resultSize + 1] = 0;
                output[resultSize + 2] = headVar[rightStart];
                output[resultSize + 3] = 0;

                leftStart--;
                rightStart--;

                resultSize += 4;
            }
        }
      
        power *= 2;
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
