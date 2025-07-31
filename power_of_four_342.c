#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 3

bool isPowerOfFour(int nVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 342. Power of Four (C language) - ");

    green();

    printf("Easy\n");

    int n[NUMBER_OF_TESTS] = {16,5,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", ((isPowerOfFour(n[test]) == 1) ? "true" : "false"));

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

bool isPowerOfFour(int nVar) {
    return (nVar > 0) && ((nVar & (nVar - 1)) == 0) && (nVar & 0x55555555);
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