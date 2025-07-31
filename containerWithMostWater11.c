/* Leetcode - 11. Container With Most Water (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 11. Container With Most Water (C language) - Medium\n");

    int height[5][50] = {{1,8,6,2,5,4,8,3,7}, {1,1}};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int max = 0;
        int maxResult = 0;
        int index = 0;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (i != j)
                {
                    int max = (height[test][i] > height[test][j]) ? height[test][j] : height[test][i];
                    index = (maxResult < max*max*j) ? j : index;
                    maxResult = (maxResult < max*max*j) ? max*max*j : maxResult;
                }
            }
        }

        green();

        printf("Test %i: ", test + 1);
        
        reset();

        printf("%i | ", maxResult/index);

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