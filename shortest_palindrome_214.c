#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

char* shortestPalindrome(char *sVar);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 214. Shortest Palindrome (C language) - ");

    red();

    printf("Hard\n");

    char s[NUMBER_OF_TESTS][ARRAY_SIZE] = {"aacecaaa","abcd"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        char *output;
        output = shortestPalindrome(s[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", output); 

        green();

        printf("Passed\n");

        free(output);
    }

    reset();
    
    return 0;
}

char* shortestPalindrome(char *sVar)
{
    int sVarSize = strlen(sVar);
    char *suffix = (char*)malloc((2 * sVarSize + 1) * sizeof(char));
    
    if (suffix == NULL) {
        exit(1);
    }

    int suffixSize = 0;

    for (int i = sVarSize - 1, j = 0; i >= 0 ; i--, j++)
    {
        char temp[ARRAY_SIZE];
        suffix[suffixSize] = '\0';

        strcpy(temp, suffix);
        strcat(temp, sVar);

        if (sVar[i] != temp[j])
        {
            suffix[suffixSize] = sVar[i];
            suffixSize++;
        }
    }

    suffix[suffixSize] = '\0';
    strcat(suffix, sVar);

    return suffix;
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