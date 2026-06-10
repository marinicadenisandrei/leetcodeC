/* Leetcode - 474. Ones and Zeroes (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

char **findMaxForm(
    char strsVar[ARRAY_SIZE][ARRAY_SIZE],
    int strsSizeVar,
    int mVar,
    int nVar,
    int *resultSize
);

void printArrOfStrings(char **arr, int arrSize);

int main()
{
    yellow();

    printf("Leetcode - 474. Ones and Zeroes (C language) - Medium\n");
    
    char strs[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE] = {{"10","0001","111001","1","0"},{"10","0","1"}};
    int strsSize[NUMBER_OF_TESTS] = {5,3};

    int m[NUMBER_OF_TESTS] = {5,1};
    int n[NUMBER_OF_TESTS] = {3,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int resultSize = 0;
        char **result = findMaxForm(strs[test], strsSize[test], m[test], n[test], &resultSize);

        printArrOfStrings(result, resultSize);
        
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            free(result[i]);
        }

        free(result);

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

char **findMaxForm(
    char strsVar[ARRAY_SIZE][ARRAY_SIZE],
    int strsSizeVar,
    int mVar,
    int nVar,
    int *resultSize
)
{
    char **result = malloc(ARRAY_SIZE * sizeof(char *));
    if (result == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        result[i] = malloc(ARRAY_SIZE * sizeof(char));
        if (result[i] == NULL)
        {
            return NULL;
        }

        result[i][0] = '\0';
    }

    *resultSize = 0;

    for (int l = 0; l < strsSizeVar; l++)
    {
        char resultTemp[ARRAY_SIZE][ARRAY_SIZE] = {""};
        int resultSizeTemp = 0;

        int zeros = 0;
        int ones = 0;

        for (int i = l; i < strsSizeVar; i++)
        {
            int z_temp = 0;
            int o_temp = 0;

            for (int j = 0; j < strlen(strsVar[i]); j++)
            {
                if (strsVar[i][j] == '0')
                {
                    z_temp++;
                }
                else
                {
                    o_temp++;
                }
            }

            if (zeros + z_temp <= mVar && ones + o_temp <= nVar)
            {
                zeros += z_temp;
                ones += o_temp;

                strcpy(resultTemp[resultSizeTemp], strsVar[i]);
                resultSizeTemp++;
            }
        }

        if (resultSizeTemp > *resultSize)
        {
            for (int i = 0; i < resultSizeTemp; i++)
            {
                strcpy(result[i], resultTemp[i]);
            }

            *resultSize = resultSizeTemp;
        }
    }

    return result;
}

void printArrOfStrings(char **arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%s%s%s", ((i == 0) ? "[" : ""), arr[i], ((i < arrSize - 1) ? ", " : "] | "));   
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