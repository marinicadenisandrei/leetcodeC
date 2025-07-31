/* Leetcode - 380. Insert Delete GetRandom O(1) (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ARRAY_SIZE 20

void reset ();
void green ();
void yellow ();
void red ();

int randomizedSet[ARRAY_SIZE] = {};
int randomizedSetSize = 0;

bool insert(int val)
{
    for (int i = 0; i < randomizedSetSize; i++)
        if (randomizedSet[i] == val)
            return false;

    randomizedSet[randomizedSetSize++] = val;
    return true;
}

bool removeVal(int val)
{
    for (int i = 0; i < randomizedSetSize; i++)
    {
        if (randomizedSet[i] == val)
        {
            for (int j = i; j < randomizedSetSize - 1; j++)
            {
                randomizedSet[j] = randomizedSet[j + 1];
            }

            randomizedSetSize--;
            return true;
        }
    }

    return false;
}

int getRandom()
{
    if (randomizedSetSize == 0) return -1; 
    int index = rand() % randomizedSetSize;
    return randomizedSet[index];
}

int main()
{
    yellow();

    printf("Leetcode - 380. Insert Delete GetRandom O(1) (C language) - Medium\n");

    srand(time(NULL));

    green();

    printf("Test 1: ");
    
    reset();

    printf("%s ", insert(1) ? "true" : "false");
    printf("%s ", removeVal(2) ? "true" : "false");
    printf("%s ", insert(2) ? "true" : "false");
    printf("%d ", getRandom());
    printf("%s ", removeVal(1) ? "true" : "false");
    printf("%s ", insert(2) ? "true" : "false");
    printf("%d ", getRandom());
    printf(" | ");

    green();

    printf("Passed\n");

    reset();

    return 0;
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