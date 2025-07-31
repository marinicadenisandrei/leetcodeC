#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int minPatches(int *numsVar, int numsVarSize, int nVar);
void sortArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 330. Patching Array (C language) - ");

    red();

    printf("Hard\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,3},{1,5,10},{1,2,2}};
    int numsSize[NUMBER_OF_TESTS] = {2,3,3};
    int n[NUMBER_OF_TESTS] = {6,20,5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", minPatches(nums[test], numsSize[test], n[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

void sortArray(int *array, int arraySize)
{
    int c = 0;
    bool flag = true;
    
    while (flag)
    {
        flag = false;

        for (int i = 0; i < arraySize - 1 - c; i++)
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

int minPatches(int *numsVar, int numsVarSize, int nVar)
{
    int copyLen = numsVarSize;

    for (int i = 1; i <= nVar; i++)
    {
        int temp = i;
        bool flag = false;
        bool second = false;

        for (int j = numsVarSize - 1; j >= 0; j--)
        {
            if (temp - numsVar[j] >= 0)
            {
                temp -= numsVar[j];       
            }
        }

        for (int j = 0; j < numsVarSize; j++)
        {
            if (numsVar[j] == temp)
            {
                for (int k = 0; k < numsVarSize; k++)
                {
                    if (numsVar[k] == temp * 2)
                    {
                        second = true;
                        break;
                    }
                }
                
                flag = true;
            }
        }
        
        if (!flag && temp > 0)
        {
            numsVar[numsVarSize++] = temp;
            sortArray(numsVar, numsVarSize);
        }
        else if (!second && temp != 0)
        {
            numsVar[numsVarSize++] = temp * 2;
            sortArray(numsVar, numsVarSize);
        }
    }

    return numsVarSize - copyLen;
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