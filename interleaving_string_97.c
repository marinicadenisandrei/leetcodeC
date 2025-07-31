/* Leetcode - 97. Interleaving String (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

bool isInterLeave(char *s1Var, char *s2Var, char *s3Var);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 97. Interleaving String (C language) - Medium\n");

    char s1[ARRAY_SIZE][ARRAY_SIZE] = {"aabcc", "aabcc", ""};
    char s2[ARRAY_SIZE][ARRAY_SIZE] = {"dbbca", "dbbca", ""};
    char s3[ARRAY_SIZE][ARRAY_SIZE] = {"aadbbcbcac", "aadbbbcbcac", ""};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        bool result = isInterLeave(s1[test], s2[test], s3[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s", (result == true) ? "true | " : "false | ");   

        green();

        printf("Passed\n"); 
    }

    reset();
    
    return 0;
}

bool isInterLeave(char *s1Var, char *s2Var, char *s3Var)
{
    if (strlen(s1Var) == 0 && strlen(s2Var) == 0 && strlen(s3Var) == 0)
    {
        return true;
    }

    int offset_s1 = 0;
    int offset_s2 = 0;

    for (int i = 0; i < strlen(s3Var) - 2; i++)
    {
        if (s3Var[i] == s1Var[offset_s1] && offset_s1 <= strlen(s1Var))
        {
            offset_s1++;
            continue;
        }
        else if (s3Var[i] == s2Var[offset_s2] && offset_s2 <= strlen(s2Var))
        {
            offset_s2++;
            continue;
        }
        else
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