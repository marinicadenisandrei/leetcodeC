/* Leetcode - 234. Palindrome Linked List (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

bool isPalindrome(int *headVar, int headVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 234. Palindrome Linked List (C language) - ");

    green();

    printf("Easy\n");

    int head[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2,2,1},{1,2}};
    int headSize[NUMBER_OF_TESTS] = {4,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", ((isPalindrome(head[test], headSize[test]) == 1) ? "true" : "false"));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

bool isPalindrome(int *headVar, int headVarSize)
{
    for (int i = 0; i < headVarSize; i++)
    {
        if (headVar[i] != headVar[headVarSize - 1 - i])
        {
            return false;
        }
    }

    return true;
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