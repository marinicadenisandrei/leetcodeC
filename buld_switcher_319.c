/* Leetcode - 319. Bulb Switcher (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int bulbSwitch(int nVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 319. Bulb Switcher (C language) - Medium\n");

    int n[NUMBER_OF_TESTS] = {3,0,1};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", bulbSwitch(n[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int bulbSwitch(int nVar)
{
    int bulbs[ARRAY_SIZE] = {};
    int result = 0;

    for (int i = 0; i < nVar; i++)
    {
        bulbs[i] = 1;
    }
    
    for (int i = 2; i <= nVar; i++)
    {
        bulbs[i - 1] = ((bulbs[i - 1] == 1) ? 0 : 1);
    }
    
    for (int i = 0; i < nVar; i++)
    {
        result += ((bulbs[i] == 1) ? 1 : 0);
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