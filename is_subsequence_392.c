/* Leetcode - 392. Is Subsequence (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

bool isSubsequence(char *sVar, char *tVar);

int main()
{
    yellow();
    
    printf("Leetcode - 392. Is Subsequence (C language) - ");

    green();

    printf("Easy\n");

    char s[NUMBER_OF_TESTS][ARRAY_SIZE] = {"abc","axc"};
    char t[NUMBER_OF_TESTS][ARRAY_SIZE] = {"ahbgdc","ahbgdc"};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", ((isSubsequence(s[test], t[test])) ? "true" : "false"));

        green();

        printf("Passed\n");
    }

    reset();
}

bool isSubsequence(char *sVar, char *tVar)
{
    for (int i = 0; i < strlen(sVar); i++)
    {
        bool flag = false;

        for (int j = 0; j < strlen(tVar); j++)
        {
            if (sVar[i] == tVar[j])
            {
                flag = true;
                break;
            }
        }
        
        if (!flag)
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