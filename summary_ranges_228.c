#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int resultSize = 0;

char** summaryRanges(int *numsVar, int numsSize);
void printArray(char **array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 228. Summary Ranges (C language) - ");

    green();

    printf("Easy\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{0,1,2,4,5,7},{0,2,3,4,6,8,9}};
    int numsSize[NUMBER_OF_TESTS] = {6,7};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        char **output = summaryRanges(nums[test], numsSize[test]);
        printArray(output, resultSize);

        for (int i = 0; i < ARRAY_SIZE; i++) {
            free(output[i]);
        }
        free(output);

        resultSize = 0;

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

void printArray(char **array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%s%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "] | "));
    }
}

char** summaryRanges(int *numsVar, int numsSize)
{
    int start = numsVar[0];

    char **result = (char **)malloc(ARRAY_SIZE * sizeof(char *));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        result[i] = (char *)malloc(ARRAY_SIZE * sizeof(char));
    }  

    for (int i = 0; i < numsSize - 1; i++)
    {
        if (numsVar[i + 1] - numsVar[i] > 1)
        {
            char temp[10];
            temp[0] = start + '0';
            temp[1] = '-';
            temp[2] = '>';
            temp[3] = numsVar[i] + '0';
            temp[4] = '\0';

            strcpy(result[resultSize++], temp);
            
            start = numsVar[i + 1];
        }
        
        if (i == numsSize - 2)
        {
            char temp[10];
            temp[0] = start + '0';
            temp[1] = '-';
            temp[2] = '>';
            temp[3] = numsVar[i + 1] + '0';
            temp[4] = '\0';

            strcpy(result[resultSize++], temp);
        }
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