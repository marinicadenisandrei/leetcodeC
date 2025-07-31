/* Leetcode - 131. Palindrome Partitioning (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

char ***partition(char *s);
bool checkPalindromeChars(char *charVar);
void displayTwoArrayChars(char ***array);

void reset ();
void green ();
void yellow ();
void red ();

int resultSize[2] = {0};

int main(void)
{
    yellow();

    printf("Leetcode - 131. Palindrome Partitioning (C language) - Medium\n");

    char *s[ARRAY_SIZE] = {"aab", "a"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        char ***output = (char ***)malloc(2 * sizeof(char **)); // Allocate memory for result

        for (int i = 0; i < 2; i++)
        {
            output[i] = (char **)malloc(ARRAY_SIZE * sizeof(char *));
            for (int j = 0; j < ARRAY_SIZE; j++)
            {
                output[i][j] = (char *)malloc((ARRAY_SIZE + 1) * sizeof(char));
            }
        }

        output = partition(s[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        displayTwoArrayChars(output);

        green();

        printf("Passed\n");

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < ARRAY_SIZE; j++)
            {
                free(output[i][j]);
            }
            free(output[i]);
        }
        free(output);

        resultSize[0] = 0;
        resultSize[1] = 0;
    }

    reset();

    return 0;
}

void displayTwoArrayChars(char ***array)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < resultSize[i]; j++)
        {
            printf("%s%s%s", ((j == 0) ? "[" : ""), array[i][j], ((j < resultSize[i] - 1) ? ", " : "]"));
        }
    }

    printf(" | ");
}

bool checkPalindromeChars(char *charVar)
{
    for (int i = strlen(charVar) - 1, j = 0; i >= 0; i--, j++)
    {
        if (charVar[i] != charVar[j])
        {
            return false;
        } 
    }

    return true;
}

char ***partition(char *s)
{
    char ***result = (char ***)malloc(2 * sizeof(char **)); // Allocate memory for result

    for (int i = 0; i < 2; i++)
    {
        result[i] = (char **)malloc(ARRAY_SIZE * sizeof(char *));
        for (int j = 0; j < ARRAY_SIZE; j++)
        {
            result[i][j] = (char *)malloc((ARRAY_SIZE + 1) * sizeof(char));
        }
    }
    
    resultSize[0] = strlen(s); 

    if (strlen(s) == 1)
    {
        result[0][0][0] = s[0];
        result[0][0][1] = '\0';

        return result;
    }

    for (int i = 0; i < strlen(s); i++)
    {
        result[0][i][0] = s[i];
        result[0][i][1] = '\0';
    }

    for (int i = 0; i < strlen(s); i++)
    {
        char temp[ARRAY_SIZE] = "";
        int i_temp = 0;

        for (int j = i; j < strlen(s); j++)
        {
            char format[2];
            format[0] = s[j];
            format[1] = '\0';

            strcat(temp, format); 

            if (checkPalindromeChars(temp))
            {
                char tempChar[2];
                tempChar[0] = s[j];
                tempChar[1] = '\0';

                strcpy(result[1][resultSize[1]], temp);
                resultSize[1]++;
            }
        }

        strcpy(temp, "");
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

