/* Leetcode - 424. Longest Repeating Character Replacement (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int characterReplacement(char* sVar, int kVar);

int main()
{
    yellow();

    printf("Leetcode - 424. Longest Repeating Character Replacement (C language) - Medium\n");

    char s[NUMBER_OF_TESTS][ARRAY_SIZE] = {"ABAB","AABABBA"};
    int k[NUMBER_OF_TESTS] = {2,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", characterReplacement(s[test], k[test]));

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

int characterReplacement(char* sVar, int kVar)
{
    int n = strlen(sVar);
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        int chance = kVar;
        int count = 1;

        for (int j = i + 1; j < n; j++)
        {
            if (sVar[j] == sVar[j - 1])
            {
                count++;
            }
            else
            {
                if (chance > 0)
                {
                    chance--;
                    count++;
                }
                else
                {
                    break;
                }
            }
        }

        result = (((count + 1) > result) ? (count + 1) : result);
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