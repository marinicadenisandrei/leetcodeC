/* Leetcode - 477. Total Hamming Distance (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int totalHammingDistance(int *numsVar, int numsSizeVar);

int main()
{
    yellow();

    printf("Leetcode - 477. Total Hamming Distance (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{4,14,2},{4,14,4}};
    int numsSize[NUMBER_OF_TESTS] = {3,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", totalHammingDistance(nums[test], numsSize[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int totalHammingDistance(int *numsVar, int numsSizeVar)
{
    int result = 0;

    for (int i = 0; i < numsSizeVar; i++)
    {
        for (int j = i + 1; j < numsSizeVar; j++)  
        {
            int diff = numsVar[i] ^ numsVar[j];

            for (int k = 0; k < 32; k++)
            {
                if ((diff >> k) & 1) result++;
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