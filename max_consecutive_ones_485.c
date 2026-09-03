/* Leetcode - 485. Max Consecutive Ones (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_TESTS 2
#define ARRAY_SIZE 20

int findMaxConsecutiveOnes(int *numsVar, int numsSizeVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 485. Max Consecutive Ones (C language) - ");

    green();

    printf("Easy\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,1,0,1,1,1},{1,0,1,1,0,1}};
    int numsSize[NUMBER_OF_TESTS] = {6,6};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", findMaxConsecutiveOnes(nums[test], numsSize[test]));
    
        green();

        printf("Passed\n");
    }

    reset();
}

int findMaxConsecutiveOnes(int *numsVar, int numsSizeVar)
{
    int result = 0;
    int temp = 0;

    for (int i = 0; i < numsSizeVar; i++)
    {
        if (numsVar[i] == numsVar[i + 1] && numsVar[i] == 1)
        {
            temp++;
        }
        else
        {
            result = ((result < temp) ? temp : result);
            temp = 0;
        }
    }    

    return result + 1;
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