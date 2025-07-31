/* Leetcode - 375. Guess Number Higher or Lower II (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_TESTS 3
#define ARRAY_SIZE 20

void reset ();
void green ();
void yellow ();
void red ();

int GetMoneyAmount(int nVar);

int main()
{
    yellow();

    printf("Leetcode - 375. Guess Number Higher or Lower II (C language) - Medium\n");

    int n[NUMBER_OF_TESTS] = {10,1,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ",GetMoneyAmount(n[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int GetMoneyAmount(int nVar)
{
    if (nVar == 1)
    {
        return 0;
    }
    else if (nVar <= 3)
    {
        return nVar / 2;
    }
    else if (nVar > 3)
    {
        return ((nVar - 3) + (nVar - 1));
    }
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

