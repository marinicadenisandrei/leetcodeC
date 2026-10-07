/* Leetcode - 493. Reverse Pairs (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int reversePairs(int* numsVar, int numsSizeVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 493. Reverse Pairs (C language) - ");

    red();

    printf("Hard\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,3,2,3,1},{2,4,3,5,1}};
    int numsSize[NUMBER_OF_TESTS] = {5,5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", (test + 1));

        reset();

        printf("%i | ", reversePairs(nums[test], numsSize[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int reversePairs(int* numsVar, int numsSizeVar)
{
    int result = 0;

    for (int i = 0; i < numsSizeVar; i++)
    {
        for (int j = i + 1; j < numsSizeVar; j++)
        {
            if (numsVar[i] > 2 * numsVar[j])
            {
                result++;
            }
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