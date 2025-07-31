/* Leetcode - 55. Jump Game (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

bool jumpGame(int array[ARRAY_SIZE], int arraySize, int starter);

int main(void)
{
    yellow();

    printf("Leetcode - 55. Jump Game (C language) - Medium\n");

    int nums[ARRAY_SIZE][ARRAY_SIZE] = {{2,3,1,1,4}, {3,2,1,0,4}};
    int nums_size[ARRAY_SIZE] = {5, 5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        bool flag = false;

        flag = jumpGame(nums[test], nums_size[test], 0);
        flag = (flag == false) ? jumpGame(nums[test], nums_size[test], 1) : true;

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s", ((flag == true) ? "true | " : "false | "));

        green();

        printf("Passed\n");

        reset();
    }
    
    return 0;
}

bool jumpGame(int array[ARRAY_SIZE], int arraySize, int starter)
{
    for (int i = starter; i < arraySize;)
    {
        i += array[i];

        if (array[i] == 0 && i != arraySize - 1)
        {
            return false;
        }

        if (i == arraySize - 1)
        {
            return true;
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