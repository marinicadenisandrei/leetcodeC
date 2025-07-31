/* Leetcode - 190. Reverse Bits (C language) - Easy */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define ARRAY_SIZE 35
#define NUMBER_OF_TESTS 2

unsigned int reverseBits(char *nVar);
unsigned int bitsToDecimal(char *bits);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 190. Reverse Bits (C language) - ");

    green();

    printf("Easy\n");

    char n[NUMBER_OF_TESTS][ARRAY_SIZE] = {"00000010100101000001111010011100","11111111111111111111111111111101"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        unsigned int result = reverseBits(n[test]); 

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%u | ", result);

        green();

        printf("Passed\n"); 
    }

    reset();

    return 0;
}

unsigned int reverseBits(char *nVar)
{
    char reverse[ARRAY_SIZE] = "";
    int reverseSize = 0;

    for (int i = strlen(nVar) - 1; i >= 0; i--)
    {
        reverse[reverseSize++] = nVar[i];
    }

    reverse[strlen(nVar)] = '\0';

    return bitsToDecimal(reverse);
}

unsigned int bitsToDecimal(char *bits)
{
    unsigned long power = 0;
    unsigned int number = 0;

    for (int i = strlen(bits) - 1; i >= 0; i--)
    {
        if (bits[i] == '1')
        {
            number += pow(2,power);
        }

        power++;
    }
    
    return number;
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