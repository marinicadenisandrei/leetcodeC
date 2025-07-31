/* Leetcode - 7. Reverse Integer (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 3

int returnMultiplication(int number);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 7. Reverse Integer (C language) - Medium\n");

    int testList[10] = {123,-123,120};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int x = testList[test];

        int negativeFlag = false;

        negativeFlag = (x < 0) ? true : false;
        x *= (x < 0) ? -1 : 1;
        
        int multiplicationNumberDepth = returnMultiplication(x);
        int multiplicationNumber = multiplicationNumberDepth;

        int reverseNumber = 0;

        for (int i = 1; i <= multiplicationNumberDepth; i = i * 10, multiplicationNumber /= 10)
        {
            reverseNumber += ((x/i) % 10) * multiplicationNumber;
        }
        
        reverseNumber *= (negativeFlag == true) ? -1 : 1;

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", reverseNumber);

        green();

        printf("Passed\n");

        reset();
    }

    return 0;
}

int returnMultiplication(int number)
{
    int tenZecimalNumber = 1;

    while (number > 1)
    {
        number = number / 10;
        tenZecimalNumber *= 10;
    }

    return tenZecimalNumber;
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