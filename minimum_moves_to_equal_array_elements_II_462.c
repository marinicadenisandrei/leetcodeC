
/* Leetcode - 462. Minimum Moves to Equal Array Elements II (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int minMoves2(int *numsVar, int numsSizeVar);

int main()
{   
    yellow();

    printf("Leetcode - 462. Minimum Moves to Equal Array Elements II (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2,3},{1,10,2,9}};
    int numsSize[NUMBER_OF_TESTS] = {3,4};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", minMoves2(nums[test], numsSize[test]));

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

int minMoves2(int *numsVar, int numsSizeVar)
{
    int result = INT_MAX;

    for (int i = 0; i < numsSizeVar; i++)
    {
        int tempMoves = 0;

        for (int j = 0; j < numsSizeVar; j++)
        {
            if (i != j)
            {
                tempMoves += abs(numsVar[i] - numsVar[j]);
            }
        }

        result = ((result > tempMoves) ? tempMoves : result);
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