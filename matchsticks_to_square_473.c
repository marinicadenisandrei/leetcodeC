/* Leetcode - 473. Matchsticks to Square (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

bool makesquare(int matchsticksVar[ARRAY_SIZE], int matchsticksSizeVar);

int main()
{
    yellow();

    printf("Leetcode - 473. Matchsticks to Square (C language) - Medium\n");

    int matchsticks[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,1,2,2,2},{3,3,3,3,4}};
    int matchsticksSize[NUMBER_OF_TESTS] = {5,5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();
        
        printf("Test %i: ", (test + 1));

        reset();

        printf("%s | ", (makesquare(matchsticks[test], matchsticksSize[test]) ? "true" : "false"));

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

bool makesquare(int matchsticksVar[ARRAY_SIZE], int matchsticksSizeVar)
{
    int sum = 0;
    int side = 0;
    int square[4] = {0,0,0,0};

    for (int i = 0; i < matchsticksSizeVar; i++)
    {
        sum += matchsticksVar[i];
    }

    side = (int) sum / 4;

    for (int i = 0; i < 4; i++)
    {
        int acc = 0;

        for (int j = 0; j < matchsticksSizeVar; j++)
        {
            acc += matchsticksVar[j];
            
            if (acc >= side)
            {
                break;
            }
        }
    
        if (acc > side)
        {
            return false;
        }        
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