/* Leetcode - 40. Combination Sum II (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void printArray(int array[ARRAY_SIZE], int sizeArray);
bool checkDuplicateIndex(int arrayIndex[ARRAY_SIZE], int arrayIndexSize);
bool checkIfSmallArrayIsInBigArray(int smallArray[ARRAY_SIZE], int sizeSmallArray, int bigArray[ARRAY_SIZE][ARRAY_SIZE], int sizeBigArray);
void sortArray(int array[ARRAY_SIZE], int sizeArray);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 40. Combination Sum II (C language) - Medium\n");

    int candidates[ARRAY_SIZE][ARRAY_SIZE] = {{10,1,2,7,6,1,5}, {2,5,2,1,2}};
    int candidates_size[ARRAY_SIZE] = {7, 5};

    int target[ARRAY_SIZE] = {8, 5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        bool flag = true;
    
        int temp[ARRAY_SIZE] = {};
        int sizeTemp = 0;

        int noDuplicates[ARRAY_SIZE][ARRAY_SIZE] = {};
        int sizeNoDuplicates = 0;

        int n = 1;

        green();

        printf("Test %i: ", test + 1);

        while (flag)
        {
            flag = false;

            int sum = 0;
            int stop = pow(candidates_size[test],n);
            int indexArray[ARRAY_SIZE] = {};

            while (stop > 0)
            {
                for (int i = 0; i < n; i++)
                {
                    temp[sizeTemp] = candidates[test][indexArray[i]];
                    sum += candidates[test][indexArray[i]];   
                    sizeTemp++;
                }
                if (sum == target[test] && checkDuplicateIndex(indexArray, n) == false && stop > 1)
                {
                    sortArray(temp, n);

                    if (checkIfSmallArrayIsInBigArray(temp, sizeTemp, noDuplicates, sizeNoDuplicates) == false)
                    {
                        for (int i = 0; i < sizeTemp; i++)
                        {
                            noDuplicates[sizeNoDuplicates][i] = temp[i];
                        }
                        sizeNoDuplicates++;
                    }

                    flag = true;
                }

                indexArray[n-1]++;

                int finder = true;

                while (finder)
                {
                    finder = false;

                    for (int i = 0; i < n; i++)
                    {
                        if (indexArray[i] == candidates_size[test])
                        {
                            indexArray[i] = 0;
                            indexArray[i-1]++;
                            finder = true;
                        }
                    }
                }
            
                if (sum < target[test])
                {
                    flag = true;
                }
                
                sum = 0;
                stop--;
                sizeTemp = 0;
            }

            reset();

            for (int i = 0; i < sizeNoDuplicates; i++)
            {
                printArray(noDuplicates[i], n);
                printf("%s", (i < sizeNoDuplicates) ? ", " : "");
            }

            n++;
            sizeTemp = 0;
            sizeNoDuplicates = 0;
        }

        printf("| ");

        green();

        printf("Passed\n");

        reset();
    }
    
    return 0;
}

void printArray(int array[ARRAY_SIZE], int sizeArray)
{
    for (int i = 0; i < sizeArray; i++)
    {
        printf("%s%i%s", (i == 0) ? "[" : "", array[i], (i < sizeArray - 1) ? ", " : "]");
    }
    
}

bool checkDuplicateIndex(int arrayIndex[ARRAY_SIZE], int arrayIndexSize)
{
    for (int i = 0; i < arrayIndexSize; i++)
    {
        for (int j = 0; j < arrayIndexSize; j++)
        {
            if (arrayIndex[i] == arrayIndex[j] && i != j)
            {
                return true;
            }
        }
        
    }
    
    return false;
}

bool checkIfSmallArrayIsInBigArray(int smallArray[ARRAY_SIZE], int sizeSmallArray, int bigArray[ARRAY_SIZE][ARRAY_SIZE], int sizeBigArray)
{
    int flag = true;

    for (int i = 0; i < sizeBigArray; i++)
    {
        flag = true;

        for (int j = 0; j < sizeSmallArray; j++)
        {
            if (smallArray[j] == bigArray[i][j])
            {
                flag = true;
            }
            else
            {
                flag = false;
                break;
            }
        }

        if (flag == true)
        {
            return true;
        }
        
    }

    return false;
}

void sortArray(int array[ARRAY_SIZE], int sizeArray)
{
    bool flag = true;

    while (flag)
    {
        flag = false;
        int temp = 0;

        for (int i = 1; i < sizeArray; i++)
        {
            if (array[i-1] > array[i])
            {
                temp = array[i-1];
                array[i-1] = array[i];
                array[i] = temp;

                flag = true;
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