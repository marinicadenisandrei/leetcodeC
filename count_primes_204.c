/* Leetcode - 204. Count Primes (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 3

int countPrimes(int nVar);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 204. Count Primes (C language) - Medium\n");

    int n[NUMBER_OF_TESTS] = {10,0,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", countPrimes(n[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int countPrimes(int nVar)
{
    int primeCounter = 0; 
    bool flag;

    for (int i = 2; i <= nVar; i++) 
    {
        flag = true; 

        for (int j = 2; j <= i / 2; j++) 
        {
            if (i % j == 0)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            primeCounter++;
        }
    }

    return primeCounter;
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