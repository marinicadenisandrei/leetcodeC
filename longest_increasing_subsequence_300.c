/* Leetcode - 300. Longest Increasing Subsequence (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int lengthOfLIS(int *numsVar, int numsVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 300. Longest Increasing Subsequence (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{10,9,2,5,3,7,101,18},{0,1,0,3,2,3},{7,7,7,7,7,7,7}};
    int numsSize[NUMBER_OF_TESTS] = {8,6,7};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);
        
        reset();
        
        printf("%i | ", lengthOfLIS(nums[test], numsSize[test]));
        
        green();

        printf("Passed\n");        
    }

    reset();
    
    return 0;
}

int lengthOfLIS(int *numsVar, int numsVarSize)
{
    bool flag = true;

    for (int i = 1; i < numsVarSize; i++)
    {
        if (numsVar[i] != numsVar[0])
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        return 1;
    }
    
    int max = 0;

    for (int i = 0; i < numsVarSize; i++)
    {
        int history = numsVar[i];
        int counter = 0;

        for (int j = i + 1; j < numsVarSize; j++)
        {
            if (history <= numsVar[j])
            {
                history = numsVar[j];
                counter++;
            }   
        }

        max = ((max < counter) ? counter : max);
    }

    return max + 1;
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