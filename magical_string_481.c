/* Leetcode - 481. Magical String (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int magicalString(int nVar);

int main()
{
    yellow();

    printf("Leetcode - 481. Magical String (C language) - Medium\n");

    int n[NUMBER_OF_TESTS] = {6,1};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", magicalString(n[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int magicalString(int nVar)
{
    int result = 1;

    int s[ARRAY_SIZE] = {1,2,2};
    int sSize = 3;

    while (sSize <= nVar)
    {
        int candidate = 0;
        int occ = s[sSize - 2];

        if (s[sSize - 1] == 1)
        {
            candidate = 2;
        }
        else 
        {
            candidate = 1;
        }

        for (int i = 0; i < occ; i++)
        {
            s[sSize++] = candidate;
        }

        if (candidate == 1)
        {
            result++;
        }
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