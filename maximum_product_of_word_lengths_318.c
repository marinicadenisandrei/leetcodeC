/* Leetcode - 318. Maximum Product of Word Lengths (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int maxProduct(char wordsVar[ARRAY_SIZE][ARRAY_SIZE], int wordsVarSize);
bool concatLettersElements(char *string1, char *string2);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{   
    yellow();

    printf("Leetcode - 318. Maximum Product of Word Lengths (C language) - Medium\n");

    char words[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE] = {{"abcw","baz","foo","bar","xtfn","abcdef"},{"a","ab","abc","d","cd","bcd","abcd"},{"a","aa","aaa","aaaa"}};
    int wordsSize[NUMBER_OF_TESTS] = {6,7,4};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", maxProduct(words[test], wordsSize[test]));
        
        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int maxProduct(char wordsVar[ARRAY_SIZE][ARRAY_SIZE], int wordsVarSize)
{
    int maxLen = 0;

    for (int i = 0; i < wordsVarSize; i++)
    {
        for (int j = 0; j < wordsVarSize; j++)
        {
            int lenVar = strlen(wordsVar[i]) * strlen(wordsVar[j]);
            maxLen = ((i != j && maxLen < lenVar && !concatLettersElements(wordsVar[i], wordsVar[j])) ? lenVar : maxLen);
        }
    }

    return maxLen;
}

bool concatLettersElements(char *string1, char *string2)
{
    for (int i = 0; i < strlen(string1); i++)
    {
        for (int j = 0; j < strlen(string2); j++)
        {
            if (string1[i] == string2[j])
            {
                return true;
            }
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
