/* Leetcode - 216. Combination Sum III (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20   
#define NUMBER_OF_TESTS 3
int resultSize = 0;

int** combinationSum3(int kVar, int nVar);
void sortArray(int *array, int arraySize);
bool duplicatesElementsInArray(int *array, int arraySize);
bool duplicatesInTwoDArray(int **bigArray, int bigaArraySize, int *array, int arraySize);
void print2DArray(int **bigArray, int bigArraySize, int bigArrayInSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 216. Combination Sum III (C language) - Medium\n");

    int k[NUMBER_OF_TESTS] = {3,3,4};
    int n[NUMBER_OF_TESTS] = {7,9,1};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int **output = (int **)malloc(ARRAY_SIZE * sizeof(int *));
        for (int i = 0; i < ARRAY_SIZE; i++) {
            output[i] = (int *)malloc(ARRAY_SIZE * sizeof(int));
        }

        green();

        printf("Test %i: ", test + 1);

        reset();

        output = combinationSum3(k[test],n[test]);
        print2DArray(output, resultSize, k[test]);

        for (int i = 0; i < ARRAY_SIZE; i++) {
            free(output[i]);
        }
        free(output);

        green();

        printf("Passed\n");

        resultSize = 0;
    }

    reset();

    return 0;
}

void print2DArray(int **bigArray, int bigArraySize, int bigArrayInSize)
{
    if (bigArraySize == 0)
    {
        printf("[] | ");
        return;
    }
    
    for (int i = 0; i < bigArraySize; i++)
    {
        for (int j = 0; j < bigArrayInSize; j++)
        {
            printf("%s%i%s", ((j == 0) ? "[" : ""), bigArray[i][j], ((j < bigArrayInSize - 1) ? ", " : "]"));
        }
    }
    
    printf(" | ");
}

bool duplicatesInTwoDArray(int **bigArray, int bigaArraySize, int *array, int arraySize)
{
    for (int i = 0; i < bigaArraySize; i++)
    {
        bool flag = true;

        for (int j = 0; j < arraySize; j++)
        {
            if (bigArray[i][j] != array[j])
            {
                flag = false;
            } 
        }
        
        if (flag)
        {
            return true;
        }
    }

    return false;
}

bool duplicatesElementsInArray(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        for (int j = 0; j < arraySize; j++)
        {
            if (i != j && array[i] == array[j])
            {
                return true;
            }
        }
    }
    
    return false;
}

void sortArray(int *array, int arraySize)
{
    bool flag = true;
    int c = 0;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < arraySize - c - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;

                flag = true;
            }
        }
        
        c++;
    }  
}

int** combinationSum3(int kVar, int nVar)
{
    int numbers[ARRAY_SIZE] = {1,2,3,4,5,6,7,8,9};
    int numbersSize = 9;
    
    int **result = (int **)malloc(ARRAY_SIZE * sizeof(int *));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        result[i] = (int *)malloc(ARRAY_SIZE * sizeof(int));
    }
        
    int index1 = 0;
    int index2 = 1;

    int temp = numbers[index1];
    numbers[index1] = numbers[index2];
    numbers[index2] = temp;

    bool flag = true;
    index1 = 1;
    index2 = 2;
    
    while (flag)
    {
        flag = false;

        if (index2 < 9)
        {
            int temp = numbers[index1];
            numbers[index1] = numbers[index2];
            numbers[index2] = temp;
        }
        else
        {
            int temp = numbers[0];
            numbers[0] = numbers[8];
            numbers[8] = temp;

            index1 = -1;
            index2 = 0;
        }

        index1++;
        index2++;
        
        int tempArray[ARRAY_SIZE] = {};
        int tempArraySize = 0;

        // here
        for (int i = 0; i < numbersSize - kVar; i++)
        {
            int sum = 0; 

            for (int j = 0; j < numbersSize - 1; j++)
            {
                sum += numbers[i];
                tempArray[tempArraySize++] = numbers[i];

                for (int k = j; k < j + kVar - 1; k++)
                {
                    tempArray[tempArraySize++] = numbers[k];
                    sum += numbers[k];
                }

                if (sum == nVar && !duplicatesElementsInArray(tempArray, kVar))
                {
                    sortArray(tempArray, kVar);

                    if (!duplicatesInTwoDArray(result, resultSize, tempArray, kVar))
                    {
                        for (int k = 0; k < tempArraySize; k++)
                        {
                            result[resultSize][k] = tempArray[k];
                        }

                        resultSize++;
                    }
                }
                
                sum = 0;
                tempArraySize = 0;
            }
        }

        for (int i = 0; i < 9; i++)
        {
            if (numbers[i] != i + 1)
            {
                flag = true;
                break;
            }
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