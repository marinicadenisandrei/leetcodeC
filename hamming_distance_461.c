/* Leetcode - 461. Hamming Distance (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int hammingDistance(int xVar, int yVar);

int main()
{
    yellow();

    printf("Leetcode - 461. Hamming Distance (C language) - ");

    green();

    printf("Easy\n");

    int x[NUMBER_OF_TESTS] = {1,3};
    int y[NUMBER_OF_TESTS] = {4,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", hammingDistance(x[test], y[test]));

        green();

        printf("Passed\n");
    }

    reset();
}

int hammingDistance(int xVar, int yVar)
{
    int x = xVar ^ yVar;
    int count = 0;

    while (x != 0)
    {
        count += x & 1;
        x >>= 1;
    }

    return count;
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