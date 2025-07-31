/* Leetcode - 336. Palindrome Pairs (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int resultSize = 0;

int** palindromePairs(char wordsVar[ARRAY_SIZE][ARRAY_SIZE], int wordsVarSize);
bool isPalindrome(char *string1, char *string2);
void print2DArray(int **array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 336. Palindrome Pairs (C language) - ");

    red();

    printf("Hard\n");

    char words[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE] = {{"abcd", "dcba", "lls", "s", "sssll"}, {"bat","tab","cat"}, {"a",""}};
    int wordsSize[NUMBER_OF_TESTS] = {5,3,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int **result = palindromePairs(words[test], wordsSize[test]);
        print2DArray(result, resultSize);

        for (int i = 0; i < resultSize; i++) {
            free(result[i]);
        }
        free(result);

        resultSize = 0;

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

void print2DArray(int **array, int arraySize)
{
    printf("[");
    for (int i = 0; i < arraySize; i++)
    {
        printf("[%d, %d]", array[i][0], array[i][1]);
        if (i < arraySize - 1)
            printf(", ");
    }
    printf("] | ");
}

bool isPalindrome(char *string1, char *string2)
{
    char temp[ARRAY_SIZE * 2];
    strcpy(temp, string1);
    strcat(temp, string2);

    int len = strlen(temp);
    for (int i = 0; i < len / 2; i++)
    {
        if (temp[i] != temp[len - 1 - i])
        {
            return false;
        }
    }

    return true;
}

int** palindromePairs(char wordsVar[ARRAY_SIZE][ARRAY_SIZE], int wordsVarSize)
{
    int** result = (int**)malloc(ARRAY_SIZE * sizeof(int*));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        result[i] = (int*)malloc(2 * sizeof(int));
    }

    for (int i = 0; i < wordsVarSize; i++)
    {
        for (int j = 0; j < wordsVarSize; j++)
        {
            if (i != j && isPalindrome(wordsVar[i], wordsVar[j]))
            {
                result[resultSize][0] = i;
                result[resultSize][1] = j;
                resultSize++;
            }
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