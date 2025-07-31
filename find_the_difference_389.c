/* Leetcode - 389. Find the Difference (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

char findTheDifference(char* sVar, char* tVar);

int main()
{
    yellow();

    printf("Leetcode - 389. Find the Difference (C language) - ");

    green();

    printf("Easy\n");

    char s[NUMBER_OF_TESTS][ARRAY_SIZE] = {"abcd",""};
    char t[NUMBER_OF_TESTS][ARRAY_SIZE] = {"abcde","y"};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%c | ", findTheDifference(s[test], t[test]));

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

char findTheDifference(char* sVar, char* tVar)
{
    int first = ((strlen(sVar) > strlen(tVar)) ? 1 : 0);

    if (first)
    {
        for (int i = 0; i < strlen(sVar); i++)
        {
            int flag = 0;
            
            for (int j = 0; j < strlen(tVar); j++)
            {
                if (sVar[i] == tVar[j])
                {
                    flag = 1;
                    break;
                }
            }

            if (!flag)
            {
                return sVar[i];
            }
        }
    }
   else
    {
        for (int i = 0; i < strlen(tVar); i++)
        {
            int flag = 0;

            for (int j = 0; j < strlen(sVar); j++)
            {
                if (tVar[i] == sVar[j])
                {
                    flag = 1;
                    break;
                }
            }

            if (!flag)
            {
                return tVar[i];
            }
        }
    }
    
    return '\0';
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

