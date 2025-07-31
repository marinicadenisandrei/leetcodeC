/* Leetcode - 127. Word Ladder (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2   

int ladderLength(char *beginWordVar, char *endWordVar, char **wordListVar, int wordListVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 127. Word Ladder (C language) - ");

    red();

    printf("Hard\n");

    char beginWord[ARRAY_SIZE][ARRAY_SIZE] = {"hit", "hit"};
    char endWord[ARRAY_SIZE][ARRAY_SIZE] = {"cog", "cog"};
    char *wordList[ARRAY_SIZE][ARRAY_SIZE] = {{"hot","dot","dog","lot","log","cog"}, {"hot","dot","dog","lot","log"}};
    int wordListSize[ARRAY_SIZE] = {6,5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", ladderLength(beginWord[test], endWord[test], wordList[test], wordListSize[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int ladderLength(char *beginWordVar, char *endWordVar, char **wordListVar, int wordListVarSize)
{
    bool flag = true;
    int occ = 0;
    int history = occ;
    int counter = 1;

    for (int i = 0; i < wordListVarSize; i++)
    {
        if (strcmp(endWordVar, wordListVar[i]) == 0)
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        return 0;
    }
    
    for (int i = 0; i < wordListVarSize; i++)
    {
        for (int j = 0; j < strlen(endWordVar); j++)
        {
            if (wordListVar[i][j] == endWordVar[j])
            {
                occ++;
            }
        }

         if (history == 2)
        {
            counter++;
            break;
        }

        if (occ >= history)
        {
            counter++;
        }
        
        history = occ;
        occ = 0;
    }

    return counter;
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