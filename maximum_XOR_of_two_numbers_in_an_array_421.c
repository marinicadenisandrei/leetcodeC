/* Leetcode - 421. Maximum XOR of Two Numbers in an Array (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int findMaximumXOR(int* numsVar, int numsSizeVar);

int main()
{
    yellow();

    printf("Leetcode - 421. Maximum XOR of Two Numbers in an Array (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{3,10,5,25,2,8},{14,70,53,83,49,91,36,80,92,51,66,70}};
    int numsSize[NUMBER_OF_TESTS] = {6,12};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", findMaximumXOR(nums[test], numsSize[test]));

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

int findMaximumXOR(int* numsVar, int numsSizeVar)
{
    int result = 0;

    for (int i = 0; i < numsSizeVar; i++)
    {
        for (int j = 0; j < numsSizeVar; j++)
        {
            if (i != j)
            {
                int xor = numsVar[i] ^ numsVar[j];
                result = ((result < xor) ? xor : result);   
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