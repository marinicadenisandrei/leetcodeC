/* Leetcode - 445. Add Two Numbers II (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

int* addTwoNumbers(int* l1Var, int l1SizeVar, int* l2Var, int l2SizeVar, int* resultSizeVar);
void printArray(int* arr, int arrSize);

int main()
{
    yellow();

    printf("Leetcode - 445. Add Two Numbers II (C language) - Medium\n");

    int l1[NUMBER_OF_TESTS][ARRAY_SIZE] = {{7,2,4,3},{2,4,3},{0}};
    int l1Size[NUMBER_OF_TESTS] = {4,3,1};
    int l2[NUMBER_OF_TESTS][ARRAY_SIZE] = {{5,6,4},{5,6,4},{0}};
    int l2Size[NUMBER_OF_TESTS] = {3,3,1};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();
        
        printf("Test %i: ", test + 1);

        reset();

        int resultSize = 0;
        int* result = addTwoNumbers(l1[test], l1Size[test], l2[test], l2Size[test], &resultSize);
        printArray(result, resultSize);
        free(result);

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

void printArray(int* arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), arr[i], ((i < arrSize - 1) ? ", " : "] | "));
    }
}

int* addTwoNumbers(int* l1Var, int l1SizeVar, int* l2Var, int l2SizeVar, int* resultSizeVar)
{
    int* result = (int*)malloc(ARRAY_SIZE * sizeof(int));  
    char l1Str[ARRAY_SIZE] = "";
    char l2Str[ARRAY_SIZE] = "";

    for (int i = 0; i < l1SizeVar; i++) l1Str[i] = l1Var[i] + '0';
    for (int i = 0; i < l2SizeVar; i++) l2Str[i] = l2Var[i] + '0';

    l1Str[l1SizeVar] = '\0';
    l2Str[l2SizeVar] = '\0';

    int l1Int = atoi(l1Str);
    int l2Int = atoi(l2Str);    
    int resultSum = l1Int + l2Int;

    char resultString[ARRAY_SIZE];
    sprintf(resultString, "%d", resultSum);

    for (int i = 0; i < (int)strlen(resultString); i++)
    {
        result[(*resultSizeVar)++] = resultString[i] - '0';
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