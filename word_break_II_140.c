/* Leetcode - 140. Word Break II (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3
int resultSize = 0;

char** wordBreak(char *sVar, char wordDictVar[ARRAY_SIZE][ARRAY_SIZE], int wordDictVarSize);
void removeSubstring(char *str, const char *sub);
void removeElementFromArray(char array[ARRAY_SIZE][ARRAY_SIZE], int arraySize, int index);
void printArrayOfStrings(char **array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 140. Word Break II (C language) - ");

    red();

    printf("Hard\n");

    char s[ARRAY_SIZE][ARRAY_SIZE] = {"catsanddog","pineapplepenapple","catsandog"};
    char wordDict[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {{"cat","cats","and","sand","dog"},{"apple","pen","applepen","pine","pineapple"},{"cats","dog","sand","and","cat"}};
    int wordDictSize[ARRAY_SIZE] = {5,5,5};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        char **output = (char **) malloc(ARRAY_SIZE * sizeof(char *));
        for(int i = 0; i < ARRAY_SIZE; i++ ) {
            output[i] = (char*)malloc(ARRAY_SIZE * sizeof(char *));
        }

        output = wordBreak(s[test], wordDict[test], wordDictSize[test]);
        
        green();

        printf("Test %i: ", test + 1);

        reset();

        printArrayOfStrings(output, resultSize);

        green();

        printf("Passed\n");

        for(int i = 0; i < ARRAY_SIZE; i++ ) {
            free(output[i]);
        }

        free(output);
        resultSize = 0;
    }

    reset();

    return 0;
}

void printArrayOfStrings(char **array, int arraySize)
{
    if (arraySize == 0)
    {
        printf("[] | ");
        return;
    }
    
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%s%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "]"));
    }

    printf(" | ");
}

void removeElementFromArray(char array[ARRAY_SIZE][ARRAY_SIZE], int arraySize, int index)
{
    for (int i = index; i < arraySize - 1; i++)
    {
        strcpy(array[i], array[i + 1]);
    }
}

void removeSubstring(char *str, const char *sub) {
    char *pos;
    int len = strlen(sub);

    while ((pos = strstr(str, sub)) != NULL) {
        memmove(pos, pos + len, strlen(pos + len) + 1);
    } 
}

char** wordBreak(char *sVar, char wordDictVar[ARRAY_SIZE][ARRAY_SIZE], int wordDictVarSize)
{
    char acumulation[ARRAY_SIZE][ARRAY_SIZE] = {""};
    int acumulationSize = 0;

    char acumulationReal[ARRAY_SIZE][ARRAY_SIZE] = {""};
    int acumulationRealSize = 0;

    char **result = (char **) malloc(ARRAY_SIZE * sizeof(char *));
    for(int i = 0; i < ARRAY_SIZE; i++ ) {
        result[i] = (char*)malloc(ARRAY_SIZE * sizeof(char *));
    }

    for (int i = 0; i < wordDictVarSize; i++)
    {
        for (int j = 0; j < wordDictVarSize; j++)
        {
            if (i != j)
            {
                char formation[ARRAY_SIZE] = "";
                strncpy(formation, "", ARRAY_SIZE - 1);
                formation[ARRAY_SIZE - 1] = '\0'; 

                char real[ARRAY_SIZE] = "";
                strncpy(real, "", ARRAY_SIZE - 1);
                real[ARRAY_SIZE - 1] = '\0';

                strcat(formation, wordDictVar[i]);
                strcat(formation, wordDictVar[j]);

                strcat(real, wordDictVar[i]);
                strcat(real, " ");
                strcat(real, wordDictVar[j]);

                if (strcmp(sVar, formation) == 0)
                {
                    strcpy(result[resultSize], real);
                    resultSize++;
                }
                
                if (strstr(sVar, formation) != NULL)
                {
                    strcpy(acumulation[acumulationSize], formation);
                    acumulationSize++;

                    strcpy(acumulationReal[acumulationRealSize], real);
                    acumulationRealSize++;
                }
            }
        }
    }

    bool flag = true;

    while (flag)
    {
        flag = false;

        char newFormation[ARRAY_SIZE][ARRAY_SIZE] = {""};
        char realNew[ARRAY_SIZE][ARRAY_SIZE] = {""};

        int newFormationSize = 0;

        for (int i = 0; i < acumulationSize; i++)
        {
            for (int j = 0; j < wordDictVarSize; j++)
            {
                char formation[ARRAY_SIZE] = "";
                strncpy(formation, "", ARRAY_SIZE - 1);
                formation[ARRAY_SIZE - 1] = '\0'; 

                char real[ARRAY_SIZE] = "";
                strncpy(real, "", ARRAY_SIZE - 1);
                real[ARRAY_SIZE - 1] = '\0';

                strcat(formation, acumulation[i]);
                strcat(formation, wordDictVar[j]);

                strcat(real, acumulationReal[i]);
                strcat(real, " ");
                strcat(real, wordDictVar[j]);

                if (strcmp(sVar, formation) == 0)
                {
                    strcpy(result[resultSize], real);
                    resultSize++;
                }
                
                if (strstr(sVar, formation) != NULL)
                {
                    flag = true;

                    strcpy(newFormation[newFormationSize], formation);
                    strcpy(realNew[newFormationSize], real);

                    newFormationSize++;
                }
            }
        }

        for (int i = 0; i < newFormationSize; i++)
        {
            strcpy(acumulation[i], newFormation[i]);
            strcpy(acumulationReal[i], realNew[i]);
        }

        acumulationSize = newFormationSize;
        acumulationRealSize = newFormationSize;
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