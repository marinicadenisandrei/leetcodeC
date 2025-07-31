#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_TESTS 2
#define ARRAY_SIZE 20

int * rotateListFunction(int array[ARRAY_SIZE], int arraySize, int element);
void printArray(int * array, int sizeArray);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 61. Rotate List (C language) - Medium\n");

    int head[ARRAY_SIZE][ARRAY_SIZE] = {{1,2,3,4,5}, {0,1,2}};
    int head_sizes[ARRAY_SIZE] = {5, 3};

    int k[ARRAY_SIZE] = {2, 4};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int * output = rotateListFunction(head[test], head_sizes[test], k[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printArray(output, head_sizes[test]);

        green();

        printf("Passed\n");

        reset();
    }

    return 0;
}

int * rotateListFunction(int array[ARRAY_SIZE], int arraySize, int element)
{
    int *parray = (int *)malloc(arraySize * sizeof(int)); 

    if (parray == NULL)
    {
        return NULL;
    }

    int index = 0;

    for (int i = 0; i < element; i++)
    {
        int temp = array[arraySize - 1];
        
        for (int j = arraySize - 1; j >= 0; j--)
        {
            array[j + 1] = array[j];
        }
    
        array[0] = temp;
    }

    for (int i = 0; i < arraySize; i++)
    {
        parray[i] = array[i];
    }
    
    return parray;
}

void printArray(int * array, int sizeArray)
{
    for (int i = 0; i < sizeArray; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < sizeArray - 1) ? ", " : "] | "));
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