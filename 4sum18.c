/* Leetcode - 18. 4Sum (C language) - Medium */

#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

#define CONST_LENGTH_TEMP_ARRAY 4
#define ALL_ARRAY_INITIALIZATION 50
#define NUMBER_OF_TESTS 2

void sortArray(int array[], int sizeArray);
bool arrayExistInArray(int array1[CONST_LENGTH_TEMP_ARRAY + 1], int sizeArray1, int bigArray[ALL_ARRAY_INITIALIZATION][ALL_ARRAY_INITIALIZATION], int sizeBigArray, int sizeSubArray);
bool differentIndex(int indexArray[CONST_LENGTH_TEMP_ARRAY + 1]);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 18. 4Sum (C language) - Medium\n");

    int nums[10][20] = {{1,0,-1,0,-2,2}, {2,2,2,2,2}};
    int targetTest[10] = {0,8};

    int numsSizeTest[10] = {6,5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int numsSize = numsSizeTest[test];
        int target = targetTest[test];

        int tempArray[CONST_LENGTH_TEMP_ARRAY + 1] = {};

        int output[ALL_ARRAY_INITIALIZATION][ALL_ARRAY_INITIALIZATION] = {};
        int sizeOutput = 0;

        for (int i = 0; i < numsSize; i++)
        {
            for (int j = 0; j < numsSize; j++)
            {
                for (int k = 0; k < numsSize; k++)
                {
                    for (int l = 0; l < numsSize; l++)
                    {

                        int tempIndex[CONST_LENGTH_TEMP_ARRAY + 1] = {i,j,k,l};

                        if (nums[test][i] + nums[test][j] + nums[test][k] + nums[test][l] == target && differentIndex(tempIndex) == true)
                        {
                            tempArray[0] = nums[test][i];
                            tempArray[1] = nums[test][j];
                            tempArray[2] = nums[test][k];
                            tempArray[3] = nums[test][l];

                            sortArray(tempArray, CONST_LENGTH_TEMP_ARRAY);

                            if (arrayExistInArray(tempArray, CONST_LENGTH_TEMP_ARRAY, output, sizeOutput, CONST_LENGTH_TEMP_ARRAY) == false)
                            {
                                for (int m = 0; m < CONST_LENGTH_TEMP_ARRAY; m++)
                                {
                                    output[sizeOutput][m] = tempArray[m];
                                }

                                sizeOutput++;
                            }
                        }
                    }
                }
            }
        }

        green();

        printf("Test %i: ", test + 1);

        reset();

        for (int i = 0; i < sizeOutput; i++)
        {
            printf("[ ");

            for (int j = 0; j < CONST_LENGTH_TEMP_ARRAY; j++)
            {
                printf("%i ", output[i][j]);
            }

            printf("] ");
        }

        printf("| ");

        green();

        printf("Passed\n");

        reset();
    }
    
    return 0;
}

void sortArray(int array[], int sizeArray)
{
    int temp = 0;
    bool flag = true;

    while (flag)
    {
        flag = false;

        for (int i = 1; i < sizeArray; i++)
        {
            if (array[i-1] > array[i])
            {
                temp = array[i-1];
                array[i-1] = array[i];
                array[i] = temp;

                i = 1;
                flag = true;
            }
        }
    }
}

bool arrayExistInArray(int array1[CONST_LENGTH_TEMP_ARRAY + 1], int sizeArray1, int bigArray[ALL_ARRAY_INITIALIZATION][ALL_ARRAY_INITIALIZATION], int sizeBigArray, int sizeSubArray)
{   
    bool flag = true;

    for (int i = 0; i < sizeBigArray; i++)
    {
        flag = true; 

        for (int j = 0; j < sizeSubArray; j++)
        {
            if (array1[j] != bigArray[i][j])
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

bool differentIndex(int indexArray[CONST_LENGTH_TEMP_ARRAY + 1])
{
    for (int i = 0; i < CONST_LENGTH_TEMP_ARRAY; i++)
    {
        for (int j = 0; j < CONST_LENGTH_TEMP_ARRAY; j++)
        {
            if (i != j)
            {
                if (indexArray[i] == indexArray[j])
                {
                    return false;
                }
            }
        }
    }
    
    return true;
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