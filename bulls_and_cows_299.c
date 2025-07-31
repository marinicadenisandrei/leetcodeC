/* Leetcode - 299. Bulls and Cows (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

char* getHint(char *secretVar, char * guessVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 299. Bulls and Cows (C language) - Medium\n");

    char secret[NUMBER_OF_TESTS][ARRAY_SIZE] = {"1807","1123"};
    char guess[NUMBER_OF_TESTS][ARRAY_SIZE] = {"7810","0111"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", getHint(secret[test], guess[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

char* getHint(char *secretVar, char * guessVar)
{
    char *aVar = (char*)malloc(sizeof(char) * 5);
    strcpy(aVar, "0A0B");
    
    char candidates[ARRAY_SIZE] = "";
    int candidatesSize = 0;
 
    int counterA = 0;
    int counterB = 0;

    for (int i = 0; i < strlen(secretVar); i++)
    {
        if (secretVar[i] == guessVar[i])
        {
            counterA++;
            secretVar[i] = 'x';
        }
    }

    for (int i = 0; i < strlen(guessVar); i++)
    {
        bool flag = false;

        for (int j = 0; j < candidatesSize; j++)
        {
            if (candidates[j] == guessVar[i])
            {
                flag = true;
                break;
            }
        }

        if (!flag)
        {
            candidates[candidatesSize++] = guessVar[i];
        }
    }

    for (int i = 0; i < candidatesSize; i++)
    {
        int counter = 0;

        for (int j = 0; j < strlen(secretVar); j++)
        {
            if (secretVar[j] == candidates[i])
            {
                counter++;
            }
        }

        counterB += counter;
    }

    aVar[0] = counterA + '0';
    aVar[2] = counterB + '0';

    return aVar;
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