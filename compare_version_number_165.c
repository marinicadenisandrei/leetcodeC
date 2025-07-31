/* Leetcode - 165. Compare Version Numbers (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int compareVersion(char *version1Var, char *version2Var);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 165. Compare Version Numbers (C language) - Medium\n");

    char version1[ARRAY_SIZE][ARRAY_SIZE] = {"1.01","1.0","0.1"};
    char version2[ARRAY_SIZE][ARRAY_SIZE] = {"1.001","1.0.0","1.1"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ");

        reset();

        printf("%i | " ,compareVersion(version1[test], version2[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int compareVersion(char *version1Var, char *version2Var)
{
    if (version1Var[0] > version2Var[0])
    {
        return 1;
    }
    else if (version1Var[0] < version2Var[0])
    {
        return -1;
    }
    else
    {
        return 0;
    }
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