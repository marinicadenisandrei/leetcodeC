/* Leetcode - 192. Word Frequency (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 50

void wordFrequency(char *wordsVar);
bool charInArray(char *charVar, char charArray[ARRAY_SIZE][ARRAY_SIZE], int charArraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 192. Word Frequency (C language) - Medium\n");
    
    green();

    printf("Test 1: \n");

    reset();

    char words[ARRAY_SIZE] = "the day is sunny the the the sunny is is";
    wordFrequency(words);
    printf(" | ");

    green();

    printf("Passed\n");

    reset();

    return 0;
}

bool charInArray(char *charVar, char charArray[ARRAY_SIZE][ARRAY_SIZE], int charArraySize)
{
    bool flag = true;

    for (int i = 0; i < charArraySize; i++)
    {
        flag = true;

        if (strlen(charVar) == strlen(charArray[i]))
        {
            for (int j = 0; j < strlen(charVar); j++)
            {
                if (charVar[j] != charArray[i][j])
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                return true;
            }
        }
    }

    return false;
}

void wordFrequency(char *wordsVar)
{
    char acumulation[ARRAY_SIZE][ARRAY_SIZE];
    int acumulationSize = 0;

    char noDuplicates[ARRAY_SIZE][ARRAY_SIZE];
    int noDuplicatesSize = 0;

    int occurence[ARRAY_SIZE] = {0};

    char temp[ARRAY_SIZE];
    int sizeTemp = 0;

    for (int i = 0; i < strlen(wordsVar); i++)
    {
        if (wordsVar[i] != ' ')
        {
            temp[sizeTemp++] = wordsVar[i]; 
        }
        else
        {
            temp[sizeTemp] = '\0';
            strcpy(acumulation[acumulationSize++], temp);
            temp[0] = '\0';
            sizeTemp = 0;
        }
    }

    strcpy(acumulation[acumulationSize++], temp);

    for (int i = 0; i < acumulationSize; i++)
    {
        if (!charInArray(acumulation[i], noDuplicates, noDuplicatesSize))
        {
            strcpy(noDuplicates[noDuplicatesSize++], acumulation[i]);
        }
    }

    for (int i = 0; i < noDuplicatesSize; i++)
    {
        int count = 0;

        for (int j = 0; j < acumulationSize; j++)
        {
            if (strcmp(noDuplicates[i], acumulation[j]) == 0)
            {
                count++;
            }
            
        }

        occurence[i] = count;
        count = 0;
    }  

    bool flag = true;

    while (flag)
    {
        int counter = 0;
        flag = false;

        for (int i = 0; i < noDuplicatesSize - 1 - counter; i++)
        {
            if (occurence[i] < occurence[i + 1])
            {
                int temp = occurence[i];
                occurence[i] = occurence[i + 1];
                occurence[i + 1] = temp;

                char tempChar[10];
                strcpy(tempChar, noDuplicates[i]);
                strcpy(noDuplicates[i], noDuplicates[i + 1]);
                strcpy(noDuplicates[i + 1], tempChar);

                flag = true;
            }
        }
        
        counter++;
    }
    
    for (int i = 0; i < noDuplicatesSize; i++)
    {
        printf("%s %i%c", noDuplicates[i], occurence[i], ((i < noDuplicatesSize - 1) ? '\n' : '\0'));
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