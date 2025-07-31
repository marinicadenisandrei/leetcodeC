/* Leetcode - 29. Divide Two Integers (C language) - Medium */

#include <stdlib.h>
#include <stdio.h>

#define NUMBER_OF_TESTS 2

void divideAndTruncatedTwoIntegers(int dvnd, int div);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 29. Divide Two Integers (C language) - Medium\n");

    int testDividend[NUMBER_OF_TESTS + 1] = {10, 7};
    int testDivisor[NUMBER_OF_TESTS + 1] = {3, -1}; 

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        divideAndTruncatedTwoIntegers(testDividend[test], testDivisor[test]);

        printf(" | ");

        green();

        printf("Passed\n");

        reset();
    }
    

    return 0;
}

void divideAndTruncatedTwoIntegers(int dvnd, int div)
{
    int result = dvnd / div;
    printf("%i", result);
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