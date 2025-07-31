/* Leetcode - 208. Implement Trie (Prefix Tree) (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20

int* Trie(char methodsVar[ARRAY_SIZE][ARRAY_SIZE], char elementsVar[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int sizeVar); 
void printArray(int *array, int arraySize);
int resultSize = 0;

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 208. Implement Trie (Prefix Tree) (C language) - Medium\n");

    char methods[ARRAY_SIZE][ARRAY_SIZE] = {"Trie", "insert", "search", "search", "startsWith", "insert", "search"};
    char elements[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {{}, {"apple"}, {"apple"}, {"app"}, {"app"}, {"app"}, {"app"}};
    int size = 7;

    green();

    printf("Test 1: ");

    reset();

    int *output;
    output = (int *)malloc(size * sizeof(int));
    output = Trie(methods, elements, size);
    printArray(output, resultSize);
    free(output);

    green();

    printf("Passed");

    reset();
}

void printArray(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%s%s", ((i == 0) ? "[" : ""), ((array[i] == 1) ? "true" : ((array[i] == 0) ? "false" : "null")), ((i < arraySize - 1) ? ", " : ""));
    }

    printf(" | ");
}

int* Trie(char methodsVar[ARRAY_SIZE][ARRAY_SIZE], char elementsVar[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int sizeVar)
{
    int *result;
    result = (int *)malloc(sizeVar * sizeof(int));
    result[resultSize++] = -1;

    char acumulation[ARRAY_SIZE][ARRAY_SIZE] = {""};
    int acumulationSize = 0;

    for (int i = 1; i < sizeVar; i++)
    {
        if (strcmp(methodsVar[i], "insert") == 0)
        {
            result[resultSize++] = -1;
            strcpy(acumulation[acumulationSize++], elementsVar[i][0]);
        }
        else if (strcmp(methodsVar[i], "search") == 0)
        {
            bool flag = false;

            for (int j = 0; j < acumulationSize; j++)
            {
                if (strcmp(acumulation[j], elementsVar[i][0]) == 0)
                {
                    flag = true;
                    break;
                }
            }

            result[resultSize++] = ((flag) ? 1 : 0);
        }
        else if (strcmp(methodsVar[i], "startsWith") == 0)
        {
            bool flag = false;
            int len = strlen(elementsVar[i][0]);

            for (int j = 0; j < acumulationSize; j++)
            {
                if (strncmp(acumulation[j], elementsVar[i][0], len) == 0)
                {
                    flag = true;
                    break;
                }
            }

            result[resultSize++] = ((flag) ? 1 : 0);
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