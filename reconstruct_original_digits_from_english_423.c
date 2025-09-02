/* Leetcode - 423. Reconstruct Original Digits from English (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

char* originalDigits(char* sVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 423. Reconstruct Original Digits from English (C language) - Medium\n");

    char s[NUMBER_OF_TESTS][ARRAY_SIZE] = {"owoztneoer","fviefuro"};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", originalDigits(s[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

char* originalDigits(char* sVar)
{
    char candidates[ARRAY_SIZE][ARRAY_SIZE] = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };

    char candidatesMath[ARRAY_SIZE][ARRAY_SIZE] = {
        "0",
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9"
    };

    int candidatesSize = 9; 

    char* result = (char*)malloc(ARRAY_SIZE * sizeof(char));
    char resultSize = 0;

    bool flag = true;

    for (int i = 0; i < candidatesSize; i++)
    {
        int indexes[ARRAY_SIZE] = {};
        int indexesSize = 0;

        for (int j = 0; j < strlen(candidates[i]); j++)
        {
            for (int k = 0; k < strlen(sVar); k++)
            {
                if (candidates[i][j] == sVar[k])
                {
                    bool indexExist = false;

                    for (int l = 0; l < indexesSize; l++)
                    {
                        if (indexes[l] == k)
                        {
                            indexExist = true;
                            break;
                        }
                    }

                    if (!indexExist)
                    {
                        indexes[indexesSize++] = k;
                        break;
                    }
                }
            }

            if (indexesSize == strlen(candidates[i]))
            {
                result[resultSize++] = candidatesMath[i][0];
                int sVarSize = strlen(sVar);            
                int removed = 0;

                for (int k = 0; k < indexesSize; k++)
                {
                    int indexToRemove = indexes[k];
                    sVar[indexToRemove] = '@';
                }
            }
        }
    }

    result[resultSize] = '\0';
    
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