/* Leetcode - 374. Guess Number Higher or Lower (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_TESTS 3

int GuessNumber(int nVar, int pickVar);
int guess(int number, int pickVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 374. Guess Number Higher or Lower (C language) - ");

    green();

    printf("Easy\n");

    int n[NUMBER_OF_TESTS] = {10,1,2};
    int pick[NUMBER_OF_TESTS] = {6,1,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", GuessNumber(n[test], pick[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int guess(int number, int pickVar)
{
    return ((number > pickVar) ? -1 : ((number < pickVar) ? 1 : 0));
}

int GuessNumber(int nVar, int pickVar)
{
    int left = 1;
    int right = nVar;

    while (left < nVar)
    {
        int mid = (left + right) / 2;
        int result = guess(mid, pickVar);

        if (result == 0)
        {
            return mid;
        }
        else if (result == -1)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
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