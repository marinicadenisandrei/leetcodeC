#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define NUMBER_OF_TESTS 2

bool isHappy(int nVar);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 202. Happy Number (C language) - ");

    green();

    printf("Easy\n");

    int n[NUMBER_OF_TESTS] = {19,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ",(isHappy(n[test]) == 1) ? "true" : "false");

        green();

        printf("Passed\n");
    }

    reset();
            
    return 0;
}

bool isHappy(int nVar)
{
    int number = 0;
    int counter = 0;
    int stoper = nVar * nVar;

    while (number != 1)
    {
        char str[20];
        sprintf(str, "%d", nVar);

        for (int i = 0; i < strlen(str); i++)
        {
            number += pow((str[i] - '0'), 2);   
        }

        nVar = number;

        if (number == 1)
        {
            return true;
        }

        if (nVar == stoper)
        {
            counter++;
        }

        if (counter > 2)
        {
            return false;
        }
        
        number = 0;
        counter++;
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
