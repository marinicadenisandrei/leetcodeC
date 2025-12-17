/* Leetcode - 451. Sort Characters By Frequency (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

char* frequencySort(char* sVar);

int main()
{   
    yellow();

    printf("Leetcode - 451. Sort Characters By Frequency (C language) - Medium\n");

    char s[NUMBER_OF_TESTS][ARRAY_SIZE] = {"tree","cccaaa","Aabb"};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", frequencySort(s[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

char* frequencySort(char* sVar)
{
    char noDuplicateChars[ARRAY_SIZE] = "";
    int occChars[ARRAY_SIZE] = {};
    int noDuplicateCharsSize = 0;

    char* result = (char*)malloc((strlen(sVar) + 1) * sizeof(char));
    int resultSize = 0;

    for (int i = 0; i < strlen(sVar); i++)
    {
        bool flag = true;

        for (int j = 0; j < noDuplicateCharsSize; j++)
        {
            if (sVar[i] == noDuplicateChars[j])
            {
                flag = false;
                break;
            }            
        }

        if (flag)
        {
            noDuplicateChars[noDuplicateCharsSize] = sVar[i];
            occChars[noDuplicateCharsSize++] = 0;
        }
    }
    
    for (int i = 0; i < noDuplicateCharsSize; i++)
    {
        int occCount = 0;
        
        for (int j = 0; j < strlen(sVar); j++)
        {
            occCount += ((noDuplicateChars[i] == sVar[j]) ? 1 : 0);
        }

        occChars[i] = occCount;
    }

    bool flag = true;
    int c = 0;

    while (flag)
    {
        flag = false;
        
        for (int i = 0; i < noDuplicateCharsSize - 1 - c; i++)
        {
            if (occChars[i] < occChars[i + 1])
            {
                int temp = occChars[i];
                occChars[i] = occChars[i + 1];
                occChars[i + 1] = temp;

                char tempChar = noDuplicateChars[i];
                noDuplicateChars[i] = noDuplicateChars[i + 1];
                noDuplicateChars[i + 1] = tempChar;

                flag = true;
            }
        }
        
        c++;
    }

    for (int i = 0; i < noDuplicateCharsSize; i++)
    {
        for (int j = 0; j < occChars[i]; j++)
        {
            result[resultSize++] = noDuplicateChars[i]; 
        }
    }

    result[resultSize] = '\0';

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