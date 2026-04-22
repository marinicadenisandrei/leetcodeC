/* Leetcode - 464. Can I Win (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

bool canIWin(int maxChoosableIntegerVar, int desiredTotalVar);

int main()
{
    yellow();

    printf("Leetcode - 464. Can I Win (C language) - Medium\n");

    int maxChoosableInteger[NUMBER_OF_TESTS] = {10,10,10};
    int desiredTotal[NUMBER_OF_TESTS] = {11,0,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", ((canIWin(maxChoosableInteger[test], desiredTotal[test]) == 1) ? "true" : "false"));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

bool canIWin(int maxChoosableIntegerVar, int desiredTotalVar)
{
    if (desiredTotalVar < maxChoosableIntegerVar)
    {
        return true;
    }

    if (1 + maxChoosableIntegerVar >= desiredTotalVar)
    {
        return false;
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