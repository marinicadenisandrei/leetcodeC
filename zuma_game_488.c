/* Leetcode - 488. Zuma Game (C language) - Hard */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define ARRAY_SIZE 32
#define NUMBER_OF_TESTS 3

int findMinStep(char* boardVar, char* handVar);
void removeSubstring(char* str, int start, int end);
void insertCharacter(char* str, int index, char c);
void collapseBoard(char* str);
char **generateRotations(const char *str);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 488. Zuma Game (C language) - ");

    red();

    printf("Hard\n");

    char board[NUMBER_OF_TESTS][ARRAY_SIZE] = {
        "WRRBBW",
        "WWRRBBWW",
        "G"
    };

    char hand[NUMBER_OF_TESTS][ARRAY_SIZE] = {
        "RB",
        "WRBRW",
        "GGGGG"
    };

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", findMinStep(board[test], hand[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int findMinStep(char* boardVar, char* handVar)
{
    char* copyBoard = malloc(strlen(boardVar) + 1);
    strcpy(copyBoard, boardVar);

    char **rotationHand = generateRotations(handVar);

    int handLen = strlen(handVar);

    int result = INT_MAX;

    for (int k = 0; k < handLen; k++)
    {
        strcpy(boardVar, copyBoard);

        int tempResult = 0;

        for (int i = 0; i < handLen; i++)
        {
            char currentHand = rotationHand[k][i];

            int indexesMax[2] = {-1, -1};
            int maxLen = 0;

            int j = 0;
            int n = strlen(boardVar);

            while (j < n)
            {
                if (boardVar[j] == currentHand)
                {
                    int start = j;

                    while (
                        j < n &&
                        boardVar[j] == currentHand
                    )
                    {
                        j++;
                    }

                    int end = j - 1;

                    int currentLen = end - start + 1;

                    if (currentLen > maxLen)
                    {
                        maxLen = currentLen;

                        indexesMax[0] = start;
                        indexesMax[1] = end;
                    }
                }
                else
                {
                    j++;
                }
            }

            if (indexesMax[0] != -1)
            {
                tempResult++;

                if (maxLen >= 2)
                {
                    removeSubstring(
                        boardVar,
                        indexesMax[0],
                        indexesMax[1]
                    );

                    collapseBoard(boardVar);
                }
                else
                {
                    insertCharacter(
                        boardVar,
                        indexesMax[1] + 1,
                        currentHand
                    );
                }
            }

            if (strlen(boardVar) == 0)
            {
                if (tempResult < result)
                {
                    result = tempResult;
                }

                break;
            }
        }
    }

    for (int i = 0; i < handLen; i++)
    {
        free(rotationHand[i]);
    }

    free(rotationHand);
    free(copyBoard);

    if (result == INT_MAX)
    {
        return -1;
    }

    return result;
}

void removeSubstring(char* str, int start, int end)
{
    memmove(
        &str[start],
        &str[end + 1],
        strlen(str) - end
    );
}

void insertCharacter(char* str, int index, char c)
{
    int len = strlen(str);

    memmove(
        &str[index + 1],
        &str[index],
        len - index + 1
    );

    str[index] = c;
}

void collapseBoard(char* str)
{
    int removed = 1;

    while (removed)
    {
        removed = 0;

        int n = strlen(str);
        int i = 0;

        while (i < n)
        {
            int start = i;
            char current = str[i];

            while (
                i < n &&
                str[i] == current
            )
            {
                i++;
            }

            int end = i - 1;
            int len = end - start + 1;

            if (len >= 3)
            {
                removeSubstring(
                    str,
                    start,
                    end
                );

                removed = 1;

                break;
            }
        }
    }
}

char **generateRotations(const char *str)
{
    int len = strlen(str);

    char **result = malloc(
        len * sizeof(char *)
    );

    for (int i = 0; i < len; i++)
    {
        result[i] = malloc(
            (len + 1) * sizeof(char)
        );

        for (int j = 0; j < len; j++)
        {
            result[i][j] =
                str[(i + j) % len];
        }

        result[i][len] = '\0';
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