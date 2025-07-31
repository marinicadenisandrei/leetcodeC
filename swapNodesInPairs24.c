#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void swapNodes(int *array, int sizeArray);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{   
    yellow();

    printf("Leetcode - 24. Swap Nodes in Pairs (C language) - Medium\n");

    int head[ARRAY_SIZE][ARRAY_SIZE] = {{1,2,3,4}, {1}, {}};
    int sizeHead[ARRAY_SIZE] = {4, 1, 0};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        swapNodes(head[test], sizeHead[test]);
        
        reset();

        for (int i = 0; i < sizeHead[test]; i++)
        {
            printf("%s%i%s ", (i == 0) ? "[" : "" ,head[test][i], (i < sizeHead[test] - 1) ? "," : "] |");
        }

        printf("%s", (sizeHead[test] == 0) ? "[] | " : "");

        green();

        printf("Passed\n");

        reset();
    }
    
    return 0;
}

void swapNodes(int *array, int sizeArray)
{
    int temp = 0;
    int *ptr = array;

    for (int i = 0; i < sizeArray - 1; i += 2)
    {
        temp = *(ptr + i);
        *(ptr + i) = *(ptr + i + 1);
        *(ptr + i + 1) = temp;
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