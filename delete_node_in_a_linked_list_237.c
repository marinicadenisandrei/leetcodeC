/* Leetcode - 237. Delete Node in a Linked List (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void deleteNode(int *headVar, int *headVarSize, int nodeVar);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void) 
{
    yellow();

    printf("Leetcode - 237. Delete Node in a Linked List (C language) - Medium\n");

    int head[NUMBER_OF_TESTS][ARRAY_SIZE] = {{4,5,1,9},{4,5,1,9}};
    int headSize[NUMBER_OF_TESTS] = {4,4};
    int node[NUMBER_OF_TESTS] = {5,1};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {   
        green();

        printf("Test %i: ", test + 1);

        reset();

        deleteNode(head[test], &headSize[test], node[test]);
        printArray(head[test], headSize[test]);

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

void printArray(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "] | "));
    }
}

void deleteNode(int *headVar, int *headVarSize, int nodeVar)
{
    for (int i = 0; i < *headVarSize; i++)
    {
        if (headVar[i] == nodeVar)
        {
            for (int j = i; j < *headVarSize - 1; j++)
            {
                headVar[j] = headVar[j + 1];
            }
            
            break;
        }
    }
    
    (*headVarSize)--;
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
