/* Leetcode - 457. Circular Array Loop (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

bool circularArrayLoop(int* numsVar, int numsSizeVar);

int main()
{
    yellow();

    printf("Leetcode - 457. Circular Array Loop (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{2,-1,1,2,2},{-1,-2,-3,-4,-5,6},{1,-1,5,1,4}};
    int numsSize[NUMBER_OF_TESTS] = {5,6,5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", ((circularArrayLoop(nums[test], numsSize[test]) == 1) ? "true" : "false"));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

bool circularArrayLoop(int* numsVar, int numsSizeVar)
{
    int next = 0;
    bool visited[1000];
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < numsSizeVar; i++)
    {
        if (visited[next]) return true;

        visited[next] = true;

        int newNext = (next + numsVar[next]) % numsSizeVar;
        if (newNext < 0) newNext += numsSizeVar;

        if (newNext == next) return false;  

        next = newNext;
    }
    return false;
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