/* Leetcode - 394. Decode String (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

char* decodeString(char *sVar);

int main()
{
    yellow();

    printf("Leetcode - 394. Decode String (C language) - Medium\n");

    char s[NUMBER_OF_TESTS][ARRAY_SIZE] = {"3[a]2[bc]","3[a2[c]]","2[abc]3[cd]ef"};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        char* output = decodeString(s[test]);
        
        printf("%s | ", output);

        free(output);

        green();

        printf("Passed\n");
    }

    reset();
}

char* decodeString(char *sVar)
{
    char *result = (char*)malloc(ARRAY_SIZE * sizeof(char));
    int resultSize = 0;

    bool flag = true;

    while (flag)
    {
        flag = false;
        int openLastIndex = 0;
        int closeFirstIndex = 0;

        for (int i = 0; i < strlen(sVar); i++)
        {
            openLastIndex = ((sVar[i] == '[') ? i : openLastIndex);
        }

        for (int i = openLastIndex; i < strlen(sVar); i++)
        {
            if (sVar[i] == ']')
            {
                closeFirstIndex = i;
                break;
            }
        }

        if (openLastIndex != 0 && closeFirstIndex != 0)
        {
            flag = true;
        }
        else
        {
            break;
        }
        
        int occ = sVar[openLastIndex - 1] - '0';
        char temp[ARRAY_SIZE] = "";
        int tempSize = 0;

        for (int i = openLastIndex + 1; i < closeFirstIndex; i++)
        {
            temp[tempSize++] = sVar[i];
        }

        temp[tempSize] = '\0';

        char newTemp[ARRAY_SIZE] = "";
        int newTempSize = 0;

        for (int i = 0; i < occ; i++)
        {
            for (int j = 0; j < tempSize; j++)
            {
                newTemp[newTempSize++] = temp[j];
            }
        }

        newTemp[newTempSize] = '\0';

        char newsVar[ARRAY_SIZE] = "";
        int newsVarSize = 0;

        for (int i = 0; i < openLastIndex - 1; i++)
        {
            newsVar[newsVarSize++] = sVar[i];
        }

        for (int i = 0; i < newTempSize; i++)
        {
            newsVar[newsVarSize++] = newTemp[i];
        }

        for (int i = closeFirstIndex + 1; i < strlen(sVar); i++)
        {
            newsVar[newsVarSize++] = sVar[i];
        }

        for (int i = 0; i < newsVarSize; i++)
        {
            sVar[i] = newsVar[i];
        }

        sVar[newsVarSize] = '\0';
    }

    for (int i = 0; i < strlen(sVar); i++)
    {
        result[i] = sVar[i];
    }

    result[strlen(sVar)] = '\0';
    
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