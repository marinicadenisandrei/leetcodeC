/* Leetcode - 397. Integer Replacement (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_TESTS 2

int integerReplacement(int nVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{   
    yellow();

    printf("Leetcode - 397. Integer Replacement (C language) - Medium\n");

    int n[NUMBER_OF_TESTS] = {8,7,4};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", integerReplacement(n[test]));

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

int integerReplacement(int nVar)
{
    int counter = 0;

    while (nVar > 1)
    {
        if (nVar % 2 == 0)
        {
            nVar /= 2;
        }
        else 
        {
            if (((nVar + 1) / 2) % 2 == 0)
            {
                nVar++;
            }
            else
            {
                nVar--;
            }
        }

        counter++;
    }

    return counter;
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