#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void subsets(int array[ARRAY_SIZE], int arraySize, int acumulation[ARRAY_SIZE][ARRAY_SIZE]);
void initializeArray(int bigArray[ARRAY_SIZE][ARRAY_SIZE], int depth);
void printArray(int arrayVar[ARRAY_SIZE], int arraySize);
void printMatrix(int matrix[ARRAY_SIZE][ARRAY_SIZE], int matrixSize, int matrixInSize);
void combineArrays(int mainArray[ARRAY_SIZE], int mainSize, int acumulationArray[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int acumulationSize, int acumulationInSize);
void bubbleSort(int arrayVar[ARRAY_SIZE], int arraySize);
bool checkIfArrayHaveDuplicates(int arrayVar[ARRAY_SIZE], int arraySize);
bool checkArraysDuplicates(int arrayVar[ARRAY_SIZE][ARRAY_SIZE], int arraySize, int arrayInSize);
bool checkEqualArrays(int array1[ARRAY_SIZE], int sizeArray1, int array2[ARRAY_SIZE]);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 78. Subsets (C language) - Medium\n");

    int nums[ARRAY_SIZE][ARRAY_SIZE] = {{1,2,3}, {0}};
    int sizeNums[ARRAY_SIZE] = {3,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int output[ARRAY_SIZE][ARRAY_SIZE] = {};

        subsets(nums[test], sizeNums[test], output);

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

void subsets(int array[ARRAY_SIZE], int arraySize, int acumulation[ARRAY_SIZE][ARRAY_SIZE])
{   
    int bigArray[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {};
    initializeArray(bigArray[0], array[arraySize - 1]);

    int starter = 1;
    int bigSize = arraySize;

    int output[ARRAY_SIZE][ARRAY_SIZE] = {};
    
    for (int i = 0; i < arraySize - 2; i++)
    {
        combineArrays(array, arraySize, bigArray, bigSize, starter);
        starter++;
        bigSize *= arraySize;
    }

    bigSize = arraySize;

    printf("[]");

    for (int i = 0; i < starter + 1; i++)
    {
        printMatrix(bigArray[i - 1], bigSize, i);
        bigSize *= arraySize;
    }

    printArray(array, arraySize);
}

void initializeArray(int bigArray[ARRAY_SIZE][ARRAY_SIZE], int depth)
{
    for (int i = 0; i < depth; i++)
    {
        bigArray[i][0] = i + 1;
    }
}

void printArray(int arrayVar[ARRAY_SIZE], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), arrayVar[i], ((i < arraySize - 1) ? ", " : "] | "));
    }
}

void printMatrix(int matrix[ARRAY_SIZE][ARRAY_SIZE], int matrixSize, int matrixInSize)
{
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixInSize; j++)
        {
            if (matrix[i][0] != -1 && matrix[i][0] != 0)
            {
                printf("%s%i%s", ((j == 0) ? "[" : ""), matrix[i][j], ((j < matrixInSize - 1) ? ", " : "]"));
            }
        }
    }
}

void combineArrays(int mainArray[ARRAY_SIZE], int mainSize, int acumulationArray[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int acumulationSize, int acumulationInSize){
    int lastSize = 0;

    for (int i = 0; i < mainSize; i++)
    {
        for (int j = 0; j < acumulationSize; j++)
        {
            for (int k = 0; k < acumulationInSize; k++)
            {
                acumulationArray[acumulationInSize][lastSize][k] = acumulationArray[acumulationInSize - 1][j][k];
            }
            
            acumulationArray[acumulationInSize][lastSize][acumulationInSize] = mainArray[i];

            if (!checkIfArrayHaveDuplicates(acumulationArray[acumulationInSize][lastSize], acumulationInSize + 1))
            {
                bubbleSort(acumulationArray[acumulationInSize][lastSize], acumulationInSize);
            }
            else
            {
                acumulationArray[acumulationInSize][lastSize][0] = -1;
            }
            
            lastSize++;
        }
    }

    checkArraysDuplicates(acumulationArray[acumulationInSize], lastSize, acumulationInSize + 1);
}

void bubbleSort(int arrayVar[ARRAY_SIZE], int arraySize)
{
    bool flag = true;
    int counter = 0;
    
    while (flag)
    {
        flag = false;

        for (int i = 0; i < arraySize; i++)
        {
            if (arrayVar[i] > arrayVar[i + 1])
            {
                int temp = arrayVar[i];
                arrayVar[i] = arrayVar[i + 1];
                arrayVar[i + 1] = temp;
            }
        }

        counter++;
    }
}

bool checkIfArrayHaveDuplicates(int arrayVar[ARRAY_SIZE], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        for (int j = 0; j < arraySize; j++)
        {
            if (i != j)
            {
                if (arrayVar[i] == arrayVar[j])
                {
                    return true;
                }
            }
        }
    }
    
    return false;
}

bool checkEqualArrays(int array1[ARRAY_SIZE], int sizeArray1, int array2[ARRAY_SIZE])
{
    for (int i = 0; i < sizeArray1; i++)
    {
        if (array1[i] != array2[i])
        {
            return false;
        }
    }

    return true;
}

bool checkArraysDuplicates(int arrayVar[ARRAY_SIZE][ARRAY_SIZE], int arraySize, int arrayInSize)
{
    for (int i = 0; i < arraySize; i++)
    {
        for (int j = i + 1; j < arraySize; j++)
        {
            if (checkEqualArrays(arrayVar[i], arrayInSize, arrayVar[j]))
            {
                arrayVar[i][0] = -1;
                break;
            }
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