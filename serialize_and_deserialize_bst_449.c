/* Leetcode - 449. Serialize and Deserialize BST (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

char* serialize(int* rootVar, int rootSizeVar);
int* deserialize(char* rootVar, int* outputSize);
void printArray(int* arr, int arrSize);

int main()
{
    yellow();

    printf("Leetcode - 449. Serialize and Deserialize BST (C language) - Medium\n");

    int root[NUMBER_OF_TESTS][ARRAY_SIZE] = {{2,1,3},{}};
    int rootSize[NUMBER_OF_TESTS] = {3,0};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        char* result = serialize(root[test], rootSize[test]);
    
        int outputSize = 0;
        int* output = deserialize(result, &outputSize);  

        printArray(output, outputSize);
        
        free(output);  
        free(result);

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

void printArray(int* arr, int arrSize)
{
    if (arrSize == 0)
    {
        printf("[] | ");
        return;
    }
    
    for (int i = 0; i < arrSize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), arr[i], ((i < arrSize - 1) ? ", " : "] | "));
    }
}

int* deserialize(char* rootVar, int* outputSize)
{
    int* result = malloc(ARRAY_SIZE * sizeof(int));
    if (!result) return NULL;

    if (outputSize == 0)
    {
        return result;
    }
    
    *outputSize = 0; 

    for (int i = 1; i < strlen(rootVar); i += 2)
    {
        result[*outputSize] = rootVar[i] - '0';
        (*outputSize)++;  
    }
    
    return result;
}

char* serialize(int *rootVar, int rootSizeVar)
{
    char *result = malloc(ARRAY_SIZE);
    int resultSize = 0;

    if (rootSizeVar == 0)
    {
        result[0] = '\0';
        return result;
    }

    result[resultSize++] = '[';

    for (int i = 0; i < rootSizeVar; i++)
    {
        result[resultSize++] = '0' + rootVar[i];
        
        if (i < rootSizeVar - 1)
        {
            result[resultSize++] = ',';
        }
    }

    result[resultSize++] = ']';
    result[resultSize] = '\0';

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