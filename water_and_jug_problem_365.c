/* Leetcode - 365. Water and Jug Problem (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();


bool CanMeasureWater(int xVar, int yVar, int targetVar);

int main()
{
    yellow();

    printf("Leetcode - 365. Water and Jug Problem (C language) - Medium\n");

    int x[NUMBER_OF_TESTS] = {3,2,1};
    int y[NUMBER_OF_TESTS] = {5,6,2};
    int target[NUMBER_OF_TESTS] = {4,5,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", ((CanMeasureWater(x[test], y[test], target[test])) ? "true" : "false"));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

bool CanMeasureWater(int xVar, int yVar, int targetVar)
{
    return ((xVar + yVar == targetVar || xVar == targetVar || yVar == targetVar) ? true : false);
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