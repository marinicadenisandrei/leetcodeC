/* Leetcode - 211. Design Add and Search Words Data Structure (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20

int* WordDictionary(char methodsVar[ARRAY_SIZE][ARRAY_SIZE], char elementsVar[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int sizeVar);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int resultSize = 0;

int main(void)
{
    yellow();
    
    printf("Leetcode - 211. Design Add and Search Words Data Structure (C language) - Medium\n");

    char methods[ARRAY_SIZE][ARRAY_SIZE] = {"WordDictionary","addWord","addWord","addWord","search","search","search","search"};
    char elements[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {{},{"bad"},{"dad"},{"mad"},{"pad"},{"bad"},{".ad"},{"b.."}};
    int size = 8;

    int *output;
    output = (int*) malloc(ARRAY_SIZE * sizeof(int));
    output = WordDictionary(methods, elements, size);

    green();

    printf("Test 1: ");
    
    reset();

    printArray(output, resultSize);

    green();

    printf("Passed\n");

    reset();

    free(output);
    resultSize = 0;

    return 0;
}

void printArray(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%s%s", ((i == 0) ? "[" : ""), ((array[i] == -1 ) ? "null" : ((array[i] == 0) ? "false" : "true")), ((i < arraySize - 1) ? ", " : "] | "));
    }
}

int* WordDictionary(char methodsVar[ARRAY_SIZE][ARRAY_SIZE], char elementsVar[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int sizeVar)
{
    char acumulation[ARRAY_SIZE][ARRAY_SIZE] = {""};
    int acumulationSize = 0;

    int *result;
    result = (int*)malloc(ARRAY_SIZE * sizeof(int));
    result[resultSize++] = -1;

    for (int i = 1; i < sizeVar; i++)
    {
        if (strcmp(methodsVar[i], "addWord") == 0)
        {
            strcpy(acumulation[acumulationSize++], elementsVar[i][0]);
            // printf("null ");
            result[resultSize++] = -1;
        }
        else if (strcmp(methodsVar[i], "search") == 0)
        {
            bool flag = true;

            for (int j = 0; j < acumulationSize; j++)
            { 
                flag = true;

                for (int k = 0; k < strlen(elementsVar[i][0]); k++)
                {
                    if (elementsVar[i][0][k] == '.')
                    {
                        continue;
                    }
                    else if (elementsVar[i][0][k] != acumulation[j][k])
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                {
                    break;
                }
            }

            if (flag)
            {
                // printf("true ");
                result[resultSize++] = 1;
            }
            else
            {
                // printf("false ");
                result[resultSize++] = 0;
            }
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
