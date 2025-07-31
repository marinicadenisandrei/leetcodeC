/* Leetcode - 151. Reverse Words in a String (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 40
#define NUMBER_OF_TESTS 3

void reverseWords(char *sVar);
void removeGaps(char *sVar);
void removeIndex(char *stringVar, int index);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 151. Reverse Words in a String (C language) - Medium\n");

    char s[ARRAY_SIZE][ARRAY_SIZE] = {"the sky is blue","  hello world  ","a good   example"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        reverseWords(s[test]);
        printf("%s | ", s[test]);

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

void removeIndex(char *stringVar, int index)
{
    int size = strlen(stringVar);

    for (int i = index; i < size - 1; i++)
    {
        stringVar[i] = stringVar[i + 1];        
    }

    stringVar[size - 1] = '\0';
}

void removeGaps(char *sVar)
{   
    while (sVar[0] == ' ')
    {
        removeIndex(sVar, 0);
    }

    while (sVar[strlen(sVar) - 1] == ' ')
    {
        removeIndex(sVar, strlen(sVar) - 1);
    }
}

void reverseWords(char *sVar)
{
    removeGaps(sVar);

    char newChar[ARRAY_SIZE];
    newChar[0] = '\0';

    char temp[ARRAY_SIZE];
    temp[0] = '\0';
    int tempSize = 0;

    int remainLen = strlen(sVar);

    for (int i = remainLen - 1; i >= 0; i--)
    {
        if (sVar[i] == ' ' || i == 0)
        {
            int minus = ((i == 0) ? 1 : 0);

            for (int j = i + 1 - minus; j < remainLen; j++)
            {
                temp[tempSize++] = sVar[j];
            }
            
            removeGaps(temp);

            temp[tempSize++] = ' ';
            temp[tempSize] = '\0';

            if (temp[0] != ' ')
            {
                strcat(newChar, temp);
            }

            strcpy(temp, "");
            tempSize = 0;

            remainLen = i;
        }
    }

    removeGaps(newChar);
    strcpy(sVar, newChar);
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