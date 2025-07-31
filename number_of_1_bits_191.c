/* Leetcode - 191. Number of 1 Bits (C language) - Easy */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define ARRAY_SIZE 40
#define NUMBER_OF_TESTS 3

int hammingWeight(char *nVar);

void reset ();
void green ();
void yellow ();
void red ();

int main() {
    yellow();

    printf("Leetcode - 191. Number of 1 Bits (C language) - ");

    green();

    printf("Easy\n");

    char n[NUMBER_OF_TESTS][ARRAY_SIZE] = {"00000000000000000000000000001011","00000000000000000000000010000000","11111111111111111111111111111101"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {   
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | " ,hammingWeight(n[test]));

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

int hammingWeight(char *nVar)
{
    int count = 0;

    for (int i = 0; i < strlen(nVar); i++)
    {
        if (nVar[i] == '1')
        {
            count++;
        }
    }

    return count;
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