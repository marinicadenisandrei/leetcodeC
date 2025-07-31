/* Leetcode - 242. Valid Anagram (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TEST 2

bool isAnagram(char *sVar, char *tvar);
void sortStringChars(char *string);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 242. Valid Anagram (C language) - ");

    green();

    printf("Easy\n");
    
    char s[NUMBER_OF_TEST][ARRAY_SIZE] = {"anagram","rat"};
    char t[NUMBER_OF_TEST][ARRAY_SIZE] = {"nagaram","car"};

    for (int test = 0; test < NUMBER_OF_TEST; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s", (isAnagram(s[test], t[test]) ? "true" : "false"));

        green();

        printf(" | Passed\n");
    }

    reset();

    return 0;
}

void sortStringChars(char *string)
{
    bool flag = true;
    int c = 0;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < strlen(string) - 1 - c; i++)
        {
            if (string[i] > string[i + 1])
            {
                char temp = string[i];
                string[i] = string[i + 1];
                string[i + 1] = temp;
                flag = true;
            } 
        }

        c++;
    }
}

bool isAnagram(char *sVar, char *tvar)
{
    sortStringChars(sVar);
    sortStringChars(tvar);

    if (strcmp(sVar, tvar) == 0)
    {
        return true;
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