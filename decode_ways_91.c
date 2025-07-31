/* Leetcode - 91. Decode Ways (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MIN_VALUE 1
#define MAX_VALUE 26
#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int numDecodings(char *sVar);
bool singleCharacter(char *sVar);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 91. Decode Ways (C language) - Medium\n");

    char s[ARRAY_SIZE][ARRAY_SIZE] = {"12", "226", "06"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int result = numDecodings(s[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", result);

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

bool singleCharacter(char *sVar)
{
    for (int i = 0; i < strlen(sVar); i++)
    {
        if (*(sVar + i) == '0')
        {
            return false;
        }
    }

    return true;
}

int numDecodings(char *sVar)
{
    if (singleCharacter(sVar))
    {
        return strlen(sVar);
    }
    else
    {
        bool flag = true;
        int counter = 0;
        int length = strlen(sVar);

    
        for (int i = 0; i < strlen(sVar); i++)
        {
            if (*(sVar + i) == '0')
            {
                char left[ARRAY_SIZE] = "";
                char right[ARRAY_SIZE] = "";

                strncpy(left, sVar, i);
                strncpy(right, sVar + i + 1, (length - i));
                strcpy(sVar,left);
                strcat(sVar,right);

                counter++;
            }
        }

        return strlen(sVar) - counter;
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