/* Leetcode - 403. Frog Jump (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

bool canCross(int* stonesVar, int stonesSizeVar);

int main()
{
    yellow();

    printf("Leetcode - 403. Frog Jump (C language) - ");

    red();

    printf("Hard\n");

    int stones[NUMBER_OF_TESTS][ARRAY_SIZE] = {{0,1,3,5,6,8,12,17},{0,1,2,3,4,8,9,11}};
    int stonesSize[NUMBER_OF_TESTS] = {8,8};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s", ((canCross(stones[test], stonesSize[test])) ? "true | " : "false | "));

        green();

        printf("Passed\n");
    }

    reset();
}

bool canCross(int* stonesVar, int stonesSizeVar)
{
    int historyJump = 0;
    int jumpNo = 1;

    for (int i = 0; i < stonesSizeVar; i++)
    {
        if (historyJump == stonesVar[i + 1] - stonesVar[i])
        {
            jumpNo--;
        }
    
        if (stonesVar[i + 1] - stonesVar[i] <= jumpNo)
        {
            jumpNo++;
        }
        else
        {
            return false;
        }

        historyJump = stonesVar[i + 1] - stonesVar[i];
    }

    return true;
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