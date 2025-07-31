/* Leetcode - 345. Reverse Vowels of a String (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

char vowelsDatabase[ARRAY_SIZE][1] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
int vowelsDatabaseSize = 10;

void reset ();
void green ();
void yellow ();
void red ();

void reverseVowels(char *sVar);

int main()
{
    yellow();

    printf("Leetcode - 345. Reverse Vowels of a String (C language) - ");

    green();

    printf("Easy\n");

    char s[NUMBER_OF_TESTS][ARRAY_SIZE] = {"IceCreAm","leetcode"};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        reverseVowels(s[test]);
        printf("%s | ", s[test]);

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

void reverseVowels(char *sVar)
{
    char candidates[ARRAY_SIZE][1] = {};
    char candidatesIndex[ARRAY_SIZE] = {};

    int candidatesSize = 0;

    for (int i = 0; i < strlen(sVar); i++)
    {
        bool flag = false;

        for (int j = 0; j < vowelsDatabaseSize; j++)
        {
            if (vowelsDatabase[j][0]== sVar[i])
            {
                flag = true;
            }
            
        }

        if (flag)
        {
            candidates[candidatesSize][0] = sVar[i];
            candidatesIndex[candidatesSize++] = i;
        }
    }

    for (int i = candidatesSize - 1; i >= 0; i--)
    {
        sVar[candidatesIndex[i]] = candidates[candidatesSize - 1 - i][0];
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