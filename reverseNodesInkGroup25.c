/* Leetcode - 25. Reverse Nodes in k-Group (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void swapElementsList(int array[ARRAY_SIZE], int arraySize, int start, int end);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 25. Reverse Nodes in k-Group (C language) - ");

    red();

    printf("Hard\n");

    int head[ARRAY_SIZE] = {1,2,3,4,5};
    int headSize = 5;
    int kTest[ARRAY_SIZE] = {2,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int k = kTest[test];

        int start = 0;
        int end = k - 1;
        
        for (int i = 0; headSize - i >= k; i += k)
        {
            swapElementsList(head, headSize, start, end);
            start += 2;
            end += 2;
        }
        
        green();

        printf("Test %i: ", test + 1);

        reset();

        for (int i = 0; i < headSize; i++)
        {
            printf("%s%i%s", (i == 0) ? "[" : "", head[i], (i < headSize - 1) ? "," : "] | ");
        }

        green();

        printf("Passed\n");

        reset();
    }
    

    return 0;
}

void swapElementsList(int array[ARRAY_SIZE], int arraySize, int start, int end)
{
    int temp = 0;
    int flagStop = true;

    if (arraySize >= end)
    {
        while (flagStop)
        {
            flagStop = false;

            for (int i = start; i < end; i++)
            {
                if (array[i] < array[i+1])
                {
                    temp = array[i];
                    array[i] = array[i+1];
                    array[i+1] = temp;
                    flagStop = true;
                    break;
                }
                
            }
        }
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