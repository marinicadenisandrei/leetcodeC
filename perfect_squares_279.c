/* Leetcode - 279. Perfect Squares (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int numSquares(int nVar);
bool isSquare(int number);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - Leetcode - 279. Perfect Squares (C language) - Medium\n");

    int n[NUMBER_OF_TESTS] = {12,13};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", numSquares(n[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

bool isSquare(int number) 
{
    int sqrtValue = (int)sqrt(number);
    return (sqrtValue * sqrtValue == number);
}

int numSquares(int nVar)
{
    int counter = 0;

    for (int i = 4; i < nVar; i++)
    {
        for (int j = 1; j < nVar; j++)
        {
            if (isSquare(i) && i * j == nVar)
            {
                return j;
            }
            
        }
        
    }

    for (int i = nVar; i >= 0 ; i--)
    {
        if (isSquare(i))
        {
            nVar -= i;
            counter++;
        }

        if (nVar == 0)
        {
            return counter;
        }
        
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