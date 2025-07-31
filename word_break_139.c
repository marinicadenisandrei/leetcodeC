#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3 

bool wordBreak(char *sVar, char wordDictVar[ARRAY_SIZE][ARRAY_SIZE], int wordDictVarSize);
void replaceSubstring(char *str, const char *subStr, const char *replaceStr);

int main(void)
{
    char s[ARRAY_SIZE][ARRAY_SIZE] = {"leetcode","applepenapple","catsandog"};
    char wordDict[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {{"leet","code"},{"apple","pen"},{"cats","dog","sand","and","cat"}};
    int wordDictInSize[ARRAY_SIZE] = {2, 2, 5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        printf("Test %i: ", test + 1);
        printf("%s | " , ((wordBreak(s[test], wordDict[test], wordDictInSize[test]) == 1) ? "true" : "false"));
        printf("Passed\n");
    }

    return 0;
}

void replaceSubstring(char *str, const char *subStr, const char *replaceStr)
{
    char *pos = strstr(str, subStr);

    if (pos != NULL)
    {
        int subStrLen = strlen(subStr);
        int replaceStrLen = strlen(replaceStr);
        int remainingLen = strlen(pos + subStrLen);

        memmove(pos, pos + subStrLen, remainingLen + 1);
        memcpy(pos, replaceStr, replaceStrLen);
    }
}

bool wordBreak(char *sVar, char wordDictVar[ARRAY_SIZE][ARRAY_SIZE], int wordDictVarSize)
{
    bool flag = true;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < wordDictVarSize; i++)
        {
            if (strstr(sVar, wordDictVar[i]) != NULL)
            {
                flag = true;

                replaceSubstring(sVar, wordDictVar[i], "");
            }
        }

    }

    if (strlen(sVar) == 0)
    {
        return true;
    }

    return false;
}