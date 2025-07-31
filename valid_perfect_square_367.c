/* Leetcode - 367. Valid Perfect Square (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

bool IsPerfectSquare(int numVar);

int main()
{
    yellow();

    printf("Leetcode - 367. Valid Perfect Square (C language) - ");

    green();

    printf("Easy\n");

    int num[NUMBER_OF_TESTS] = {16,14};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", (IsPerfectSquare(num[test]) ? "true" : "false"));

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

bool IsPerfectSquare(int numVar)
{
    for (int i = 0; i < numVar / 2; i++)
    {
        if (i * i == numVar)
        {
            return true;
        }   
    }
    

    return false;
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