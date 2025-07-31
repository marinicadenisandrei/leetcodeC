/* Leetcode - 53. Maximum Subarray (C language) - Medium */

#include <stdlib.h>
#include <stdio.h>

#define NUMBER_OF_TESTS 3
#define ARRAY_SIZE 20

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 53. Maximum Subarray (C language) - Medium\n");

    int nums[ARRAY_SIZE][ARRAY_SIZE] = {{-2,1,-3,4,-1,2,1,-5,4}, {1}, {5,4,-1,7,8}};
    int nums_size[ARRAY_SIZE] = {9, 1, 5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int sum = 0;
        int result = 0;

        for (int i = 0; i < nums_size[test]; i++)
        {
            for (int j = i; j < nums_size[test]; j++)
            {
                sum += nums[test][j];
                result = (result < sum) ? sum : result;
            }

            sum = 0;
        }

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", result);

        green();

        printf("Passed\n");

        reset();
    }
    
    return 0;
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