#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int globalOutput = 0;
int globalInSize[ARRAY_SIZE] = {0};

char ***findLadders(char *beginWordVar, char *endWordVar, char **wordListVar, int wordListVarSize);
void printArrayString(char **arrayString, int arrayStringSize);
void removeIndex(char **charArray, int charArraySize, int removeIndexVar);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 126. Word Ladder II (C language) - ");

    red();

    printf("Hard\n");

    char beginWord[ARRAY_SIZE][ARRAY_SIZE] = {"hit", "hit"};
    char endWord[ARRAY_SIZE][ARRAY_SIZE] = {"cog", "cog"};
    char *wordList[ARRAY_SIZE][ARRAY_SIZE] = {{"hot", "dot", "dog", "lot", "log", "cog"}, {"hot","dot","dog","lot","log"}};
    int wordListSize[ARRAY_SIZE] = {6,5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        char ***output = (char ***)malloc(ARRAY_SIZE * sizeof(char **));
        for (int i = 0; i < ARRAY_SIZE; i++) {
            output[i] = (char **)malloc(ARRAY_SIZE * sizeof(char *));
            for (int j = 0; j < ARRAY_SIZE; j++) {
                output[i][j] = (char *)malloc((ARRAY_SIZE + 1) * sizeof(char));
            }
        }

        green();

        printf("Test %i: ", test + 1);

        reset();

        output = findLadders(beginWord[test], endWord[test], wordList[test], wordListSize[test]);

        if (globalOutput == 0)
        {
            printf("[]");
        }
        
        for (int i = 0; i < globalOutput; i++)
        {
            printArrayString(output[i], globalInSize[i]);
        }

        printf(" | ");

        green();

        printf("Passed\n");

        for (int i = 0; i < ARRAY_SIZE; i++) {
            for (int j = 0; j < ARRAY_SIZE; j++) {
                free(output[i][j]);
            }
            free(output[i]);
        }
        free(output);

        globalOutput = 0;
    }

    reset();

    return 0;
}

void printArrayString(char **arrayString, int arrayStringSize)
{
    if (arrayString == 0)
    {
        printf("[]");
        return;
    }
    
    for (int i = 0; i < arrayStringSize; i++)
    {
        printf("%s%s%s", ((i == 0) ? "[" : ""), arrayString[i], ((i < arrayStringSize - 1) ? ", " : "]"));
    }
}

void removeIndex(char **charArray, int charArraySize, int removeIndexVar)
{
    for (int i = removeIndexVar; i < charArraySize - 1; i++)
    {
        charArray[i] = charArray[i + 1];
    }  
}

char ***findLadders(char *beginWordVar, char *endWordVar, char **wordListVar, int wordListVarSize)
{
    char ***result = (char ***)malloc(ARRAY_SIZE * sizeof(char **));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        result[i] = (char **)malloc(ARRAY_SIZE * sizeof(char *));
        for (int j = 0; j < ARRAY_SIZE; j++) {
            result[i][j] = (char *)malloc((ARRAY_SIZE + 1) * sizeof(char));
        }
    }

    bool continueVar = false;

    for (int i = 0; i < wordListVarSize; i++)
    {
        if (strcmp(endWordVar, wordListVar[i]) == 0)
        {
            continueVar = true;
            break;   
        }
    }

    if (!continueVar)
    {
        return result;
    }
    
    int occ = 0;
    int history_occ = occ;
    int removeIndexElement = 0;

    bool flag = true;

    int resultSize = 0;
    int resultSizeOut = 0;

    while(flag)
    {
        flag = false;
        
        strcpy(result[globalOutput][resultSize], beginWordVar);
        resultSize++;

        for (int i = 0; i < wordListVarSize; i++)
        {
            for (int j = 0; j < strlen(beginWordVar); j++)
            {
                if (wordListVar[i][j] == endWordVar[j])
                {
                    occ++;
                }
            }

            if (occ >= history_occ)
            {
                strcpy(result[globalOutput][resultSize], wordListVar[i]);
                resultSize++;
            }

            if (strlen(endWordVar) - occ == 1)
            {
                strcpy(result[globalOutput][resultSize], endWordVar);
                removeIndexElement = i;
                resultSize++;
                break;
            }

            history_occ = occ;
            occ = 0;
        }

        removeIndex(wordListVar, wordListVarSize, removeIndexElement);
        wordListVarSize--;

        for (int i = 0; i < wordListVarSize - 1; i++)
        {
            int temp_occ = 0;

            for (int j = 0; j < strlen(endWordVar); j++)
            {
                if (wordListVar[i][j] == endWordVar[j])
                {
                    temp_occ++;
                }
            }

            if (strlen(endWordVar) - temp_occ == 1)
            {
                flag = true;
                break;
            }
        }

        globalInSize[globalOutput] = resultSize;
        globalOutput++;
        resultSize = 0;
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