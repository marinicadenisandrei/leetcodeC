/* Leetcode - 227. Basic Calculator II (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int calculate(char *sVar);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 227. Basic Calculator II (C language) - Medium\n");

    char s[NUMBER_OF_TESTS][ARRAY_SIZE] = {"3+2*2"," 3/2 "," 3+5 / 2 "};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {   
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", calculate(s[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int calculate(char *sVar)
{
    char temp[strlen(sVar)];
    int tempSize = 0;
    bool flag = true;

    for (int i = 0; i < strlen(sVar); i++)
    {
        if (sVar[i] != ' ')
        {
            temp[tempSize++] = sVar[i];
        }
    }

    temp[tempSize] = '\0';

    while (flag)
    {
        flag = false;

        for (int i = 0; i < strlen(temp); i++)
        {
            int number = 0;
            char newTemp[10];

            if (temp[i] == '/')
            {
                int num1 = (temp[i - 1] - '0'); 
                int num2 = (temp[i + 1] - '0');
                number = num1 / num2;

                strncpy(newTemp, temp, i - 1);
                newTemp[i - 1] = number + '0';
                newTemp[i] = '\0';

                strcpy(temp, newTemp);
                flag = true;
                break;
            }
            else if (temp[i] == '*')
            {
                int num1 = (temp[i - 1] - '0'); 
                int num2 = (temp[i + 1] - '0');
                number = num1 * num2;

                strncpy(newTemp, temp, i - 1);
                newTemp[i - 1] = number + '0';
                newTemp[i] = '\0';

                strcpy(temp, newTemp);
                flag = true;
                break;
            }
        }
    }

    flag = true;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < strlen(temp); i++)
        {
            int number = 0;
            char newTemp[10];

            if (temp[i] == '+')
            {
                int num1 = (temp[i - 1] - '0'); 
                int num2 = (temp[i + 1] - '0');
                number = num1 + num2;

                strncpy(newTemp, temp, i - 1);
                newTemp[i - 1] = number + '0';
                newTemp[i] = '\0';

                strcpy(temp, newTemp);
                flag = true;
            }
            else if (temp[i] == '-')
            {
                int num1 = (temp[i - 1] - '0'); 
                int num2 = (temp[i + 1] - '0');
                number = num1 - num2;

                strncpy(newTemp, temp, i - 1);
                newTemp[i - 1] = number + '0';
                newTemp[i] = '\0';

                strcpy(temp, newTemp);
                flag = true;
                break;
            }
        }
    }

    return temp[0] - '0';
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