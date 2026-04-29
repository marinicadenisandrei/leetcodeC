/* Leetcode - 466. Count The Repetitions (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int getMaxRepetitions(char *s1Var, int n1, char *s2Var, int n2);

int main()
{
    yellow();

    printf("Leetcode - 466. Count The Repetitions (C language) - ");

    red();

    printf("Hard\n");

    char s1[NUMBER_OF_TESTS][ARRAY_SIZE] = {"acb","acb"};
    int n1[NUMBER_OF_TESTS] = {4,1};
    char s2[NUMBER_OF_TESTS][ARRAY_SIZE] = {"ab","acb"};
    int n2[NUMBER_OF_TESTS] = {2,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", getMaxRepetitions(s1[test], n1[test], s2[test], n2[test]));

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

int getMaxRepetitions(char *s1Var, int n1, char *s2Var, int n2)
{
    int output = 0;

    int len1 = strlen(s1Var);
    char result1[ARRAY_SIZE];
    result1[0] = '\0'; 

    for (int i = 0; i < n1; i++) {
        strcat(result1, s1Var);
    }

    int len2 = strlen(s2Var);
    char result2[ARRAY_SIZE];
    result2[0] = '\0'; 

    for (int i = 0; i < n2; i++) {
        strcat(result2, s2Var);
    }

    int indexCursor1 = 0;
    int indexCursor2 = 0;

    while (indexCursor1 < strlen(result1))
    {
        if (result1[indexCursor1] == result2[indexCursor2]) {
            indexCursor2++;
        }   

        if (indexCursor2 == strlen(result2))
        {
            indexCursor2 = 0;
            output++;
        }
        
        indexCursor1++;
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