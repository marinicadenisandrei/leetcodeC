/* Leetcode - 467. Unique Substrings in Wraparound String (C language) - Medium */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

int findSubstringInWraproundString(char *sVar);

int main()
{
    yellow();

    printf("Leetcode - 467. Unique Substrings in Wraparound String (C language) - Medium\n");

    char s[ARRAY_SIZE][ARRAY_SIZE] = {"a","cac","zab"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", findSubstringInWraproundString(s[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int findSubstringInWraproundString(char *sVar)
{
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    
    char *arr[ARRAY_SIZE] = { NULL };
    int arrSize = 0;

    int n = strlen(sVar);
    int result = 0;

    for (int start = 0; start < n; start++)
    {
        for (int len = 1; len <= n - start; len++)
        {
            char sub[100];

            strncpy(sub, sVar + start, len);
            sub[len] = '\0';

            bool addFlag = true;

            for (int i = 0; i < arrSize; i++)
            {
                if (strcmp(arr[i], sub) == 0)
                {
                    addFlag = false;
                    break;
                }
            }

            if (strstr(alphabet, sub) != NULL && addFlag)
            {
                result += 1;

                arr[arrSize] = malloc(strlen(sub) + 1);
                strcpy(arr[arrSize], sub);
                arrSize++;
            }
        }
    }

    for (int i = 0; i < arrSize; i++)
    {
        free(arr[i]);
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