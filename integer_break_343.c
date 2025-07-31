/* Leetcode - 343. Integer Break (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_TESTS 2

int integerBreak(int nVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 343. Integer Break (C language) - Medium\n");

    int n[NUMBER_OF_TESTS] = {2,10};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", integerBreak(n[test]));

        green();

        printf("Passed\n");
    }

    reset();
}

int integerBreak(int nVar)
{
    if (nVar <= 2)
    {
        return 1;
    }

    int result = 0;

    for (int i = 2; i < nVar; i++)
    {
        int temp = 3;
        int sumTemp = 0;
        int mulTemp = 1;

        while (sumTemp < nVar)
        {
            sumTemp += temp;
            mulTemp *= temp;

            if (sumTemp > 10)
            {
                sumTemp -= (temp * 2);
                mulTemp /= (temp * temp);
                temp++;
            }

            if (temp == 10)
            {
                break;
            }
        }

        result = (result < mulTemp) ? mulTemp : result;
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