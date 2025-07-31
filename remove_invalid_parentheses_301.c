/* Leetcode - 301. Remove Invalid Parentheses (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int resultSize = 0;

char** removeInvalidParentheses(char *sVar);
void printArraysOfStrings(char** array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 301. Remove Invalid Parentheses (C language) - ");

    red();

    printf("Hard\n");

    char s[NUMBER_OF_TESTS][ARRAY_SIZE] = {"()())()","(a)())()",")("};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        char **output = removeInvalidParentheses(s[test]);
        printArraysOfStrings(output, resultSize);

        green();

        printf("Passed\n");

        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            free(output[i]);
        }

        free(output);
        resultSize = 0;
        output = NULL;
    }
    
    reset();

    return 0;
}

void printArraysOfStrings(char** array, int arraySize)
{
    if (arraySize == 0)
    {
        printf("[] | ");
        return;
    }
    
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%s%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "] | "));
    }
}

char** removeInvalidParentheses(char *sVar)
{
    bool flag = false;

    char **result=(char**)malloc(sizeof(char*) * ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        result[i] = (char*)malloc(sizeof(char) * ARRAY_SIZE);
    }
    
    for (int i = 0; i < strlen(sVar); i++)
    {
        if (sVar[i] == '(')
        {
            flag = true;
        }
        else if (sVar[i] == '(' && flag == true)
        {
            for (int j = i; j < strlen(sVar) - 1; j++)
            {
                sVar[j] = sVar[j + 1];
            }

            strcpy(result[resultSize++], sVar);

            for (int j = i - 3; j < strlen(sVar) - 1; j++)
            {
                sVar[j] = sVar[j + 1];
            }

            strcpy(result[resultSize++], sVar);
        }
        else if (sVar[i] == ')')
        {
            flag = false;
        }
    }

    flag = false;

    for (int i = strlen(sVar) - 1; i >= 0; i--)
    {
        if (sVar[i] == ')' && flag == true)
        {
            char temp[strlen(sVar)];
            strcpy(temp, sVar);
                
            for (int j = i; j < strlen(sVar); j++)
            {
                sVar[j] = sVar[j + 1];
            }

            strcpy(result[resultSize++], sVar);
            strcpy(sVar, temp);

            for (int j = i - 2; j < strlen(sVar); j++)
            {
                sVar[j] = sVar[j + 1];
            }

            strcpy(result[resultSize++], sVar);
            flag = false;
        }
        else if (sVar[i] == ')')
        {
            flag = true;
        }
        else if (sVar[i] == '(')
        {
            flag = false;
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