/* Leetcode - 215. Kth Largest Element in an Array (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int findKthLargest(int *numsVar, int numsVarSize, int kVar);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 215. Kth Largest Element in an Array (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{3,2,1,5,6,4},{3,2,3,1,2,4,5,5,6}}; 
    int numsSize[NUMBER_OF_TESTS] = {6,9};
    int k[NUMBER_OF_TESTS] = {2,4};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", findKthLargest(nums[test], numsSize[test], k[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int findKthLargest(int *numsVar, int numsVarSize, int kVar)
{
    bool flag = true;
    int counter = 0;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < numsVarSize - 1 - counter; i++)
        {
            if (numsVar[i] > numsVar[i + 1])
            {
                int temp = numsVar[i];
                numsVar[i] = numsVar[i + 1];
                numsVar[i + 1] = temp;

                flag = true;
            }
        }

        counter++;
    }

    return numsVar[numsVarSize - kVar];
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