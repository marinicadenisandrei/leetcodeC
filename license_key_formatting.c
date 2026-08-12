/* Leetcode - 482. License Key Formatting (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

char* licenseKeyFormatting(char sVar[], int kVar);

int main()
{
    yellow();

    printf("Leetcode - 482. License Key Formatting (C language) - ");

    green();

    printf("Easy\n");

    char s[ARRAY_SIZE][ARRAY_SIZE] = {"5F3Z-2e-9-w","2-5g-3-J"};
    int k[ARRAY_SIZE] = {4,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);
        
        reset();
        
        printf("%s | ", licenseKeyFormatting(s[test], k[test]));

        green();

        printf("Passed\n");
    }

    reset();
}

char* licenseKeyFormatting(char sVar[], int kVar)
{
    int j = 0;

    for (int i = 0; sVar[i] != '\0'; i++) {
        if (sVar[i] != '-') {
            sVar[j++] = sVar[i];
        }
    }

    sVar[j] = '\0';
    
    char splits[ARRAY_SIZE][ARRAY_SIZE];
    int splitsSize = 0;
    
    int len = strlen(sVar);
    char chunk[ARRAY_SIZE];
    
    char *result = malloc(ARRAY_SIZE);
    result[0] = '\0';       

    while (len > 0) {
        int take = (len >= kVar) ? kVar : 1;
        int start = len - take;

        strncpy(chunk, sVar + start, take);
        chunk[take] = '\0';

        if (result[0] != '\0') {
            char tmp[ARRAY_SIZE];
            snprintf(tmp, sizeof tmp, "%s-%s", chunk, result);
            strcpy(result, tmp);
        } else {
            strcpy(result, chunk);
        }

        len = start;
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