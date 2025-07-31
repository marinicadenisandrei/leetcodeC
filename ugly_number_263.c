/* Leetcode - 263. Ugly Number (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

bool isUgly(int nVar);
bool isPrime(int number);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 263. Ugly Number (C language) - ");

    green();

    printf("Easy\n");

    int n[ARRAY_SIZE] = {6,1,14};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", ((isUgly(n[test])) ? "true" : "false"));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

bool isPrime(int number)
{
    if (number == 1)
    {
        return true;
    }
    
    int primeFactors[ARRAY_SIZE] = {2,3,5};
    int primeFactorsSize = 3;

    for (int i = 0; i < primeFactorsSize; i++)
    {
        for (int j = 0; j < primeFactorsSize; j++)
        {
            if (primeFactors[i] * primeFactors[j] == number)
            {
                return true;
            }
        }
    }
    
    return false;
}

bool isUgly(int nVar)
{
    return isPrime(nVar);
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