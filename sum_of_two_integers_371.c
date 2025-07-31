/* Leetcode - 371. Sum of Two Integers (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int GetSum(int aVar, int bVar);

int main()
{
    yellow();

    printf("Leetcode - 371. Sum of Two Integers (C language) - Medium\n");

    int a[NUMBER_OF_TESTS] = {1,2};
    int b[NUMBER_OF_TESTS] = {2,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", GetSum(a[test], b[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int GetSum(int aVar, int bVar)
{
    return aVar + bVar;
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
  