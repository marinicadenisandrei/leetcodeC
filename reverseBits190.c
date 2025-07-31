/* Leetcode - 190. Reverse Bits (C language) */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stddef.h>

#define NUMBER_OF_TESTS 2

long long unsigned convertBinaryToDecimal(char string[]);
void reset ();
void green ();
void yellow ();

int main(void)
{
    yellow();

    printf("Leetcode - 190. Reverse Bits (C language)\n");

    char n[5][100] = {"00000010100101000001111010011100","11111111111111111111111111111101"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test+1);

        reset();

        printf("%llu ",convertBinaryToDecimal(n[test]));

        green();

        printf("| Passed\n");

        reset();
    }
    
    return 0;
}

long long unsigned convertBinaryToDecimal(char string[])
{
    int lenString = strlen(string);
    char *pString = string;
    long long unsigned decimalNumber = 0;
    int power = 0;

    for (int i = 0; i < lenString+1; i++, pString++)
    {
        decimalNumber += (*pString == '1') ? pow(2,power) : 0;
        power += 1;
    }

    return decimalNumber;   
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
