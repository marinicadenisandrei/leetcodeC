/* Leetcode - 45. Jump Game II (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 45. Jump Game II (C language) - Medium\n");

    int nums[ARRAY_SIZE][ARRAY_SIZE] = {{2,3,1,1,4}, {2,3,0,1,4}};
    int nums_size[ARRAY_SIZE] = {5, 5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int temp[ARRAY_SIZE][ARRAY_SIZE] = {{2}};
        int size_temp = 1;
        int size_last_temp = 2;

        bool flag = false;

        for (int i = 0; i < nums_size[test] && flag == false; i++)
        {
            int indexAppend = 0;

            for (int j = 0; j < size_last_temp; j++)
            {
                int depth = temp[size_temp - 1][j] % 10;

                if (depth == nums[test][nums_size[test] - 1])
                {
                    flag = true;

                    green();

                    printf("Test %i: ", test + 1);

                    reset();

                    printf("%i | ", i);

                    green();

                    printf("Passed\n");

                    break;
                }
                
                for (int k = i + 1; k <= depth + i; k++)
                {
                    char intToString[ARRAY_SIZE] = "";
                    sprintf(intToString, "%d", temp[size_temp - 1][j]);

                    char actual[2] = "";
                    sprintf(actual, "%d", nums[test][k]);

                    strcat(intToString, actual);

                    int result = atoi(intToString);

                    // printf("%i\n", result);

                    temp[size_temp][indexAppend] = result;
                    indexAppend++;
                }
            }

            size_last_temp = indexAppend;
            size_temp++;
        }
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



