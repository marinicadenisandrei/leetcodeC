/* Leetcode - 77. Combinations (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void combine(int n, int k);
void printArray(int arrayVar[ARRAY_SIZE], int sizeArray);
void printMatrix(int matrixVar[ARRAY_SIZE][ARRAY_SIZE], int sizeMatrix, int sizeInMatrix);
void initializeArray(int arrayVar[ARRAY_SIZE], int sizeArray);
void initializeBigArray(int bigArray[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int n);
void combineArrays(int smallArray[ARRAY_SIZE], int sizeSmall, int bigArray[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int sizeBigArray, int sizeInBigArray, int elements);
void bubble_sort(int arrayVar[ARRAY_SIZE], int sizeArray);
void sortAllElementsInBigArray(int bigArray[ARRAY_SIZE][ARRAY_SIZE], int sizeBig, int sizeIn);
bool arrayInBigArray(int smallArray[ARRAY_SIZE], int sizeSmall, int bigArray[ARRAY_SIZE][ARRAY_SIZE], int sizeBig);
bool checkForDuplicates(int arrayVar[ARRAY_SIZE], int sizeArray);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{   
    yellow();

    printf("Leetcode - 77. Combinations (C language) - Medium\n");

    int n[ARRAY_SIZE] = {4,1};
    int k[ARRAY_SIZE] = {2,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        combine(n[test], k[test]);

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

void combine(int n, int k)
{
    int mainArray[ARRAY_SIZE] = {};
    int acumulation[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {};

    int starter = 1;
    int lastSize = n;

    int output[ARRAY_SIZE][ARRAY_SIZE] = {};
    int sizeOutput = 0;

    initializeArray(mainArray, n);
    initializeBigArray(acumulation, n);
    
    for (int i = 0; i < k - 1; i++)
    {
        combineArrays(mainArray, n, acumulation, i + 1, lastSize, starter);

        lastSize *= n;
        starter++;
    }

    sortAllElementsInBigArray(acumulation[k - 1], lastSize, k);
    
    for (int i = 0; i < lastSize; i++)
    {
        if (!arrayInBigArray(acumulation[k - 1][i], k, output, sizeOutput) && !checkForDuplicates(acumulation[k - 1][i], k))
        {
            for (int j = 0; j < k; j++)
            {
                output[sizeOutput][j] = acumulation[k - 1][i][j];
            }

            sizeOutput++;
        }
    }

    printMatrix(output, sizeOutput, k);
}

void printArray(int arrayVar[ARRAY_SIZE], int sizeArray)
{
    for (int i = 0; i < sizeArray; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), arrayVar[i], ((i < sizeArray - 1) ? ", " : "]\n"));
    }
    
}

void printMatrix(int matrixVar[ARRAY_SIZE][ARRAY_SIZE], int sizeMatrix, int sizeInMatrix)
{
    for (int i = 0; i < sizeMatrix; i++)
    {
        for (int j = 0; j < sizeInMatrix; j++)
        {
            printf("%s%i%s", ((j == 0) ? "[" : ""), matrixVar[i][j], ((j < sizeInMatrix - 1) ? ", " : "]"));
        }
    }

    printf(" | ");
}

void initializeArray(int arrayVar[ARRAY_SIZE], int sizeArray)
{
    for (int i = 1; i <= sizeArray; i++) arrayVar[i - 1] = i; 
}

void initializeBigArray(int bigArray[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int n)
{
    for (int i = 0; i <= n; i++)
    {
        bigArray[0][i][0] = i + 1;
    }
}

void combineArrays(int smallArray[ARRAY_SIZE], int sizeSmall, int bigArray[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int sizeBigArray, int sizeInBigArray, int elements)
{
    int sizeLast = 0;

    for (int i = 0; i < sizeSmall; i++)
    {
    
        for (int j = 0; j < sizeInBigArray; j++)
        {
            for (int k = 0; k < elements; k++)
            {
                bigArray[sizeBigArray][sizeLast][k] = bigArray[sizeBigArray - 1][j][k];
            }

            bigArray[sizeBigArray][sizeLast][elements] = smallArray[i];

            sizeLast++;
        }        
    }
}

void bubble_sort(int arrayVar[ARRAY_SIZE], int sizeArray)
{
    bool flag = true;
    int counter = 0;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < sizeArray - 1 - counter; i++)
        {
            if (arrayVar[i] > arrayVar[i + 1])
            {
                int temp = arrayVar[i];
                arrayVar[i] = arrayVar[i + 1];
                arrayVar[i + 1] = temp;

                flag = true;
            }
        }

        counter++;
    }
}

void sortAllElementsInBigArray(int bigArray[ARRAY_SIZE][ARRAY_SIZE], int sizeBig, int sizeIn)
{
    for (int i = 0; i < sizeBig; i++)
    {
        bubble_sort(bigArray[i], sizeIn);
    }
}

bool arrayInBigArray(int smallArray[ARRAY_SIZE], int sizeSmall, int bigArray[ARRAY_SIZE][ARRAY_SIZE], int sizeBig)
{
    bool flag = true;

    for (int i = 0; i < sizeBig; i++)
    {
        flag = true;

        for (int j = 0; j < sizeSmall; j++)
        {
            if (smallArray[j] != bigArray[i][j])
            {
                flag = false;
                break;
            }
        }

        if(flag)
        {
            return true;
        }
    }

    return false;   
}

bool checkForDuplicates(int arrayVar[ARRAY_SIZE], int sizeArray)
{
    int counter = 0;

    for (int i = 0; i < sizeArray; i++)
    {
        for (int j = 0; j < sizeArray; j++)
        {
            if (arrayVar[i] == arrayVar[j])
            {
                counter++;
            }
        }

        if (counter > 1)
        {
            return true;
        }
        else
        {
            counter = 0;
        }
    }

    return false;
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
