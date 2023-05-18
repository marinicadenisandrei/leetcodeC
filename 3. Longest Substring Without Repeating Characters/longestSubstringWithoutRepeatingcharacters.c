/* Leetcode - 3. Longest Substring Without Repeating Characters (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool haveRepetitions(char string[]);
int maxString(char array[100][100], int arraysize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{   
    yellow();

    printf("Leetcode - 3. Longest Substring Without Repeating Characters (C language) - Medium\n");

    char s[20][100] = {"abcabcbb", "bbbbb", "pwwkew"};
    int s_sizeTest[10] = {8, 5, 6};

    for (int test = 0; test < 3; test++)
    {
        char history[100][100] = {};
        int starter = 0;
        int stringIndex = 0;

        int s_size = s_sizeTest[test];

        while (starter <= s_size)
        {
            char const *ps = s[test] + starter;

            for (int i = starter; i < s_size; i++, ps++, stringIndex++)
            {
                history[starter][stringIndex] = *ps;
                
                if (haveRepetitions(history[starter]) == 1)
                {
                    history[starter][stringIndex] = '\0'; 
                    break;
                }
                
            }

            starter++;
            stringIndex = 0;
        }

        green();

        printf("Test %i: ", test+1);

        reset();

        printf("%i", maxString(history,s_size));

        green();

        printf(" | Passed\n");

        reset();
    }
    
    return 0;
}


bool haveRepetitions(char string[])
{
    char const *pstring1 = string;
    char const *pstring2 = string + 1;
    bool flag = false;
    
    for (int i = 0; i < strlen(string); i++, pstring1++)
    {
        for (int j = 0; j < strlen(string); j++, pstring2++)
        {
            if (i != j)
            {
                if (*pstring1 == *pstring2)
                {
                    return true;
                }   
            }
        }
        pstring2 = string;   
    }
    
    return false;
}

int maxString(char array[100][100], int arraysize)
{
    int maxLength = 0;

    for (int i = 0; i < arraysize; i++)
    {
        int length = strlen(array[i]);
        if (length > maxLength) {
            maxLength = length;
        }
    }
    
    return maxLength;
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