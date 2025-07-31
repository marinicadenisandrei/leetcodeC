/* Leetcode - 313. Super Ugly Number (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int nthSuperUglyNumber(int nVar, int *primesVar, int primesVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 313. Super Ugly Number (C language) - Medium\n");

    int n[NUMBER_OF_TESTS] = {12,1};
    int primes[NUMBER_OF_TESTS][ARRAY_SIZE] = {{2,7,13,19},{2,3,5}};
    int primesSize[NUMBER_OF_TESTS] = {4,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", nthSuperUglyNumber(n[test], primes[test], primesSize[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int nthSuperUglyNumber(int nVar, int *primesVar, int primesVarSize)
{
    int result[ARRAY_SIZE] = {1};
    int resultSize = 1;

    int checkNumber = 2;

    while (resultSize < nVar)
    {
        bool flag = true;

        for (int i = 2; i <= checkNumber; i++)
        {
            if (checkNumber % i == 0)
            {
                flag = false;

                for (int j = 0; j < primesVarSize; j++)
                {
                    if (i % primesVar[j] == 0)
                    {
                        flag = true;
                        break;
                    }
                }

                if (!flag)
                {
                    break;
                }
            }
        }

        if (flag)
        {
            result[resultSize++] = checkNumber;
        }

        checkNumber++;
    }

    
    return result[resultSize - 1];
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