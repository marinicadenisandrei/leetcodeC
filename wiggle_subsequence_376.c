/* Leetcode - 376. Wiggle Subsequence (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 3
#define ARRAY_SIZE 20

int WiggleMaxLength(int *numsVar, int numsVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 376. Wiggle Subsequence (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,7,4,9,2,5},{1,17,5,10,13,15,10,5,16,8},{1,2,3,4,5,6,7,8,9}};
    int numsSize[NUMBER_OF_TESTS] = {6,10,9};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", WiggleMaxLength(nums[test], numsSize[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int WiggleMaxLength(int *numsVar, int numsVarSize)
{
    bool flag = true;

    while (flag)
    {
        flag = false;

        for (int i = 1; i < numsVarSize; i++)
        {
            if (((i - 1) % 2 == 0 && numsVar[i] - numsVar[i - 1] < 0) || ((i - 1) % 2 == 1 && numsVar[i] - numsVar[i - 1] > 0))
            {
                for (int j = i - 1; j < numsVarSize; j++)
                {
                    numsVar[j] = numsVar[j + 1];
                }
                
                numsVarSize--;
                flag = true;
                break;
            }
        }
    }
    
    return numsVarSize;
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