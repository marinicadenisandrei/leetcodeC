/* Leetcode - 224. Basic Calculator (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define ARRAY_SIZE 25
#define NUMBER_OF_TESTS 3

int calculate(char sVar[ARRAY_SIZE]);
void remove_spaces(char* str);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 224. Basic Calculator (C language) - ");

    red();

    printf("Hard\n");

    char s[NUMBER_OF_TESTS][ARRAY_SIZE] = {"1 + 1"," 2-1 + 2 ","(1+(4+5+2)-3)+(6+8)"};

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

void remove_spaces(char* str) 
{
    int i, j;
    for (i = 0, j = 0; str[i]; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

int calculate(char sVar[ARRAY_SIZE])
{
    bool flag = true;
    int first = 0;
    int last = 0;

    remove_spaces(sVar);

    while (flag)
    {
        flag = false;

        for (int i = 0; i < strlen(sVar); i++)
        {
            if (sVar[i] == ')')
            {
                for (int j = i - 2; j >= 0; j--)
                {   
                    if (sVar[j] == '(')
                    {
                        char number[ARRAY_SIZE] = "";
                        int numberSize = 0;
                        int calculation = 0;
                        int starter = 0;

                        for (int k = j + 1; k < i; k++)
                        {
                            if (isdigit(sVar[k]))
                            {
                                number[numberSize++] = sVar[k];
                            }
                            else
                            {
                                number[numberSize] = '\0';
                                calculation += atoi(number);
                                number[0] = '\0';
                                numberSize = 0;
                                starter = k;
                                break;
                            }
                        }

                        for (int k = starter; k <= i; k++)
                        {
                            if (sVar[k] == ' ')
                            {
                                continue;
                            }
                            
                            if (sVar[k] == '+')
                            {
                                for (int l = k + 1; l <= i; l++)
                                {
                                    if (isdigit(sVar[l]))
                                    {
                                        number[numberSize++] = sVar[l];
                                    }
                                    else
                                    {
                                        number[numberSize] = '\0';
                                        calculation += atoi(number);
                                        number[0] = '\0';
                                        numberSize = 0;
                                        break;
                                    } 
                                }
                            }
                            else if (sVar[k] == '-')
                            {
                                for (int l = k + 1; l <= i; l++)
                                {
                                    if (isdigit(sVar[l]))
                                    {
                                        number[numberSize++] = sVar[l];
                                    }
                                    else
                                    {
                                        number[numberSize] = '\0';
                                        calculation -= atoi(number);
                                        number[0] = '\0';
                                        numberSize = 0;
                                        break;
                                    } 
                                }
                            }
                        }
                        
                        char temp[ARRAY_SIZE] = "";
                        char str[ARRAY_SIZE];

                        strncpy(temp, sVar, j);
                        sprintf(str, "%d", calculation);
                        strcat(temp, str);

                        str[0] = '\0';
                        int str_len = 0;
                        
                        for (int k = i + 1; k < strlen(sVar); k++)
                        {
                            str[str_len++] = sVar[k];
                        }

                        str[str_len++] = '\0';

                        strcat(temp, str);
                        strcpy(sVar, temp);
                        flag = true;
                        break;
                    }
                }
            }
        }
    }    

    char number[ARRAY_SIZE] = "";
    int numberSize = 0;
    int calculation = 0;
    int starter = 0;

    for (int i = 0; i < strlen(sVar); i++)
    {
        if (isdigit(sVar[i]))
        {
            number[numberSize++] = sVar[i];
        }
        else
        {
            number[numberSize] = '\0';
            calculation += atoi(number);
            number[0] = '\0';
            numberSize = 0;
            starter = i;
            break;
        }
    }

    for (int k = starter; k <= strlen(sVar); k++)
    {
        if (sVar[k] == '+')
        {
            for (int l = k + 1; l <= strlen(sVar); l++)
            {
                if (isdigit(sVar[l]))
                {
                    number[numberSize++] = sVar[l];
                }
                else
                {
                    number[numberSize] = '\0';
                    calculation += atoi(number);
                    number[0] = '\0';
                    numberSize = 0;
                    break;
                } 
            }
        }
        else if (sVar[k] == '-')
        {
            for (int l = k + 1; l <= strlen(sVar); l++)
            {
                if (isdigit(sVar[l]))
                {
                    number[numberSize++] = sVar[l];
                }
                else
                {
                    number[numberSize] = '\0';
                    calculation -= atoi(number);
                    number[0] = '\0';
                    numberSize = 0;
                    break;
                } 
            }
        }
    }

    return calculation;
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