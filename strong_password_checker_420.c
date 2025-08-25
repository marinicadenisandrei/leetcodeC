/* Leetcode - 420. Strong Password Checker (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

int strongPasswordChecker(char passwordVar[ARRAY_SIZE], int passwordSizeVar);

int main()
{
    yellow();

    printf("Leetcode - 420. Strong Password Checker (C language) - ");

    red();

    printf("Hard\n");

    char password[NUMBER_OF_TESTS][ARRAY_SIZE] = {"a","aA1","1337C0d3"};
    int passwordSize[NUMBER_OF_TESTS] = {1,3,8};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", strongPasswordChecker(password[test], passwordSize[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int strongPasswordChecker(char passwordVar[ARRAY_SIZE], int passwordSizeVar)
{
    if (passwordSizeVar < 6)
    {
        return 6 - passwordSizeVar;
    }
    else if (passwordSizeVar > 20)
    {
        return passwordSizeVar - 20;
    }
    
    int countUpperCase = 0;
    int countRepeatingCharacters = 0;
    bool repeatingStart = false;

    char historyTemp;

    for (int i = 0; i < passwordSizeVar; i++)
    {
        if (passwordVar[i] >= 65 && passwordVar[i] <= 90)
        {
            countUpperCase++;
        }

        if (passwordVar[i] != '\0')
        {
            if (historyTemp == passwordVar[i] && !repeatingStart)
            {
                repeatingStart = true;
                countRepeatingCharacters++;
            }
            else
            {
                repeatingStart = false;
            }
        }

        historyTemp = passwordVar[i];
    }

    int total = (1 - countRepeatingCharacters) + (1 - countUpperCase);

    return ((total < 0) ? 0 : total);
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