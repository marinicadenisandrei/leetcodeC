/* Leetcode - 354. Russian Doll Envelopes (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset();
void green();
void yellow();
void red();

int maxEnvelopes(int envelopesVar[ARRAY_SIZE][ARRAY_SIZE], int envelopesVarSize);
void sortArray(int *array, int arraySize);

int main()
{   
    yellow();

    printf("Leetcode - 354. Russian Doll Envelopes (C language) - ");

    red();

    printf("Hard\n");

    int envelopes[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE] = {{{5,4},{6,4},{6,7},{2,3}},{{1,1},{1,1},{1,1},{1,1}}};
    int envelopesSize[NUMBER_OF_TESTS] = {4,4};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", maxEnvelopes(envelopes[test], envelopesSize[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

void sortArray(int *array, int arraySize)
{
    bool flag = true;
    int c = 0;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < arraySize - 1 - c; i++)
        {
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;

                flag = true;
            }
        }
        
        c++;
    }
}

int maxEnvelopes(int envelopesVar[ARRAY_SIZE][ARRAY_SIZE], int envelopesVarSize)
{
    for (int i = 0; i < envelopesVarSize; i++)
    {
        sortArray(envelopesVar[i], 2);
    }

    int maxEnvelopes = 0;

    for (int i = 3; i < envelopesVarSize; i++)
    {
        int temp = 0;
        int first = envelopesVar[i][0];
        int second = envelopesVar[i][1];

        for (int j = 0; j < envelopesVarSize; j++)
        {
            if (i != j && second - first == 1 && envelopesVar[j][0] - second == 1 && envelopesVar[j][1] - envelopesVar[j][0] == 1)
            {
                temp++;
                first = envelopesVar[j][0];
                second = envelopesVar[j][1];
            }
        }

        maxEnvelopes = ((maxEnvelopes < temp) ? temp : maxEnvelopes);
    }

    return maxEnvelopes + 1;
}

void reset() {
printf("\033[1;0m");
}

void green() {
printf("\033[1;32m");
}

void yellow() {
printf("\033[1;33m");
}

void red() {
printf("\033[1;31m");
}