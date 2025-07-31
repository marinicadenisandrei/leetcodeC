/* Leetcode - 65. Valid Number (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void printArray(int array[ARRAY_SIZE], int size_array);
int checkForDigits(char charVar[ARRAY_SIZE]);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 65. Valid Number (C language) - ");

    red();

    printf("Hard\n");

    char s[ARRAY_SIZE][ARRAY_SIZE] = {"0", "e", "."};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        bool flag = false;

        if (checkForDigits(s[test]) == 1)
        {
            flag = true;
        }

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s", ((flag == true) ? "true | " : "false | "));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int checkForDigits(char charVar[20])
{
    int counter_dot = 0;
    bool e_present = false;

    if (charVar[0] == '.' && strlen(charVar) == 1)
    {
        return 0;
    }
    
    for (int i = 0; i < strlen(charVar); i++)
    {
        if (charVar[i] == '.')
        {
            counter_dot++;
            continue;
        }

        if (charVar[i] == 'e' || charVar[i] == 'E')
        {
            e_present = true;
        }
        
        if (!isdigit(charVar[i]))
        {
            if (charVar[i] != '-')
            {
                if (charVar[i] != '+')
                {
                    if ((charVar[i] != 'e' && !isdigit(charVar[i-1]) && i < 0) || (charVar[i] != 'E' && !isdigit(charVar[i-1]) && i < 0))
                    {
                        return 0;
                    }
                }
            }
        }

        if (counter_dot > 1)
        {
            return 0;
        }

        if (counter_dot == 1 && e_present == true)
        {
            return 0;
        }
    }

    return 1;
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