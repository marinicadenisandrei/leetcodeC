/* Leetcode - 15. 3Sum - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 3

void sortArray(int array[], int sizeArray);
int removeDuplucates(int array1[50][50], int sizeArray1, int array2[50][50], int sizeArray2);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 15. 3Sum - Medium\n");

    int nums[10][50] = {{-1,0,1,2,-1,-4}, {0,1,1}, {0,0,0}};
    int sizeNumsTest[10] = {6, 3, 3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int sizeNums = sizeNumsTest[test]; 

        int output[50][50] = {};
        int outputIndex = 0;

        int noDuplicatesArray[50][50] = {};
        int sizeNoDuplicatesArray = 0;

        for (int i = 0; i < sizeNums; i++)
        {
            for (int j = 0; j < sizeNums; j++)
            {
                for (int k = 0; k < sizeNums; k++)
                {
                    if (i != j && j != k && i != k)
                    {
                        if (nums[test][i] + nums[test][j] + nums[test][k] == 0)
                        {
                            output[outputIndex][0] = nums[test][i];
                            output[outputIndex][1] = nums[test][j];
                            output[outputIndex][2] = nums[test][k];

                            sortArray(output[outputIndex], 3);

                            outputIndex++;
                        }
                    }
                }
            }
        }

        sizeNoDuplicatesArray = removeDuplucates(output, outputIndex, noDuplicatesArray, sizeNoDuplicatesArray);

        green();

        printf("Test %i: ", test + 1);

        reset();

        if (sizeNoDuplicatesArray != 0)
        {
            for (int i = 0; i < sizeNoDuplicatesArray; i++)
            {
                printf("[ ");

                for (int j = 0; j < 3; j++)
                {
                    printf("%i ", noDuplicatesArray[i][j]);
                }

                printf("] ");
            }
        }
        else
        {
            printf("[] | ");
        }

        green();

        printf("Passed\n");

        reset();
    }

    return 0;
}

void sortArray(int array[], int sizeArray)
{
    int temp = 0;
    int flag = true;

    while (flag)
    {   
        flag = false;

        for (int i = 0; i < sizeArray-1; i++)
        {
            if (array[i] > array[i+1])
            {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                i = 0;
                temp = 0;
                flag = true;
            }
        }
    }
}

int removeDuplucates(int array1[50][50], int sizeArray1, int array2[50][50], int sizeArray2)
{
    bool flagDuplicate = false;
    int startIndex = 0;

    for (int i = 0; i < sizeArray1; i++)
    {
        for (int j = 0; j < sizeArray2; j++)
        {
            if (array1[i][0] == array2[j][0] && array1[i][1] == array2[j][1] && array1[i][2] == array2[j][2])
            {
                flagDuplicate = true;
                break;
            }
        }

        if (flagDuplicate == false)
        {
            array2[sizeArray2][0] = array1[i][0];
            array2[sizeArray2][1] = array1[i][1];
            array2[sizeArray2][2] = array1[i][2];

            sizeArray2++;
        }

        flagDuplicate = false;
    }

    return sizeArray2;
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