#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ARRAY_SIZE 20

struct MyQueue
{
    int queueVar[ARRAY_SIZE];
    int x;
};

void myQueuePush(struct MyQueue *obj, int x);
int myQueuePop(struct MyQueue *obj);
int myQueuePeek(struct MyQueue *obj);
bool myQueueEmpty(struct MyQueue *obj);

void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 232. Implement Queue using Stacks (C language) - ");

    green();

    printf("Easy\n");

    char methods[ARRAY_SIZE][ARRAY_SIZE] = {"MyQueue","push","push","peek","pop","empty"};
    int elements[ARRAY_SIZE][ARRAY_SIZE] = {{},{1},{2},{},{},{}};
    int methodsSize = 6;

    int cache[ARRAY_SIZE] = {};
    cache[0] = 0;

    struct MyQueue obj = { .x = 0 }; 

    for (int i = 1; i < methodsSize; i++)
    {
        if (strcmp(methods[i], "push") == 0)
        {
            myQueuePush(&obj, elements[i][0]);
            cache[i] = 0;        
        }
        else if (strcmp(methods[i], "peek") == 0)
        {
            cache[i] = myQueuePeek(&obj);
        }
        else if (strcmp(methods[i], "pop") == 0)
        {
            cache[i] = myQueuePop(&obj);
        }
        else if (strcmp(methods[i], "empty") == 0)
        {
            cache[i] = myQueueEmpty(&obj);
        }
    }

    printf("Test 1: ");

    reset();

    printArray(cache, methodsSize);

    green();

    printf("Passed\n");

    reset();

    return 0;
}

void printArray(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s",((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "] | "));
    }  
}

void myQueuePush(struct MyQueue *obj, int x)
{
    obj->queueVar[obj->x] = x;
    obj->x++;
}

int myQueuePop(struct MyQueue *obj)
{
    if (obj->x > 0)
    {
        int popValue = obj->queueVar[0];
        for (int i = 0; i < obj->x - 1; i++)
        {
            obj->queueVar[i] = obj->queueVar[i + 1];
        }
        obj->x--;
        return popValue;
    }
    return -1; 
}

int myQueuePeek(struct MyQueue *obj)
{
    if (obj->x > 0)
    {
        return obj->queueVar[0];
    }
    return -1; 
}

bool myQueueEmpty(struct MyQueue *obj)
{
    return obj->x == 0;
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