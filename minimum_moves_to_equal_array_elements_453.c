/* Leetcode - 453. Minimum Moves to Equal Array Elements (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TEST 2

void reset ();
void green ();
void yellow ();
void red ();

int minMoves(int* nums, int numsSize);

int main()
{
    yellow();

    printf("Leetcode - 453. Minimum Moves to Equal Array Elements (C language) - Medium\n");

    int nums[NUMBER_OF_TEST][ARRAY_SIZE] = {{1,2,3},{1,1,1}};
    int numsSize[NUMBER_OF_TEST] = {3,3};

    for (int test = 0; test < NUMBER_OF_TEST; test++)
    {
        green();
        
        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", minMoves(nums[test], numsSize[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int minMoves(int* nums, int numsSize)
{
    int max = 0;
    int result = 0;

    for (int i = 0; i < numsSize; i++)
    {
        max = ((max < nums[i]) ? nums[i] : max);
    }
    
    for (int i = 0; i < numsSize; i++)
    {
        result += max - nums[i];   
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