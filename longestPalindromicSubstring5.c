/* Leetcode - 5. Longest Palindromic Substring (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 2

bool checkPalindrom(char string[]);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 5. Longest Palindromic Substring (C language) - Medium\n");

    char s[10][50] = {"babad", "cbbd"};
    int s_testSize[10] = {5,4};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int indexTempString = 0;
        int s_size = s_testSize[test];
        bool flag = false;

        green();

        printf("Test %i: ", test + 1);

        reset();
        
        for (int i = 0; i < s_size && !flag; i++)
        {
            char tempString[50] = "";

            for (int j = i; j < s_size; j++)
            {
                tempString[indexTempString] = s[test][j];
                indexTempString++;
                
                if (checkPalindrom(tempString) == 1 && strlen(tempString) > 1)
                {
                    printf("%s", tempString);
                    flag = true;
                    break;
                }
            }

            indexTempString = 0;
        }
        green();

        printf(" | Passed\n");
    }

    reset();
    
    return 0;
}

bool checkPalindrom(char string[])
{
    char const *pstring = string;
    char const *pendstring = string + strlen(string) - 1;

    for (int i = 0; i < strlen(string); i++, pstring++, pendstring--)
    {
        if (*pstring != *pendstring)
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