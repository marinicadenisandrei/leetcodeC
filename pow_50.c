/* Leetcode - 50. Pow(x, n) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 3

float pow_functin(float x, int n);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 50. Pow(x, n) - Medium\n");

    float x[NUMBER_OF_TESTS] = {2.00000, 2.10000, 2.00000};
    int n[NUMBER_OF_TESTS] = {10, 3, -2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        float result = pow_functin(x[test], n[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%f | ", result);    

        green();

        printf("Passed\n");

        reset();
    }

    return 0;
}

float pow_functin(float x, int n)
{
    float result = 1;
    bool flag_negative = false;

    if (n < 0)
    {
        n *= -1;
        flag_negative = true;
    }
    
    for (int i = 0; i < n; i++)
    {
        result *= x;
    }

    if (flag_negative == true)
    {
        return 1/result;
    }
    
    return result;
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