/* Leetcode - 231. Power of Two (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 3

bool isPowerOfTwo(int nVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 231. Power of Two (C language) - ");

    green();

    printf("Easy\n");

    int n[NUMBER_OF_TESTS] = {1,16,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ",(isPowerOfTwo(n[test]) ? "true" : "false"));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

bool isPowerOfTwo(int nVar)
{
    int power = 0;
    int result = pow(2,power);

    while (result < nVar)
    {   
        power++;
        result = pow(2,power);
    }

    if (result == nVar)
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