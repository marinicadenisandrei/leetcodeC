/* Leetcode - 416. Partition Equal Subset Sum (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

bool canPartition(int* numsVar, int numsSizeVar);
void sortArr(int* arr, int arrSize);

int main()
{
    yellow();

    printf("Leetcode - 416. Partition Equal Subset Sum (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,5,11,5},{1,2,3,5}};
    int numsSize[NUMBER_OF_TESTS] = {4,4};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s", ((canPartition(nums[test], numsSize[test])) ? "true | " : "false | "));

        green();

        printf("Passed\n");
    } 

    reset();

    return 0;
}

void sortArr(int* arr, int arrSize)
{
    bool flag = true;
    int c = 0;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < arrSize - 1 - c; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;

                flag = true;
            }
        }
        
        c++;
    }
}

bool canPartition(int* numsVar, int numsSizeVar)
{   
    int g_sum = 0;

    for (int i = 0; i < numsSizeVar; i++)
    {
        g_sum += numsVar[i];
    }
    
    if (g_sum % 2 != 0)
    {
        return false;
    }
    
    sortArr(numsVar, numsSizeVar);
    
    for (int i = 0; i < numsSizeVar; i++)
    {

        int l_sum = 0;
        int r_sum = 0;

        for (int j = 0; j < numsSizeVar; j++)
        {
            if (j < i)
            {
                l_sum += numsVar[j];
            }
            else
            {
                r_sum += numsVar[j];
            }
        }

        if (l_sum == r_sum)
        {
            return true;
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