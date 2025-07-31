/* Leetcode - 413. Arithmetic Slices (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int numberOfArithmeticSlices(int* numsVar, int numsSizeVar);

int main()
{
    yellow();

    printf("Leetcode - 413. Arithmetic Slices (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2,3,4},{1}};
    int numsSize[NUMBER_OF_TESTS] = {4,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", numberOfArithmeticSlices(nums[test], numsSize[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int numberOfArithmeticSlices(int* numsVar, int numsSizeVar)
{
    if (numsSizeVar < 3)
    {
        return 0;
    }

    int result = 0;

    for (int i = 0; i < numsSizeVar - 2; i++)
    {
        int diff = 0;
        int c = 0;

        for (int j = i; j < numsSizeVar; j++)
        {
            if (j == i)
            {
                diff = numsVar[j + 1] - numsVar[j];
                c++;
            }
            else if (numsVar[j + 1] - numsVar[j] == diff)
            {
                c++;
            }
            else
            {
                break;
            }
        }


        if (c >= 2)
        {
            result++;
        }

        if (c + 1 == numsSizeVar)
        {
            result++;
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