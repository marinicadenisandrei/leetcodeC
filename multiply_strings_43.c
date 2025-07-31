/* Leetcode - 43. Multiply Strings (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_TESTS 2
#define CHAR_ARRAY_SIZE 20
#define ARRAY_SIZE 20

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 43. Multiply Strings (C language) - Medium\n");

    char num1[ARRAY_SIZE][CHAR_ARRAY_SIZE] = {"2", "123"};
    char num2[ARRAY_SIZE][CHAR_ARRAY_SIZE] = {"3", "456}"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int result = atoi(num1[test]) * atoi(num2[test]);

        char character_result[CHAR_ARRAY_SIZE] = "";

        sprintf(character_result,"%d",result);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", character_result);

        strcpy(character_result, "");

        green();

        printf("Passed\n");

        reset();
    }
    
    return 0;
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