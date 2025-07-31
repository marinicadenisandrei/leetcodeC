/* Leetcode - 132. Palindrome Partitioning II (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int minCut(char *s);
bool checkPalindromeString(char *stringVar);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 132. Palindrome Partitioning II (C language) - ");

    red();

    printf("Hard\n");

    char s[ARRAY_SIZE][ARRAY_SIZE] = {"aab", "a", "ab"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", minCut(s[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

bool checkPalindromeString(char *stringVar)
{
    for (int i = 0, j = strlen(stringVar) - 1; i < strlen(stringVar) / 2; i++, j--)
    {
        if (stringVar[i] != stringVar[j])
        {
            return false;
        }
    }

    return true;
}

int minCut(char *s)
{
    if (strlen(s) == 1)
    {
        return 0;
    }
    
    int counter = 0;
    char formation[strlen(s) + 1];

    for (int i = 0, j = 0; i < strlen(s); i++, j++)
    {
        formation[j] = s[i];
        formation[j + 1] = '\0';

        if (checkPalindromeString(formation))
        {
            char formation2[(strlen(s) + 1) - i];

            for (int k = i + 1, l = 0; k < strlen(s); k++, l++)
            {
                formation2[l] = s[k];
            }

            formation2[(strlen(s) - 1) - i] = '\0';

            if (checkPalindromeString(formation2))
            {
                return 1;
            }
        }
    }

    return 0;
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