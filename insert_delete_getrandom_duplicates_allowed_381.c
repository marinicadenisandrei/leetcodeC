/* Leetcode - 381. Insert Delete GetRandom O(1) - Duplicates allowed (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void reset ();
void green ();
void yellow ();
void red ();

struct RandomizedCollection {
    int size;      
    int capacity;   
    int *collection;
};

void create(struct RandomizedCollection *c, int capacity) {
    c->size = 0;
    c->capacity = capacity;
    c->collection = (int *)malloc(capacity * sizeof(int));
}


bool insert(struct RandomizedCollection *c, int x) {
    bool flag = false;

    for (int i = 0; i < c->size; i++) {
        if (c->collection[i] == x) {
            flag = true;
            break;
        }
    }

    if (c->size >= c->capacity) {
        printf("Collection is full. Cannot insert more elements.\n");
        return false;
    }

    c->collection[c->size++] = x;

    if (flag)
    {
        return false;
    }

    return true;
}

int getRandom(struct RandomizedCollection *c) {
    if (c->size == 0) {
        printf("Collection is empty.\n");
        return -1;
    }
    int index = rand() % c->size;
    return c->collection[index];
}

bool removeCol(struct RandomizedCollection *c, int x)
{
    for (int i = 0; i < c->size; i++)
    {
        if (c->collection[i] == x)
        {
            for (int j = i; j < c->size - 1; j++)
            {
                c->collection[j] = c->collection[j + 1];
            }
            
            c->size--;

            return true;
        }
    }
    
    return false;
}

int main() {
    yellow();
    
    printf("Leetcode - 381. Insert Delete GetRandom O(1) - Duplicates allowed (C language) - ");

    red();

    printf("Hard\n");

    srand(time(NULL));

    struct RandomizedCollection randomizedCollection;
    create(&randomizedCollection, 10); 

    green();

    printf("Test 1: ");

    reset();

    printf("%s ", insert(&randomizedCollection, 1) ? "true" : "false");
    printf("%s ", insert(&randomizedCollection, 1) ? "true" : "false");
    printf("%s ", insert(&randomizedCollection, 2) ? "true" : "false");
    printf("%d ", getRandom(&randomizedCollection));
    printf("%s ", removeCol(&randomizedCollection, 1) ? "true" : "false");
    printf("%d ", getRandom(&randomizedCollection));

    free(randomizedCollection.collection);

    printf("| ");

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
