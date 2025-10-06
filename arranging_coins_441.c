#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int arrangeCoins(int nVar);

int main()
{
    yellow();
    
    printf("Leetcode - 441. Arranging Coins (C language) - ");

    green();

    printf("Easy\n");

    int n[NUMBER_OF_TESTS] = {3,8};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", arrangeCoins(n[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int arrangeCoins(int nVar)
{
    int counter = 1;
    int level = 0;

    while (counter <= nVar)
    {
        nVar -= counter;
        level++;
        counter++;
    }

    return level;
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