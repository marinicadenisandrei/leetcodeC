/* Leetcode - 172. Factorial Trailing Zeroes (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_TESTS 3

int returnFactorialNumber(int number);
int trailingZeroes(int nVar);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 172. Factorial Trailing Zeroes (C language) - Medium\n");
    int n[NUMBER_OF_TESTS] = {3,5,0};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();
        
        int output = trailingZeroes(n[test]);
        printf("%i | ", output);

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int returnFactorialNumber(int number)
{
    int result = 1;

    for (int i = 1; i <= number; i++)
    {
        result *= i;
    }

    return result;
}

int trailingZeroes(int nVar)
{
    int factorialResult = returnFactorialNumber(nVar);
    int zeroes = 0;

    while (factorialResult > 0)
    {
        if (factorialResult % 10 == 0)
        {
            zeroes++;
        }
        
        factorialResult /= 10;
    }
    
    return zeroes;
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