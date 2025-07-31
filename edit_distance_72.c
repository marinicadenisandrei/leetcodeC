/* Leetcode - 72. Edit Distance (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20

int editDistance(char var1[ARRAY_SIZE], char var2[ARRAY_SIZE]);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 72. Edit Distance (C language) - Medium\n");

    char word1[ARRAY_SIZE][ARRAY_SIZE] = {"horese", "intention"};
    char word2[ARRAY_SIZE][ARRAY_SIZE] = {"ros", "execution"};

    int size_word1 = 2;

    for (int test = 0; test < size_word1; test++)
    {
        int result = editDistance(word1[test], word2[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", result);

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int editDistance(char var1[ARRAY_SIZE], char var2[ARRAY_SIZE])
{
    int editVar = ((strlen(var1) == strlen(var2)) ? 0 : 1);

    for (int i = 0; i < strlen(var2); i++)
    {
        if (var1[i] != var2[i])
        {
            editVar++;
        }
    }
    
    return editVar;
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