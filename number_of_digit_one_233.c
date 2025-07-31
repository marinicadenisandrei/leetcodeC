/* Leetcode - 233. Number of Digit One (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 30
#define NUMBER_OF_TESTS 2

int countDigitOne(int nVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 233. Number of Digit One (C language) - ");

    red();

    printf("Hard\n");

    int n[NUMBER_OF_TESTS] = {13,0};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", countDigitOne(n[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int countDigitOne(int nVar)
{
    char bigString[ARRAY_SIZE];
    int count = 0;

    for (int i = 0; i <= nVar; i++)
    {
        char temp[10];
        sprintf(temp, "%d", i);
        strcat(bigString, temp);
        temp[0] = '\0';
    }

    for (int i = 0; i < strlen(bigString); i++)
    {
        count += ((bigString[i] == '1') ? 1 : 0);
    }
    
    return count;
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