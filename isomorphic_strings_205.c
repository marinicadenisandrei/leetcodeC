/* Leetcode - 205. Isomorphic Strings (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 3

bool isIsomorphic(char *sVar, char *tVar);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 205. Isomorphic Strings (C language) - ");

    green();

    printf("Easy\n");

    char s[NUMBER_OF_TESTS][10] = {"egg","foo","paper"};
    char t[NUMBER_OF_TESTS][10] = {"add","bar","title"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", (isIsomorphic(s[test], t[test]) == 1) ? "true" : "false");

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

bool isIsomorphic(char *sVar, char *tVar)
{
    int counter = 0;

    int sArray[10] = {0};
    int sArraySize = 0;

    int tArray[10] = {0};
    int tArraySize = 0;

    for (int i = 0; i < strlen(sVar); i++)
    {
        for (int j = 0; j < strlen(sVar); j++)
        {
            if (sVar[i] == sVar[j])
            {
                counter++;
            }
        }

        sArray[sArraySize++] = counter;
        counter = 0;
    }

    counter = 0;

    for (int i = 0; i < strlen(tVar); i++)
    {
        for (int j = 0; j < strlen(tVar); j++)
        {
            if (tVar[i] == tVar[j])
            {
                counter++;
            }
        }

        tArray[tArraySize++] = counter;
        counter = 0;
    }

    for (int i = 0; i < sArraySize; i++)
    {
        if (sArray[i] != tArray[i])
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