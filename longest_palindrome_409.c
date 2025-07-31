/* Leetcode - 409. Longest Palindrome (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int longestPalindrome(char* sVar);
bool charInString(char c, char* str);

int main()
{
    yellow();

    printf("Leetcode - 409. Longest Palindrome (C language) - ");

    green();

    printf("Easy\n");

    char s[NUMBER_OF_TESTS][ARRAY_SIZE] = {"abccccdd","a"};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", longestPalindrome(s[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int longestPalindrome(char* sVar)
{
    bool findOne = false;

    char noDupl[ARRAY_SIZE] = "";
    int noDuplSize = 0;

    int result = 0;

    for (int i = 0; i < strlen(sVar); i++)
    {
        noDupl[noDuplSize] = '\0';

        if (!charInString(sVar[i], noDupl))
        {
            noDupl[noDuplSize++] = sVar[i];
        }
    }

    noDupl[noDuplSize] = '\0';
    
    for (int i = 0; i < strlen(noDupl); i++)
    {
        int counter = 0;
        
        for (int j = 0; j < strlen(sVar); j++)
        {
            counter += ((sVar[j] == noDupl[i]) ? 1 : 0);
        }

        if (counter % 2 == 0)
        {
            result += counter;
        }

        if (counter == 1 && !findOne)
        {
            findOne = true;
        }
    }  
    
    return result + ((findOne) ? 1 : 0);
}

bool charInString(char c, char* str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (c == str[i])
        {
            return true;
        }
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