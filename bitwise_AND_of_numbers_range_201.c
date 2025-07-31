/* Leetcode - 201. Bitwise AND of Numbers Range (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define CHAR_SIZE 100
#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int rangeBitwiseAnd(int leftVar, int rightVar);
char* intToBinary(int value);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 201. Bitwise AND of Numbers Range (C language) - Medium\n");

    int left[ARRAY_SIZE] = {5,0,1};
    int right[ARRAY_SIZE] = {7,0,2147483647};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int result = rangeBitwiseAnd(left[test], right[test]);

        printf("%i | ", result);

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

char* intToBinary(int value)
{
    char *binaryValue = (char*) malloc(CHAR_SIZE);
    int binLen = 0;

    while (value > 0)
    {
        binaryValue[binLen++] = ((value % 2 == 0) ? '0' : '1');
        value = (int) (value / 2);
    }

    binaryValue[binLen] = '\0';

    return binaryValue;
}

int rangeBitwiseAnd(int leftVar, int rightVar)
{
    if (leftVar == 0 || rightVar == 0)
    {
        return 0;
    }
    
    char acumulation[ARRAY_SIZE][ARRAY_SIZE];
    int acumulationSize = 0;
    bool flag = true;

    for (int i = leftVar; i <= rightVar; i++)
    {
        char *binChar = intToBinary(i);
        strcpy(acumulation[acumulationSize++], binChar);
        // printf("%i, %s\n", i, binChar);
        binChar = NULL;

        for (int i = 0; i < strlen(acumulation[0]); i++)
        {
            for (int j = 0; j < acumulationSize; j++)
            {
                if (acumulation[i][j] == '0')
                {
                    flag = false;
                    break;
                }
            }

            if (!flag)
            {
                break;
            }
        }

        if (!flag)
        {
            break;
        }
    }
    
    int result = 0;
    int bit = 0;

    for (int i = strlen(acumulation[0]) - 1; i >= 0; i--)
    {
        bit = 1;

        for (int j = 0; j < acumulationSize; j++)
        {
            if (acumulation[i][j] == '0')
            {
                bit = 0;
                break;
            }
        }

        result += bit * pow(2, i);
    }
    
    return result;
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