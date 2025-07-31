/* Leetcode - 71. Simplify Path (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void removeLastSlash(char *pathVar);
void removeWrongCharacters(char *pathVar);
void removeMultipleSlashes(char *pathVar);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 71. Simplify Path (C language) - Medium\n");

    char path[ARRAY_SIZE][ARRAY_SIZE] = {"/home/", "/../", "home//foo/"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        removeLastSlash(path[test]);
        removeWrongCharacters(path[test]);
        removeMultipleSlashes(path[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", path[test]);

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

void removeWrongCharacters(char *pathVar)
{
    char *src = pathVar;
    char *new = pathVar;

    while (*src)
    {
        if (*src != '.')
        {
            *new = *src;
            new++;
        }

        src++;        
    }

    *new = '\0';
}

void removeLastSlash(char *pathVar)
{
    size_t lengthStrig = strlen(pathVar);

    if (lengthStrig > 1 && pathVar[lengthStrig - 1] == '/')
    {
        pathVar[lengthStrig - 1] = '\0';
    }
}

void removeMultipleSlashes(char *pathVar)
{
    char *new = pathVar;

    for (int i = 0; i < strlen(pathVar); i++)
    {
        if (*(pathVar + i) == '/' && *(pathVar + i + 1) == '/')
        {
            continue;
        }
        else
        {
            *new = *(pathVar + i);
            new++;
        }     
    }

    *new = '\0';
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