/* Leetcode - 438. Find All Anagrams in a String (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int* findAnagrams(char* sVar, char* pVar, int* resultSize);
void sortString(char *str);
void printArray(int* arr, int arrSize);

int main()
{
    yellow();   

    printf("Leetcode - 438. Find All Anagrams in a String (C language) - Medium\n");

    char s[NUMBER_OF_TESTS][ARRAY_SIZE] = {"cbaebabacd","abab"};
    char p[NUMBER_OF_TESTS][ARRAY_SIZE] = {"abc","ab"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int resultSize = 0;
        int* output = findAnagrams(s[test], p[test], &resultSize);
        printArray(output, resultSize);

        free(output);

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

void printArray(int* arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), arr[i], ((i < arrSize - 1) ? ", " : "] | "));
    }    
}

void sortString(char *str) {
    int n = strlen(str);
    char temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int* findAnagrams(char* sVar, char* pVar, int* resultSize)
{
    int* result = (int*)malloc(ARRAY_SIZE * sizeof(int));


    sortString(pVar);

    for (int i = 0; i <= strlen(sVar) - strlen(pVar); i++)
    {
        char temp[ARRAY_SIZE] = "";
        int tempSize = 0;

        for (int j = i; j < i + strlen(pVar); j++)
        {
            temp[tempSize++] = sVar[j];
        }

        temp[tempSize] = '\0';
        sortString(temp);

        if (strcmp(temp, pVar) == 0)
        {
            result[(*resultSize)++] = i;
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