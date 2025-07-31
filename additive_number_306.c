/* Leetcode - 306. Additive Number (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

bool isAdditiveNumber(char *numberVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 306. Additive Number (C language) - Medium\n");

    char number[NUMBER_OF_TESTS][ARRAY_SIZE] = {"112358", "199100199"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s", isAdditiveNumber(number[test]) ? "true | " : "false | ");

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

bool isAdditiveNumber(char *numberVar)
{
    for (int i = 0; i < strlen(numberVar) - 2; i++)
    {
        int result = (numberVar[i + 2] - '0') - ((numberVar[i + 1] - '0') + (numberVar[i] - '0'));
        if (result > 0)
        {
            return false;
        }
    }

    return true;
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