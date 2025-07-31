/* Leetcode - 39. Combination Sum (C language) - Medium */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void printArrayInt(int array[ARRAY_SIZE], int sizeArray);
int generateSum(int candidatesArrary[ARRAY_SIZE], int candidateArraySize, int outputArray[ARRAY_SIZE][ARRAY_SIZE], int newSizes[ARRAY_SIZE], int targetVar);
bool stillDifferentLast(int array[ARRAY_SIZE], int arraySize);
int arraySum(int array[ARRAY_SIZE], int arraySize);
void appendToArray(int simpleArray[ARRAY_SIZE], int sizeSimpleArray, int bigArray[ARRAY_SIZE][ARRAY_SIZE], int sizeBigArray);
bool simpleArrayExistInBigArray(int simpleArray[ARRAY_SIZE], int sizeSimpleArray, int bigArray[ARRAY_SIZE][ARRAY_SIZE], int sizeBigArray, int insideBigSizes[ARRAY_SIZE]);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 39. Combination Sum (C language) - Medium\n");

    int candidates[ARRAY_SIZE][ARRAY_SIZE] = {{2,3,6,7}, {2,3,5}, {2}};
    int candidatesSize[ARRAY_SIZE] = {4, 3, 1};
    int target[ARRAY_SIZE] = {7, 8, 1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int formatArray[ARRAY_SIZE][ARRAY_SIZE] = {};
        int formatArraySize = 0;

        int newFormatSizes[ARRAY_SIZE] = {};

        generateSum(candidates[test], candidatesSize[test], formatArray, newFormatSizes, target[test]);

        int output[ARRAY_SIZE][ARRAY_SIZE] = {};
        int outputSize = 0;
        int outputInteriorSizes[ARRAY_SIZE] = {};
        int interiorIndex = 0;

        for (int i = 0; i < candidatesSize[test]; i++)
        {
            int temp[ARRAY_SIZE] = {};
            int sum = 0;
            
            for (int j = 0; j < newFormatSizes[i]; j++)
            {
                temp[j] = formatArray[i][j];
            }

            if (arraySum(temp, newFormatSizes[i]) == target[test] && simpleArrayExistInBigArray(temp, newFormatSizes[i], output, outputSize, outputInteriorSizes) == false)
            {
                appendToArray(temp, newFormatSizes[i], output, outputSize);
                outputSize++;
                outputInteriorSizes[interiorIndex] = newFormatSizes[i];
                interiorIndex++;
            }

            int start = 1;
            
            for (int k = 0; k < candidatesSize[test]; k++)
            {
                if (temp[0] != candidates[test][k])
                {
                    int indexEnd = newFormatSizes[i] - 1;
                    temp[indexEnd] = candidates[test][k];
                    indexEnd--;
                    
                    if (arraySum(temp, newFormatSizes[i]) == target[test] && simpleArrayExistInBigArray(temp, newFormatSizes[i], output, outputSize, outputInteriorSizes) == false)
                    {
                        appendToArray(temp, newFormatSizes[i], output, outputSize);
                        outputSize++;
                        outputInteriorSizes[interiorIndex] = newFormatSizes[i];
                        interiorIndex++;
                    }
                    
                    while (stillDifferentLast(temp, newFormatSizes[i]))
                    {
                        temp[indexEnd] = candidates[test][k];
                        indexEnd--;

                        if (arraySum(temp, newFormatSizes[i]) == target[test])
                        {
                            appendToArray(temp, newFormatSizes[i], output, outputSize);
                            outputSize++;
                            outputInteriorSizes[interiorIndex] = newFormatSizes[i];
                            interiorIndex++;
                        }
                    }
                }      
            }
        }

        green();

        printf("Test %i: ", test + 1);

        reset();

        if (outputSize == 0)
        {
            printf("[] | ");
        }
        else
        {
            for (int i = 0; i < outputSize; i++)
            {
                printArrayInt(output[i], outputInteriorSizes[i]);
                printf("%s", (i >= 0 && i < outputSize - 1) ? ", " : " | ");
            }
        }

        green();

        printf("Passed\n");

        reset();
    }
    
    return 0;
}

void printArrayInt(int array[ARRAY_SIZE], int sizeArray){

    for (int i = 0; i < sizeArray; i++)
    {
        printf("%s%i%s", (i == 0) ? "[" : "", array[i], (i < sizeArray - 1) ? "," : "]");
    }
}

int generateSum(int candidatesArrary[ARRAY_SIZE], int candidateArraySize, int outputArray[ARRAY_SIZE][ARRAY_SIZE], int newSizes[ARRAY_SIZE], int targetVar)
{
    for (int i = 0; i < candidateArraySize; i++)
    {
        int sum = candidatesArrary[i];
        int startIndex = 0;

        outputArray[i][startIndex] = candidatesArrary[i];
        startIndex++;

        while (sum < targetVar)
        {
            outputArray[i][startIndex] = candidatesArrary[i];
            startIndex++;

            sum += candidatesArrary[i];
        }

        newSizes[i] = (sum == targetVar) ? startIndex : startIndex - 1;

        startIndex = 0;
        sum = 0;
    }
}

bool stillDifferentLast(int array[ARRAY_SIZE], int arraySize)
{
    for (int i = arraySize - 1; i > 0; i--)
    {
        if (array[i] != array[arraySize - 1])
        {
            return true;
        }
    }

    return false;
}

int arraySum(int array[ARRAY_SIZE], int arraySize)
{
    int sum = 0;

    for (int i = 0; i < arraySize; i++)
    {
        sum += array[i];
    }
    
    return sum;
}

void appendToArray(int simpleArray[ARRAY_SIZE], int sizeSimpleArray, int bigArray[ARRAY_SIZE][ARRAY_SIZE], int sizeBigArray)
{
    for (int i = 0; i < sizeSimpleArray; i++)
    {
        bigArray[sizeBigArray][i] = simpleArray[i];
    }
}

bool simpleArrayExistInBigArray(int simpleArray[ARRAY_SIZE], int sizeSimpleArray, int bigArray[ARRAY_SIZE][ARRAY_SIZE], int sizeBigArray, int insideBigSizes[ARRAY_SIZE])
{
    int flag = true;

    for (int i = 0; i < sizeBigArray; i++)
    {
    
        if (insideBigSizes[i] == sizeSimpleArray)
        {
            for (int j = 0; j < insideBigSizes[i]; j++)
            {
                if (simpleArray[j] != bigArray[i][j])
                {
                    flag = false;
                    break;
                }
            }
        }

        if (flag == true && insideBigSizes[i] == sizeSimpleArray)
        {
            return true;
        }

        flag = true;
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