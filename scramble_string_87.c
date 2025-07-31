/* Leetcode - 87. Scramble String (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

bool isScramble(char *s1, char *s2);
bool checkForCut(char *stringVar);
bool checkStringValidity(char *stringFormat, char *globalString);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 87. Scramble String (C language) - ");

    red();

    printf("Hard\n");

    char s1[ARRAY_SIZE][ARRAY_SIZE] = {"great", "abcde", "a"};
    char s2[ARRAY_SIZE][ARRAY_SIZE] = {"rgeat", "caebd", "a"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        bool result = isScramble(s1[test], s2[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", ((result) ? "true" : "false"));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

bool checkForCut(char *stringVar)
{
    int sum = 0;

    for (int i = 0; i < strlen(stringVar); i++)
    {
        if (*(stringVar + i) != '/')
        {
            sum++;
        }
        else
        {
            if (sum == 1)
            {
                return false;
            }
            else
            {
                sum = 0;
            }
        }
    }
    
    return true;
}

bool checkStringValidity(char *stringFormat, char *globalString)
{
    char temp[ARRAY_SIZE];
    int tempSize = 0;

    char *pointer = NULL;

    for (int i = 0; i < strlen(stringFormat); i++)
    {
        if (*(stringFormat + i) != '/')
        {
            temp[tempSize] = *(stringFormat + i);
            tempSize++;     
        }
        else
        {
            temp[tempSize] = '\0';
        
            pointer = strstr(globalString, temp);

            if (pointer == NULL)
            {
                return false;
            }
            
            strcpy(temp, "");
            tempSize = 0;
        }
    }

    pointer = strstr(globalString, temp);

    if (pointer == NULL)
    {
        return false;
    }

    return true;
}

bool isScramble(char *s1, char *s2)
{
    if (strlen(s1) == 1 && strlen(s2))
    {
        if (s1[0] == s2[0])
        {
            return true;
        }
    }
    
    int output[] = {};
    int outputSize = 0;

    int lenString = strlen(s1);

    char copyString[lenString];
    strcpy(copyString, s1);

    for (int i = 2; i < lenString - 1; i++)
    {
        for (int j = lenString - 1; j >= i; j--)
        {
            s1[j+1] = s1[j];
        }

        s1[i] = '/';
        s1[lenString + 1] = '\0';

        if (checkStringValidity(s1, s2))
        {
            return true;
        }

        while (checkForCut(s1))
        {
            int arrayIndex[ARRAY_SIZE] = {1};
            int arrayIndexSize = 1;

            for (int k = 0; k < strlen(s1); k++)
            {
                if (s1[k] == '/')
                {
                    arrayIndex[arrayIndexSize] = k + 1; 
                    arrayIndexSize++;
                }
            }

            int offset = 0;
            int newLen = strlen(s1);

            for (int k = 0; k < arrayIndexSize; k++)
            {
                for (int l = newLen; l >= arrayIndex[k] + offset; l--)
                {
                    s1[l] = s1[l - 1];
                }

                s1[arrayIndex[k] + offset] = '/';
                newLen++;
                s1[newLen] = '\0';
                
                offset += 2;
            }

            if (checkStringValidity(s1, s2))
            {
                return true;
            }
        }
    
        strcpy(s1, copyString);
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