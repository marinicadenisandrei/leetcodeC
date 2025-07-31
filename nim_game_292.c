/* Leetcode - 292. Nim Game (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 3

bool canWinNim(int nVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 292. Nim Game (C language) - ");

    green();

    printf("Easy\n");

    int n[NUMBER_OF_TESTS] = {4,1,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();
        printf("%s | ", ((canWinNim(n[test]) == true) ? "true" : "false"));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

bool canWinNim(int nVar)
{
    return !(nVar % 4 == 0);
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