/* Leetcode - 486. Predict the Winner (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 2
#define ARRAY_SIZE 20

bool predictTheWinner(int* numsVar, int numsSizeVar);
int diff(int* nums, int i, int j);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 486. Predict the Winner (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,5,2},{1,5,233,7}};
    int numsSize[NUMBER_OF_TESTS] = {3,4};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", ((predictTheWinner(nums[test], numsSize[test]) == 1) ? "true" : "false"));
    
        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

bool predictTheWinner(int* numsVar, int numsSizeVar)
{
    return diff(numsVar, 0, numsSizeVar - 1) >= 0;
}

int diff(int* nums, int i, int j)
{
    if (i == j)
        return nums[i];
    
    int takeLeft  = nums[i] - diff(nums, i + 1, j);
    int takeRight = nums[j] - diff(nums, i, j - 1);

    return takeLeft > takeRight ? takeLeft : takeRight;
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