/* Leetcode - 414. Third Maximum Number (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 3
#define ARRAY_SIZE 20

void reset ();
void green ();
void yellow ();
void red ();

int thirdMax(int* numsVar, int numsSizeVar);

int main()
{
    yellow();

    printf("Leetcode - 414. Third Maximum Number (C language) - ");

    green();

    printf("Easy\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{3,2,1},{1,2},{2,2,3,1}};
    int numsSize[NUMBER_OF_TESTS] = {3,2,4};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", thirdMax(nums[test], numsSize[test]));

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

int thirdMax(int* numsVar, int numsSizeVar)
{
    int noDupl[ARRAY_SIZE] = {};
    int noDuplSize = 0;

    for (int i = 0; i < numsSizeVar; i++)
    {
        bool flag = false;

        for (int j = 0; j < noDuplSize; j++)
        {
            if (noDupl[j] == numsVar[i])
            {
                flag = true;
                break;
            }
        }
           
        if (!flag)
        {
            noDupl[noDuplSize++] = numsVar[i];
        }
    }

    int c = 0;
    int flag = true;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < noDuplSize - 1 - c; i++)
        {
            if (noDupl[i] < noDupl[i + 1])
            {
                int temp = noDupl[i];
                noDupl[i] = noDupl[i + 1];
                noDupl[i + 1] = temp;

                flag = true;
            }
        }

        c++;
    }

    return ((noDuplSize <= 2) ? noDupl[noDuplSize - 2] : noDupl[2]);
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