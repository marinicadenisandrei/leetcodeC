/* Leetcode - 166. Fraction to Recurring Decimal (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

char *fractionToDecimal(int numeratorVar, int denominatorVar);
bool occSubstrInStr(char *string, char *substr);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 166. Fraction to Recurring Decimal (C language) - Medium\n");

    int numerator[ARRAY_SIZE] = {1,2,4};
    int denominator[ARRAY_SIZE] = {2,1,333};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        char *result = fractionToDecimal(numerator[test], denominator[test]);

        printf("%s | ", result);

        free(result);

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

bool occSubstrInStr(char *string, char *substr)
{
    int occ = 0;

    for (int i = 0; i < strlen(string); i++)
    {
        if (substr[0] == string[0])
        {
            bool flag = true;

            for (int j = 1; j < strlen(substr); j++)
            {
                if (string[i + j] != substr[j])
                {
                    flag = false;
                }
            }

            if (flag)
            {
                occ++;
            }
        }
    }

    if (occ > 1)
    {
        return true;
    }

    return false;
}

char *fractionToDecimal(int numeratorVar, int denominatorVar)
{
    float result = (float)numeratorVar / denominatorVar;
    char str[ARRAY_SIZE];

    sprintf(str, "%f", result);

    int indexPoint = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '.')
        {
            indexPoint = i;
        }
    }
    
    char temp[ARRAY_SIZE];
    int tempSize = 0;

    int maxString = 0;

    char stringResult[20];

    for (int i = indexPoint + 1; i < strlen(str); i++)
    {
        temp[tempSize++] = str[i];
        temp[tempSize] = '\0';

        if (occSubstrInStr(str, temp))
        {
            if (strlen(temp) > maxString)
            {
                maxString = strlen(temp);
                strcpy(stringResult, temp);
            }
        }
    }

    if (maxString > 0)
    {
        strcpy(temp, "");
        strncpy(temp, str, indexPoint + 1);
        temp[indexPoint + 1] = '\0';
        strcat(temp, "(");
        strcat(temp, stringResult);
        strcat(temp, ")");

        return strdup(temp);
    }
    else
    {
        return strdup(str);
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