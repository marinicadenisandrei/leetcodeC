/* Leetcode - 282. Expression Add Operators (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int resultSize = 0;

char** addOperators(char *numVar, int targetVar);
int evalFunction(char expression[ARRAY_SIZE]);
void printArray(char **array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 282. Expression Add Operators (C language) - ");

    red();

    printf("Hard\n");

    char num[NUMBER_OF_TESTS][ARRAY_SIZE] = {"123","232","3456237490"};
    int target[NUMBER_OF_TESTS] = {6,8,9191};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        char **output = addOperators(num[test], target[test]);
        printArray(output, resultSize);

        green();

        printf("Passed\n");

        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            free(output[i]);
        }

        free(output);
        resultSize = 0;
    }

    reset();
    
    return 0;
}

void printArray(char **array, int arraySize)
{
    if (arraySize == 0)
    {
        printf("[] | ");
    }

    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%s%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "] | "));
    }
}

int evalFunction(char *expression)
{
    bool flag = true;

    while (flag)
    {
        flag = false;

        for (int i = 1; i < strlen(expression) - 1; i += 2)
        {
            if (expression[i] == '*')
            {
                char part1[10] = "";
                strncpy(part1, expression, i - 1);

                int result = (expression[i - 1] - '0') * (expression[i + 1] - '0');
                part1[i - 1] = result + '0';

                int part1Size = i;

                for (int j = i + 2; j < strlen(expression); j++)
                {
                    part1[part1Size++] = expression[j];
                }

                strcpy(expression, part1);
                flag = true;
                break;
            }
        }
    }

    int result = (int) (expression[0] - '0');
    
    for (int i = 1; i < strlen(expression) - 1; i += 2)
    {
        if (expression[i] == '+')
        {
            result += (int) (expression[i + 1] - '0');
        }
        else if (expression[i] == '-')
        {
            result -= (int) (expression[i + 1] - '0');
        }
    }

    return result;
}


char** addOperators(char *numVar, int targetVar)
{
    char **results = (char **)malloc(ARRAY_SIZE * sizeof(char *));
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        results[i] = (char *)malloc(ARRAY_SIZE * sizeof(char));
    }

    char candidates[3][1] = {'+','*','-'};

    for (int j = 0; j < 3; j++)
    {
        char temp[ARRAY_SIZE] = "";
        int tempSize = 0;

        int result = ((candidates[j][0] == '*') ? 1 : 0);

        for (int i = 0; i < strlen(numVar); i++)
        {
            if (candidates[j][0] == '*')
            {
                result *= (int) (numVar[i] - '0');
                temp[tempSize++] = numVar[i];
                temp[tempSize++] = '*';
            }
            else if (candidates[j][0] == '+') 
            {
                result += (int) (numVar[i] - '0');
                temp[tempSize++] = numVar[i];
                temp[tempSize++] = '+';
            }
            else if (candidates[j][0] == '-') 
            {
                result -= (int) (numVar[i] - '0');
                temp[tempSize++] = numVar[i];
                temp[tempSize++] = '-';
            }
        }

        temp[tempSize - 1] = '\0';

        if (result == targetVar)
        {
            strcpy(results[resultSize++], temp);
        }
    }
    
    char temp[ARRAY_SIZE] = "";
    int tempSize = 0;
    int index = 0;

    for (int i = 0; i < strlen(numVar); i++)
    {
        temp[tempSize++] = numVar[i];
        temp[tempSize++] = candidates[index++][0];
        
        index = ((index == 3) ? 0 : index);
    }

    temp[tempSize - 1] = '\0';
    char copy[ARRAY_SIZE] = "";
    strcpy(copy, temp);

    if (evalFunction(temp) == targetVar)
    {
        strcpy(results[resultSize++], copy);
    }

    strcpy(temp, copy);
    
    int index1 = 1;
    int index2 = 3;
    
    while (index2 < strlen(temp) - 1)
    {
        char c[1];
        c[0] = temp[index1];
        temp[index1] = temp[index2];
        temp[index2] = c[0];

        char copy[ARRAY_SIZE] = "";
        strcpy(copy, temp);


        if (evalFunction(temp) == targetVar)
        {
            strcpy(results[resultSize++], copy);
        }

    
        index1++;
        index2++;
    }

    return results;
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