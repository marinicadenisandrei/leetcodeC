/* Leetcode - 164. Maximum Gap (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int maximumGap(int *numsVar, int numsSizewVar);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 164. Maximum Gap (C language) - Medium\n");

    int nums[ARRAY_SIZE][ARRAY_SIZE] = {{3,6,9,1},{10}};
    int numsSize[ARRAY_SIZE] = {4,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | " ,maximumGap(nums[test], numsSize[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int maximumGap(int *numsVar, int numsSizewVar)
{
    int max = 0;

    for (int i = 0; i < numsSizewVar - 1; i++)
    {
        max = ((numsVar[i] < numsVar[i + 1] && (numsVar[i + 1] - numsVar[i] > max)) ? numsVar[i + 1] - numsVar[i] : max);        
    }

    return max;
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