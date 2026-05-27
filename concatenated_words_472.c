/* Leetcode - 472. Concatenated Words (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUMBER_OF_TESTS 2
#define ARRAY_SIZE 20

void reset ();
void green ();
void yellow ();
void red ();

char** findAllConcatenatedWordsInADict(char wordsVar[ARRAY_SIZE][ARRAY_SIZE], int wordsSizeVar, int *resultSizeVar);
int compareByLengthDescending(const void *a, const void *b);
void printArrOfStrings(char **arr, int arrSize);
void freeArrOfStrings(char **arr, int capacity);

int main()
{
    yellow();

    printf("Leetcode - 472. Concatenated Words (C language) - ");

    red();

    printf("Hard\n");

    char words[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE] = {{"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"},{"cat","dog","catdog"}};
    int wordsSize[NUMBER_OF_TESTS] = {8,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int resultSize = 0;
        char **result = findAllConcatenatedWordsInADict(words[test], wordsSize[test], &resultSize);
        printArrOfStrings(result, resultSize);
        freeArrOfStrings(result, ARRAY_SIZE);

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

char** findAllConcatenatedWordsInADict(char wordsVar[ARRAY_SIZE][ARRAY_SIZE], int wordsSizeVar, int *resultSizeVar)
{
    char** result = malloc(ARRAY_SIZE * sizeof(char*));

    if (result == NULL) {
        return NULL;
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        result[i] = malloc(20 * sizeof(char));

        if (result[i] == NULL) {
            return NULL;
        }
    }
    
    qsort(wordsVar, wordsSizeVar, ARRAY_SIZE * sizeof(char), compareByLengthDescending);

    for (int i = 0; i < wordsSizeVar; i++)
    {
        bool flag = true;

        char str[ARRAY_SIZE];
        strcpy(str, wordsVar[i]);

        while (flag)
        {
            flag = false;

            for (int j = 0; j < wordsSizeVar; j++)
            {
                if (i != j && strstr(str, wordsVar[j]) != NULL)
                {
                    char *pos;

                    while ((pos = strstr(str, wordsVar[j])) != NULL) {
                        memmove(
                            pos,
                            pos + strlen(wordsVar[j]),
                            strlen(pos + strlen(wordsVar[j])) + 1
                        );
                    }

                    flag = true;
                }
            }
        }

        if (strlen(str) == 0)
        {
            strcpy(result[*resultSizeVar], wordsVar[i]);
            (*resultSizeVar)++;
        }
    }

    return result;
}

int compareByLengthDescending(const void *a, const void *b)
{
    const char *word1 = (const char *)a;
    const char *word2 = (const char *)b;

    return strlen(word2) - strlen(word1);
}

void printArrOfStrings(char **arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%s%s%s", ((i == 0) ? "[" : ""), arr[i], ((i < arrSize - 1) ? ", " : "] | "));
    }
}

void freeArrOfStrings(char **arr, int capacity)
{
    if (arr == NULL) return;
    for (int i = 0; i < capacity; i++) free(arr[i]);
    free(arr);
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