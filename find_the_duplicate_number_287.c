/* Leetcode - 287. Find the Duplicate Number (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int findDuplicate(int *numsVar, int numsVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 287. Find the Duplicate Number (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,3,4,2,2},{3,1,3,4,2},{3,3,3,3,3}};
    int numsSize[NUMBER_OF_TESTS] = {5,5,5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", findDuplicate(nums[test], numsSize[test]));

        green();

        printf("Passed\n");    
    }

    reset();
    
    return 0;
}

int findDuplicate(int *numsVar, int numsVarSize)
{
    for (int i = 0; i < numsVarSize; i++)
    {
        for (int j = 0; j < numsVarSize; j++)
        {
            if (i != j && numsVar[i] == numsVar[j])
            {
                return numsVar[i];
            }       
        }        
    }
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