/* Leetcode - 377. Combination Sum IV (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int CombinationSum4(int* numsVar, int numsVarSize, int targetVar);

int main()
{
    yellow();

    printf("Leetcode - 377. Combination Sum IV (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2,3},{9}};
    int numsSize[NUMBER_OF_TESTS] = {3,1};
    int target[NUMBER_OF_TESTS] = {4,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", CombinationSum4(nums[test], numsSize[test], target[test]));

        green();

        printf("Passed\n");
    }

    reset();
}

int CombinationSum4(int* numsVar, int numsVarSize, int targetVar)
{
    int* dp = (int*)calloc(targetVar + 1, sizeof(int));
    dp[0] = 1; 

    for (int i = 1; i <= targetVar; i++) {
        for (int j = 0; j < numsVarSize; j++) {
            if (i >= numsVar[j]) {
                dp[i] += dp[i - numsVar[j]];
            }
        }
    }

    int result = dp[targetVar];
    free(dp);

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
  