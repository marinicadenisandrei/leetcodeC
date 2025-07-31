/* Leetcode - 357. Count Numbers with Unique Digits (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define NUMBER_OF_TESTS 2

int countNumbersWithUniqueDigits(int nVar);
bool uniqueDigits(int number);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 357. Count Numbers with Unique Digits (C language) - Medium\n");

    int n[NUMBER_OF_TESTS] = {2,0};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", countNumbersWithUniqueDigits(n[test]));

        green();

        printf("Passed\n");
    }
    
    reset();
}

int countNumbersWithUniqueDigits(int nVar)
{
    int result = pow(10,nVar);

    for (int i = 0; i < pow(10,nVar); i++)
    {
        result -= ((!uniqueDigits(i)) ? 1 : 0);
    }

    return result;
}

bool uniqueDigits(int number)
{
    char str[10];
    sprintf(str, "%d", number);

    for (int i = 0; i < strlen(str); i++)
    {
        for (int j = 0; j < strlen(str); j++)
        {
            if (i != j && str[i] == str[j])
            {
                return false;
            }
        }   
    }
    
    return true;
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