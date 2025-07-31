/* Leetcode - 316. Remove Duplicate Letters (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

char* removeDuplicateLetters(char *sVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 316. Remove Duplicate Letters (C language) - Medium\n");

    char s[NUMBER_OF_TESTS][ARRAY_SIZE] = {"bcabc","cbacdcbc"};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", removeDuplicateLetters(s[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

char* removeDuplicateLetters(char *sVar)
{
    char *result = (char*) malloc(strlen(sVar) * sizeof(char));
    char resultSize = 0;

    for (int i = 0; i < strlen(sVar); i++)
    {
        bool flag = true;

        for (int j = 0; j < resultSize; j++)
        {
            if (result[j] == sVar[i])
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            result[resultSize++] = sVar[i];
        }
    }
    
    result[resultSize] = '\0';

    int c = 0;
    int flag = true;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < resultSize - 1 - c; i++)
        {
            if (result[i] > result[i + 1])
            {
                char temp = result[i];
                result[i] = result[i + 1];
                result[i + 1] = temp;

                flag = true;
            }
        }
        
        c++;
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