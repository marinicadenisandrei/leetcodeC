/* Leetcode - 434. Number of Segments in a String (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 40
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int countSegments(char* sVar);

int main()
{
    yellow();

    printf("Leetcode - 434. Number of Segments in a String (C language) - ");

    green();

    printf("Easy\n");

    char s[NUMBER_OF_TESTS][ARRAY_SIZE] = {"Hello, my name is John", "Hello"};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", countSegments(s[test]));

        green();

        printf("Passed\n");
    }

    reset();
}

int countSegments(char* sVar)
{
    int result = 0;

    for (int i = 1; i < strlen(sVar); i++)
    {
        result += ((sVar[i - 1] == ' ' && sVar[i] != ' ') ? 1 : 0);
    }
    
    return result + 1;
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