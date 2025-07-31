/* Leetcode - 290. Word Pattern (C language) - Easy*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 30
#define NUMBER_OF_TESTS 3

bool wordPattern(char *patternVar, char *sVar);
bool charInString(char character, char *string);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 290. Word Pattern (C language) - ");

    green();

    printf("Easy\n");

    char pattern[NUMBER_OF_TESTS][ARRAY_SIZE] = {"abba","abba","aaaa"};
    char s[NUMBER_OF_TESTS][ARRAY_SIZE] = {"dog cat cat dog","dog cat cat fish","dog cat cat dog"};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", ((wordPattern(pattern[test], s[test]) == true) ? "true" : "false"));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

bool wordPattern(char *patternVar, char *sVar)
{
    char s_list[ARRAY_SIZE][ARRAY_SIZE] = {""};
    int s_listSize = 0;

    char temp[10] = "";
    int tempSize = 0;

    for (int i = 0; i < strlen(sVar); i++)
    {
        temp[tempSize++] = sVar[i];

        if (sVar[i] == ' ' || i + 1 == strlen(sVar))
        {
            temp[tempSize - ((sVar[i] == ' ') ? 1 : 0)] = '\0';
            strcpy(s_list[s_listSize++], temp);

            strcpy(temp, "");
            tempSize = 0;  
        }
    }  
     
    for (int i = 0; i < strlen(patternVar); i++)
    {
        for (int j = 0; j < strlen(patternVar); j++)
        {
            if (i != j && patternVar[i] == patternVar[j] && strcmp(s_list[i], s_list[j]) != 0)
            {
                return false;
            }
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