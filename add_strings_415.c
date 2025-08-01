/* Leetcode - 415. Add Strings (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();


char* addStrings(char* num1Var, char* num2Var);

int main()
{
    yellow();

    printf("Leetcode - 415. Add Strings (C language) - ");

    green();

    printf("Easy\n");

    char num1[NUMBER_OF_TESTS][ARRAY_SIZE] = {"11","456","0"};
    char num2[NUMBER_OF_TESTS][ARRAY_SIZE] = {"123","77","0"};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", addStrings(num1[test], num2[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

char* addStrings(char* num1Var, char* num2Var)
{
    int val1 = (int)strtol(num1Var, NULL, 10);
    int val2 = (int)strtol(num2Var, NULL, 10);
    int result = val1 + val2;

    char *buf = malloc(22);
    snprintf(buf, 22, "%ld", result);

    return buf;
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