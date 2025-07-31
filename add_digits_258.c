/* Leetcode - 258. Add Digits (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_TESTS 2

int addDigits(int numVar);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 258. Add Digits (C language) - ");

    green();

    printf("Easy\n");

    int num[NUMBER_OF_TESTS] = {38,0};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", addDigits(num[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int addDigits(int numVar)
{
    char temp[20];
    sprintf(temp, "%d", numVar); 
    
    while (strlen(temp) > 1)
    {
        int sum = 0;
        for (int i = 0; i < strlen(temp); i++)
        {
            int integer = temp[i] - '0'; 
            sum += integer;
        }
        
        strcpy(temp, "");
        sprintf(temp, "%d", sum);
    }

    return temp[0] - '0';
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