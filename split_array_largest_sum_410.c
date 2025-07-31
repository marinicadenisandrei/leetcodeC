/* Leetcode - 410. Split Array Largest Sum (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_TESTS 2
#define ARRAY_SIZE 20

void reset ();
void green ();
void yellow ();
void red ();

int splitArray(int* numsVar, int numsSizeVar, int kVar);

int main()
{
    yellow();

    printf("Leetcode - 410. Split Array Largest Sum (C language) - ");

    red();

    printf("Hard\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{7,2,5,10,8},{1,2,3,4,5}};
    int numsSize[NUMBER_OF_TESTS] = {5,5};
    int k[NUMBER_OF_TESTS] = {2,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", splitArray(nums[test], numsSize[test], k[test]));
    
        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int splitArray(int* numsVar, int numsSizeVar, int kVar)
{
    int sum = 0;
    int diff = INT_MAX;

    for (int i = 1; i < numsSizeVar; i++)
    {
        int tempSumLeft = 0;
        int tempSumRight = 0;
        
        for (int j = 0; j < i; j++)
        {
            tempSumLeft += numsVar[j];
        }
        
        for (int j = i; j < numsSizeVar; j++)
        {
            tempSumRight += numsVar[j];
        }
        
        int tempDiff = abs(tempSumLeft - tempSumRight);

        if (tempDiff < diff)
        {
            diff = tempDiff;
            sum = ((tempSumLeft < tempSumRight) ? tempSumRight : tempSumLeft);
        }
    }

    return sum;
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