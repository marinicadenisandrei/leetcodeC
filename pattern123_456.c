/* Leetcode - 456. 132 Pattern (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

bool find132pattern(int* numsVar, int numsSizeVar);

int main()
{
    yellow();

    printf("Leetcode - 456. 132 Pattern (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2,3,4},{3,1,4,2},{-1,3,2,0}};
    int numsSize[NUMBER_OF_TESTS] = {4,4,4};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", (find132pattern(nums[test], numsSize[test]) == 0) ? "false" : "true");

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

bool find132pattern(int* numsVar, int numsSizeVar)
{
    for (int i = 0; i < numsSizeVar - 2; i++)
    {
        if (numsVar[i] < numsVar[i + 2] && numsVar[i + 2] < numsVar[i + 1])
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