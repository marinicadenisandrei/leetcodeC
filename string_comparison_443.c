/* Leetcode - 443. String Compression (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

char** compress(char charsVar[ARRAY_SIZE][2], int charsSizeVar, int *resultSizeVar);
void printStringArray(char** arr, int arrSize);

int main(void)
{
    yellow();

    printf("Leetcode - 443. String Compression (C language) - Medium\n");

    char chars[NUMBER_OF_TESTS][ARRAY_SIZE][2] = {{"a","a","b","b","c","c","c"},{"a"},{"a","b","b","b","b","b","b","b","b","b","b","b","b"}};
    int charsSize[NUMBER_OF_TESTS] = {7,1,13};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int resultSize = 0;
        char **result = compress(chars[test], charsSize[test], &resultSize);
        printStringArray(result, resultSize);

        if (!result) {
            return 1;
        }
        for (int i = 0; i < resultSize; i++) {
            free(result[i]);
        }
        free(result);

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

void printStringArray(char** arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%s%s%s", ((i == 0) ? "[" : ""), arr[i], ((i < arrSize - 1) ? ", " : "] | "));
    }
}

char** compress(char charsVar[ARRAY_SIZE][2], int charsSizeVar, int *resultSizeVar)
{
    char **result = malloc(ARRAY_SIZE * sizeof(char*));
    if (!result) return NULL;

    int counter = 1;
    int resPos = 0;

    for (int i = 0; i < charsSizeVar; i++) {
        if (i + 1 < charsSizeVar && charsVar[i][0] == charsVar[i + 1][0]) 
        {
            counter++;
        } 
        else 
        {
            result[resPos] = malloc(2);
            sprintf(result[resPos++], "%c", charsVar[i][0]);

            char temp[16];
            sprintf(temp, "%d", counter);
            result[resPos] = malloc(strlen(temp) + 1);
            strcpy(result[resPos++], temp);

            counter = 1;
        }
    }

    *resultSizeVar = resPos;
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