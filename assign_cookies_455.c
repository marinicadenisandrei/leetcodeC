/* Leetcode - 455. Assign Cookies (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int findContentChildren(int* gVar, int gSizeVar, int* sVar, int sSizeVar);

int main()
{
    yellow();

    printf("Leetcode - 455. Assign Cookies (C language) - ");

    green();

    printf("Easy\n");

    int g[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2,3},{1,2}};
    int gSize[NUMBER_OF_TESTS] = {3,2};

    int s[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,1},{1,2,3}};
    int sSize[NUMBER_OF_TESTS] = {2,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", findContentChildren(g[test], gSize[test], s[test], sSize[test]));

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

int findContentChildren(int* gVar, int gSizeVar, int* sVar, int sSizeVar)
{
    int result = 0;
    int rest = 0;

    for (int i = 0; i < ((sSizeVar < gSizeVar) ? sSizeVar : gSizeVar); i++)
    {
        if (gVar[i] <= sVar[i] + rest)
        {
            rest = sVar[i] + rest - gVar[i];
            result++;
        }
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