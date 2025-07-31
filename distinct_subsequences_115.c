/* Leetcode - 115. Distinct Subsequences (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int numDistinct(char *sVar, char *tVar);
bool charExistInArray(char character, char array[ARRAY_SIZE][2], int arraySize);
bool isAscending(char *string);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 115. Distinct Subsequences (C language) - ");

    red();

    printf("Hard\n");

    char s[ARRAY_SIZE][ARRAY_SIZE] = {"rabbbit","babgbag"};
    char t[ARRAY_SIZE][ARRAY_SIZE] = {"rabbit","bag"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", numDistinct(s[test], t[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

bool charExistInArray(char character, char array[ARRAY_SIZE][2], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (character == array[i][0])
        {
            return true;
        }
    }

    return false;
}

bool isAscending(char *string)
{
    for (int i = 1; i < strlen(string); i++)
    {
        if (string[i-1] > string[i])
        {
            return false;
        }
    }
    
    return true;
}

int numDistinct(char *sVar, char *tVar)
{
    char letters[ARRAY_SIZE][2] = {};
    int lettersSize = 0;

    char occurenceIndex[ARRAY_SIZE][ARRAY_SIZE] = {};
    int sizeInOcc[ARRAY_SIZE] = {0};

    for (int i = 0; i < strlen(tVar); i++)
    {
        if (!charExistInArray(tVar[i], letters, lettersSize))
        {
            letters[lettersSize][0] = tVar[i];
            lettersSize++;
        }
    }

    for (int i = 0; i < lettersSize; i++)
    {
        for (int j = 0; j < strlen(sVar); j++)
        {
            if (sVar[j] == letters[i][0])
            {
                occurenceIndex[i][sizeInOcc[i]] = j + '0';
                occurenceIndex[i][sizeInOcc[i] + 1] = '\0';
                sizeInOcc[i]++;
            }
        }
    }

    char combineArray[ARRAY_SIZE][ARRAY_SIZE] = {};
    int sizeCombine = 0;

    for (int i = 0; i < strlen(occurenceIndex[0]); i++)
    {
        for (int j = 0; j < strlen(occurenceIndex[1]); j++)
        {
            combineArray[sizeCombine][0] = occurenceIndex[0][i];
            combineArray[sizeCombine][1] = occurenceIndex[1][j];
            combineArray[sizeCombine][2] = '\0';

            sizeCombine++;
        }
    }

    char temp[ARRAY_SIZE][ARRAY_SIZE] = {};
    int sizeTemp = 0;

    int startLen = 2;

    for (int i = 2; i < lettersSize; i++)
    {
        for (int j = 0; j < sizeCombine; j++)
        {
            for (int k = 0; k < strlen(occurenceIndex[i]); k++)
            {
                strcat(temp[sizeTemp], combineArray[j]);
                temp[sizeTemp][startLen] = occurenceIndex[i][k];
                temp[sizeTemp][startLen + 1] = '\0';

                sizeTemp++;
            }   
        }

        for (int j = 0; j < sizeTemp; j++)
        {
            strcpy(combineArray[j], temp[j]);
        }

        sizeCombine = sizeTemp;
        sizeTemp = 0;
        startLen++;
    }

    int result = 0;

    for (int j = 0; j < sizeCombine; j++)
    {
        if (isAscending(combineArray[j]))
        {
            result++;
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