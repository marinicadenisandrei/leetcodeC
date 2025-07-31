/* Leetcode - 400. Nth Digit (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 50
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int findNthDigit(int nVar);

int main()
{
    yellow();

    printf("Leetcode - 400. Nth Digit (C language) - Medium\n");

    int n[NUMBER_OF_TESTS] = {3,11};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();
        
        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", findNthDigit(n[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int findNthDigit(int nVar)
{
    char buffer[ARRAY_SIZE] = "";
    int bufferSize = 0;

    for (int i = 1; i <= nVar; i++)
    {
        char buf[12];
        sprintf(buf, "%d", i);

        for (int j = 0; j < strlen(buf); j++)
        {
            buffer[bufferSize++] = buf[j];
        }
    }

    buffer[bufferSize] = '\0';
    
    return buffer[nVar - 1] - '0';
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
