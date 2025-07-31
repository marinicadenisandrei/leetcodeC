/* Leetcode - 137. Single Number II (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int singleNumber(int *numsVar, int numsVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 137. Single Number II (C language) - Medium\n");

    int nums[ARRAY_SIZE][ARRAY_SIZE] = {{2,2,3,2}, {0,1,0,1,0,1,99}};
    int numsSize[ARRAY_SIZE] = {4,7};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", singleNumber(nums[test], numsSize[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int singleNumber(int *numsVar, int numsVarSize)
{
    for (int i = 0; i < numsVarSize; i++)
    {
        int occ = 0;

        for (int j = 0; j < numsVarSize; j++)
        {
            if (i != j && numsVar[i] == numsVar[j])
            {
                occ++;
            }
        }

        if (occ == 0)
        {
            return numsVar[i];
        }
        
        occ = 0;
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