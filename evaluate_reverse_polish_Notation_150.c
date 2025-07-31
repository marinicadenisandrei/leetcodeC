/* Leetcode - 150. Evaluate Reverse Polish Notation (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int evalRPN(char tokensVar[ARRAY_SIZE][ARRAY_SIZE], int tokensVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{   
    yellow();

    printf("Leetcode - 150. Evaluate Reverse Polish Notation (C language) - Medium\n");

    char tokens[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {{"2","1","+","3","*"},{"4","13","5","/","+"},{"10","6","9","3","+","-11","*","/","*","17","+","5","+"}};
    int tokensSize[ARRAY_SIZE] = {5,5,13};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | " ,evalRPN(tokens[test], tokensSize[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int evalRPN(char tokensVar[ARRAY_SIZE][ARRAY_SIZE], int tokensVarSize)
{
    while (tokensVarSize > 1)
    {
        for (int i = 0; i < tokensVarSize; i++)
        {
            if ((tokensVar[i][0] >= '0' && tokensVar[i][0] <= '9') || (tokensVar[i][0] == '-' && strlen(tokensVar[i]) > 1 && tokensVar[i][1] >= '0' && tokensVar[i][1] <= '9')) 
            {
                continue; 
            }
            else
            {
                int result = 0;

                int num1 = atoi(tokensVar[i - 2]);
                int num2 = atoi(tokensVar[i - 1]);

                if (tokensVar[i][0] == '+')
                {
                    result = num1 + num2;
                }
                else if (tokensVar[i][0] == '-')
                {
                    result = num1 - num2;
                }
                else if (tokensVar[i][0] == '/')
                {
                    result = num1 / num2;
                }
                else
                {
                    result = num1 * num2;
                }

                char numStr[ARRAY_SIZE];
                sprintf(numStr, "%d", result);
                strcpy(tokensVar[i - 2], numStr);

                for (int j = i + 1; j < tokensVarSize; j++)
                {
                    strcpy(tokensVar[j - 2], tokensVar[j]);
                }

                tokensVarSize -= 2;

                if (tokensVarSize == 1)
                {
                    return atoi(tokensVar[0]);
                }

                break;
            } 
        }
    }
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