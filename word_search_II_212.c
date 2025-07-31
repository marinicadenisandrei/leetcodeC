/* Leetcode - 212. Word Search II (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

char** findWords(char boardVar[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int boardVarSize, char wordsVar[ARRAY_SIZE][ARRAY_SIZE], int wordsSize);
void printArray(char **array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int outputSize = 0;

int main(void)
{
    yellow();

    printf("Leetcode - 212. Word Search II (C language) - ");

    red();

    printf("Hard\n");

    char board[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {{{"o","a","a","n"},{"e","t","a","e"},{"i","h","k","r"},{"i","f","l","v"}},{{"a","b"},{"c","d"}}};
    int boardSize[NUMBER_OF_TESTS] = {4,2};

    char words[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE] = {{"oath","pea","eat","rain"}, {"abcb"}};
    int wordsSize[NUMBER_OF_TESTS] = {4,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        char **result = (char **)malloc(ARRAY_SIZE * sizeof(char *));
        for (int i = 0; i < outputSize; i++)
        {
            result[i] = (char *)malloc(ARRAY_SIZE * sizeof(char)); 
        }
        
        green();

        printf("Test %i: ", test + 1);

        reset();

        result = findWords(board[test], boardSize[test], words[test], wordsSize[test]);
        printArray(result, outputSize);

        green();

        printf("Passed\n");
        
        for (int i = 0; i < outputSize; i++)
        {
            free(result[i]); 
        }

        free(result);
        outputSize = 0;
    }

    reset();
}

void printArray(char **array, int arraySize)
{
    if (arraySize == 0)
    {
        printf("[] | ");
        return;
    }
    
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%s%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "] | "));
    }
}

char** findWords(char boardVar[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int boardVarSize, char wordsVar[ARRAY_SIZE][ARRAY_SIZE], int wordsSize)
{
    char **output = (char **)malloc(ARRAY_SIZE * sizeof(char *));

    for (int i = 0; i < wordsSize; i++)
    {
        int his_k = 0;
        int his_l = 0;

        bool flag = false;

        for (int j = 0; j < strlen(wordsVar[i]); j++)
        {
            flag = false;

            for (int k = 0; k < boardVarSize; k++)
            {
                for (int l = 0; l < boardVarSize; l++)
                {
                    if (wordsVar[i][j] == boardVar[k][l][0])
                    {
                        if (his_k - k <= 1 && his_l - l <= 1 && his_k <= k)
                        {
                            his_k = k;
                            his_l = l;
                            flag = true;
                            break;
                        }
                    }

                    if (flag)
                    {
                        break;
                    }
                }

                if (flag)
                {
                    break;
                }
            }

            if (!flag)
            {
                break;
            }
        }

        if (flag)
        {
            output[outputSize] = (char *)malloc(ARRAY_SIZE * sizeof(char)); 
            strcpy(output[outputSize], wordsVar[i]);
            outputSize++;
        }
    }
    
    return output;
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