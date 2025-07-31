/* Leetcode - 385. Mini Parser (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUMBER_OF_TESTS 2
#define ARRAY_SIZE 20

void reset ();
void green ();
void yellow ();
void red ();

int resultSize = 0;

int* deserialize(char *sVar);
void printArray(int *arr, int arrSize);

int main()
{
    yellow();

    printf("Leetcode - 385. Mini Parser (C language) - Medium\n");

    char s[NUMBER_OF_TESTS][ARRAY_SIZE] = {"324","[123,[456,[789]]]"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int* output = deserialize(s[test]);
        printArray(output, resultSize);

        free(output);
        resultSize = 0;

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

void printArray(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), arr[i], ((i < arrSize - 1) ? ", " : "] | "));
    }
}

int* deserialize(char *sVar)
{
    int* result = (int*)malloc(ARRAY_SIZE * sizeof(int));

    char temp[ARRAY_SIZE] = "";
    int tempSize = 0;

    for (int i = 0; i < strlen(sVar); i++)
    {
        if (sVar[i] >= '0' && sVar[i] <= '9') {
            temp[tempSize++] = sVar[i];
        }
        else
        {
            if (tempSize > 0)
            {
                temp[tempSize] = '\0';
                
                int num = atoi(temp);
                result[resultSize++] = num;
                
                tempSize = 0;
            }
        }
    }

    if (resultSize == 0)
    {
        result[resultSize++] = atoi(sVar);
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