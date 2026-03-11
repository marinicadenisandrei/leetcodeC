/* Leetcode - 459. Repeated Substring Pattern (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

bool repeatedSubstringPattern(char *sVar);

int main()
{
    yellow();

    printf("Leetcode - 459. Repeated Substring Pattern (C language) - ");

    green();

    printf("Easy\n");

    char s[NUMBER_OF_TESTS][ARRAY_SIZE] = {"abab","aba","abcabcabcabc"};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", ((repeatedSubstringPattern(s[test]) == 1) ? "true" : "false"));

        green();

        printf("Passed\n");
    }

    green();
}

bool repeatedSubstringPattern(char *sVar)
{
    for (int i = 2; i < strlen(sVar); i++)
    {
        char sub[ARRAY_SIZE];
        strncpy(sub, sVar + 0, i);
        sub[i] = '\0';

        char check[ARRAY_SIZE] = "";

        while (strlen(check) < strlen(sVar))
        {
            strcat(check, sub);   
        }

        if (strcmp(check, sVar) == 0)
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