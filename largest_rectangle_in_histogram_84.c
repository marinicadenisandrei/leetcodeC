/* Leetcode - 84. Largest Rectangle in Histogram (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int largestRectangleArea(int arrayVar[ARRAY_SIZE], int arraySize);
int maxElementFromArray(int *arrayVar, int arraySize);
void printMatrix(int matrix[ARRAY_SIZE][ARRAY_SIZE], int matrixSize, int matrixInSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 84. Largest Rectangle in Histogram (C language) - ");

    red();

    printf("Hard\n");

    int height[ARRAY_SIZE][ARRAY_SIZE] = {{2,1,5,6,2,3},{2,4}};
    int heightSize[ARRAY_SIZE] = {6,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int result = largestRectangleArea(height[test], 6);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", result);

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int largestRectangleArea(int arrayVar[ARRAY_SIZE], int arraySize)
{
    int matrixVar[ARRAY_SIZE][ARRAY_SIZE] = {};
    int maxElement = maxElementFromArray(arrayVar, arraySize);

    for (int i = 0; i < arraySize; i++)
    {
        for (int j = 0; j < maxElement; j++)
        {
            if (j < arrayVar[i])
            {
                matrixVar[i][j] = 1;
            }
            else
            {
                matrixVar[i][j] = 0;
            }
        }
    }

    int elements = 0;
    int max = 0;

    for (int i = 1; i < arraySize; i++)
    {
        for (int j = 1; j < maxElement; j++)
        {
            if (matrixVar[j - 1][i - 1] == 1)
            {
                elements++;
            } 
            else
            {
                max = ((max < elements * i) ? elements * i : max);
                elements = 0;
            } 
        }

        elements = 0;        
    }

    return max;
}

int maxElementFromArray(int *arrayVar, int arraySize)
{
    int max = 0;

    for (int i = 0; i < arraySize; i++)
    {
        if (max < *(arrayVar + i)) max = *(arrayVar + i);
    }

    return max;
}

void printMatrix(int matrix[ARRAY_SIZE][ARRAY_SIZE], int matrixSize, int matrixInSize)
{
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixInSize; j++)
        {
            printf("%s%i%s", ((j == 0) ? "[" : ""), matrix[i][j], ((j < matrixInSize - 1) ? ", " : "]\n"));
        }
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