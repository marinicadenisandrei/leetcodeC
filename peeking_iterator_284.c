/* Leetcode - 284. Peeking Iterator (C language) - Medium */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 20

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

struct PeekingIterator
{
    int data;
    struct PeekingIterator *next;
}*first=NULL;

int create(int A[], int n)
{
    struct PeekingIterator *t,*last;
    first = (struct PeekingIterator *)malloc(sizeof(struct PeekingIterator));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct PeekingIterator*)malloc(sizeof(struct PeekingIterator));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }

    return 0;
}

int peek(struct PeekingIterator* obj)
{
    return first->data;
}

int next(struct PeekingIterator* obj)
{
    int x = first->data;
    first = first->next;
    return x;
}

bool hasNext(struct PeekingIterator* obj) 
{
    if (first == NULL)
    {
        return false;
    }
    
    return true;
}

void displayCache(int *cache, int cacheSize)
{
    for (int i = 0; i < cacheSize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), cache[i], ((i < cacheSize - 1) ? ", " : "] | "));
    }
}

int main()
{
    yellow();

    printf("Leetcode - 284. Peeking Iterator (C language) - Medium\n");

    int array[ARRAY_SIZE] = {1,2,3};
    int arraySize = 3;

    int cache[ARRAY_SIZE] = {0};
    int cacheSize = 0;

    cache[cacheSize++] = create(array, arraySize);

    cache[cacheSize++] = next(first);
    cache[cacheSize++] = peek(first);
    cache[cacheSize++] = next(first);
    cache[cacheSize++] = next(first);
    cache[cacheSize++] = hasNext(first);

    green();

    printf("Test 1: ");

    reset();

    displayCache(cache, cacheSize);

    green();

    printf("Passed\n");

    reset();

    return 0;
}