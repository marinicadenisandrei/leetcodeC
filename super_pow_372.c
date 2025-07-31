/* Leetcode - 372. Super Pow (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

int SuperPow(int aVar, int *bVar, int bVarSize);

int main()
{
    yellow();

    printf("Leetcode - 372. Super Pow (C language) - Medium\n");

    int a[NUMBER_OF_TESTS] = {2,2,1};

    int b[NUMBER_OF_TESTS][ARRAY_SIZE] = {{3},{1,0},{4,3,3,8,5,2}};
    int bSize[NUMBER_OF_TESTS] = {1,2,6};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", SuperPow(a[test], b[test], bSize[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int SuperPow(int aVar, int *bVar, int bVarSize)
{
    char powerFormation[ARRAY_SIZE] = "";

    for (int i = 0; i < bVarSize; i++)
    {
        powerFormation[i] = bVar[i] + '0';
    }

    powerFormation[bVarSize + 1] = '\0';

    int powerVar = atoi(powerFormation);
    
    return pow(aVar, powerVar);
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