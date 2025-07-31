/* Leetcode - 146. LRU Cache (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 20
int cacheSize = 1;

int* LRUcache(char methodsVar[ARRAY_SIZE][ARRAY_SIZE], int numbersList[ARRAY_SIZE][ARRAY_SIZE], int lenVar);
int numberInArray(int *array, int arraySize, int number);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 146. LRU Cache (C language) - Medium\n");

    char methods[ARRAY_SIZE][ARRAY_SIZE] = {"LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"};
    int numbersList[ARRAY_SIZE][ARRAY_SIZE] = {{2},{1,1},{2,2},{1},{3,3},{2},{4,4},{1},{3},{4}};
    int len = 10;

    int *output = (int*) malloc(ARRAY_SIZE * sizeof(int));
    output = LRUcache(methods, numbersList, len);

    green();

    printf("Test 1: ");

    reset();

    printArray(output, cacheSize);

    green();

    printf("Passed");

    reset();

    return 0;
}

void printArray(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "]"));
    }
    
    printf(" | ");
}

int numberInArray(int *array, int arraySize, int number)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] == number)
        {
            return number;
        }
    }

    return -1;
}

int* LRUcache(char methodsVar[ARRAY_SIZE][ARRAY_SIZE], int numbersList[ARRAY_SIZE][ARRAY_SIZE], int lenVar)
{
    int lru_cache[ARRAY_SIZE];
    int lru_cache_size = 0;
    int wherePut = 0;

    int *cache = (int*) malloc(ARRAY_SIZE * sizeof(int));
    cache[0] = 0;

    for (int i = 1; i < lenVar; i++)
    {
        if (strcmp(methodsVar[i], "put") == 0)
        {
            lru_cache[wherePut] = numbersList[i][0];
            wherePut++;
            lru_cache_size++;
            cache[cacheSize] = 0;
            cacheSize++;
        }
        else if (strcmp(methodsVar[i], "get") == 0)
        {
            int temp = numberInArray(lru_cache, lru_cache_size, numbersList[i][0]);

            if (temp != -1)
            {
                cache[cacheSize] = temp;
                cacheSize++;
            }
            else
            {
                cache[cacheSize] = -1;
                cacheSize++;
                wherePut = 0;
            }            
        }

        if (wherePut == numbersList[0][0])
        {
            wherePut--;
        }
    }

    return cache;
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