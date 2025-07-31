/* Leeetcode - 395. Longest Substring with At Least K Repeating Characters (C language) - Medium */

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

int longestSubstring(char *sVar, int kVar);
bool charInString(char c, char *s);

int main()
{
    yellow();

    printf("Leeetcode - 395. Longest Substring with At Least K Repeating Characters (C language) - Medium\n");

    char s[NUMBER_OF_TESTS][ARRAY_SIZE] = {"aaabb","ababbc"};
    int k[NUMBER_OF_TESTS] = {3,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", longestSubstring(s[test], k[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

bool charInString(char c, char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == c)
        {
            return true;
        }
    }
    
    return false;
}

int longestSubstring(char *sVar, int kVar)
{
    int result = 0;

    char noDuplicates[ARRAY_SIZE] = "";
    int noDuplicatesSize = 0;

    for (int i = 0; i < strlen(sVar); i++)
    {
        if (!charInString(sVar[i], noDuplicates))
        {
            noDuplicates[noDuplicatesSize++] = sVar[i];
            noDuplicates[noDuplicatesSize] = '\0';
        }
    }

    for (int i = 0; i < strlen(noDuplicates); i++)
    {
        int counter = 0;
        
        for (int j = 0; j < strlen(sVar); j++)
        {
            if (noDuplicates[i] == sVar[j])
            {
                counter++;                
            }
        }

        if (counter >= kVar)
        {
            result += counter;
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