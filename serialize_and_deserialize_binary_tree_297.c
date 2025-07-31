/* Leetcode - 297. Serialize and Deserialize Binary Tree (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

char* serialize(int *rootVar, int rootSizeVar);
int* deserialize(char *serVar);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 297. Serialize and Deserialize Binary Tree (C language) - ");

    red();

    printf("Hard\n");

    int root[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2,3,0,0,4,5},{}};
    int rootSize[NUMBER_OF_TESTS] = {7,0};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printArray(deserialize(serialize(root[test], rootSize[test])), rootSize[test]);

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

char* serialize(int *rootVar, int rootSizeVar)
{
    char *serVar = (char *)malloc(ARRAY_SIZE);
    int serVarSize = 0;

    if (rootSizeVar == 0)
    {
        serVar[serVarSize++] = '\0';
        return serVar;
    }

    for (int i = 0; i < rootSizeVar; i++)
    {
        serVar[serVarSize++] = rootVar[i] + '0';
        serVar[serVarSize++] = ',';
    }
    
    serVar[serVarSize++] = '\0';
    return serVar;
}

int* deserialize(char *serVar)
{
    int *output = (int*)malloc(sizeof(int) * ARRAY_SIZE);
    int outputSize = 0;

    if (strlen(serVar) == 0)
    {
        return output;
    }

    for (int i = 0; i < strlen(serVar); i += 2)
    {
        output[outputSize++] = serVar[i] - '0';
    }

    return output;
}

void printArray(int *array, int arraySize)
{
    if (arraySize == 0)
    {
        printf("[] | ");
        return;
    }

    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], (i < arraySize - 1) ? ", " : "] | ");
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