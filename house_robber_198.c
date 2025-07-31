/* Leetcode - 198. House Robber (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20 
#define NUMBER_OF_TESTS 2

int rob(int *numsVar, int numsVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();
    
    printf("Leetcode - 198. House Robber (C language) - Medium\n");

    int nums[ARRAY_SIZE][ARRAY_SIZE] = {{1,2,3,1},{2,7,9,3,1}};
    int numsSize[ARRAY_SIZE] = {4,5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int result = rob(nums[test], numsSize[test]);
        printf("%i | ", result);

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int rob(int *numsVar, int numsVarSize)
{
    int robberSum = 0;
    int maxVar = 0;


    for (int i = 0; i < numsVarSize; i++)
    {
        for (int j = i; j < numsVarSize; j += 2)
        {
            robberSum += numsVar[j];
        }
        
        maxVar = ((maxVar < robberSum) ? robberSum : maxVar);
        robberSum = 0;
    }

    return maxVar;
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