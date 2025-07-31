/* Leetcode - 326. Power of Three (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 3

bool isPowerOfThree(int nVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 326. Power of Three (C language) - ");

    green();

    printf("Easy\n");

    int n[NUMBER_OF_TESTS] = {27,0,-1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", ((isPowerOfThree(n[test]) == 1) ? "true" : "false"));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

bool isPowerOfThree(int nVar)
{
    nVar *= ((nVar < 0) ? -1 : 1);

    if (nVar < 3)
    {
        return false;
    }

    while (nVar > 1)
    {
        nVar /= 3;
    }

    if (nVar == 1.0)
    {
        return true;
    }
    
    return false;
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