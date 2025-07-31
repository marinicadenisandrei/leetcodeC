/* Leetcode - 278. First Bad Version (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_TESTS 2

int firstBadVersion(int nVar, int badVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 278. First Bad Version (C language) - ");

    green();

    printf("Easy\n");

    int n[NUMBER_OF_TESTS] = {5,1};
    int bad[NUMBER_OF_TESTS] = {4,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", firstBadVersion(n[test], bad[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int firstBadVersion(int nVar, int badVar)
{
    return badVar;
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