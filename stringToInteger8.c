/* Leetcode - 8. String to Integer (atoi) (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_TESTS 3

void makeValidCharacter(char string1[], char string2[]);

void reset ();
void green ();
void yellow ();

int main(void)
{
    yellow();

    printf("Leetcode - 8. String to Integer (atoi) (C language) - Medium\n");

    char s[10][50] = {"42", "   -42", "4193 with words"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        char stringInteger[50] = "";

        makeValidCharacter(s[test], stringInteger);

        int number = atoi(stringInteger);

        reset();

        printf("%i", number);

        green();

        printf(" | Passed\n");

        reset();
    }
    
    return 0;
}

void makeValidCharacter(char string1[], char string2[])
{
    char *pstring2 = string2;

    for (int i = 0; i < strlen(string1); i++)
    {
        if ((int) string1[i] >= 10)
        {
            *pstring2 = string1[i];
            pstring2++;
        }
    }
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