/* Leetcode - 32. Longest Valid Parentheses (C language) - Hard */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define STRING_SIZE 30
#define NUMBER_OF_TESTS 3

struct parenthesesHistory
{
    int counterRight;
    int counterLeft;
};

int longestValidPar(char string[STRING_SIZE]);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();
    printf("Leetcode - 32. Longest Valid Parentheses (C language) - ");

    red();
    printf("Hard\n");

    char sTest[NUMBER_OF_TESTS][STRING_SIZE] = {"(()", ")()())", ""};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int result = 0;

        result = longestValidPar(sTest[test]);

        green();
        printf("Test %i: ", test + 1);

        reset();
        printf("%i | ", result);

        green();
        printf("Passed\n");

        reset();
    }
    

    return 0;
}

int longestValidPar(char string[STRING_SIZE])
{
    int stringLen = strlen(string);
    struct parenthesesHistory parentheses = {0, 0};
    

    for (int i = 0; i < stringLen; i++)
    {
        parentheses.counterRight += (string[i] == '(') ? 1 : 0;
        parentheses.counterLeft += (string[i] == ')') ? 1 : 0;
    }
    
    return fmin(parentheses.counterLeft, parentheses.counterRight) * 2;
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