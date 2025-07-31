/* Leetcode - 264. Ugly Number II (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int nthUglyNumber(int nVar);
bool dividedByTwoElements(int number);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 264. Ugly Number II (C language) - Medium\n");

    int n[NUMBER_OF_TESTS] = {1,10};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", nthUglyNumber(n[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

bool dividedByTwoElements(int number)
{
    if (number == 2 || number == 3 || number == 5)
    {
        return true;
    }
    
    int candidates[3] = {2,3,5};
    int flags[3] = {0};
    int counter = 0;

    for (int i = 0; i < 3; i++)
    {
        if (number % candidates[i] == 0)
        {
            flags[i] = 1;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (flags[i] == 1)
        {
            counter++;
        }
    }    

    if (counter > 0)
    {
        return true;
    }
    
    return false;
}

int nthUglyNumber(int nVar)
{
    int numbers[ARRAY_SIZE] = {1};
    int numbersSize = 1;

    int startNumberCheck = 2;

    while (numbersSize < nVar)
    {   
        if (dividedByTwoElements(startNumberCheck))
        {
            numbers[numbersSize++] = startNumberCheck;        
        }

        startNumberCheck++;
    }
    
    return numbers[nVar - 1];
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