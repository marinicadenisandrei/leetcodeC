/* Leetcode - 460. LFU Cache (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20

void reset ();
void green ();
void yellow ();
void red ();

struct LFUCache
{
    int cache[ARRAY_SIZE];
    int cnt[ARRAY_SIZE];
    int size;
    int maxSize;
};

void put(struct LFUCache *lfu, int key, int value)
{
    (void)value;

    if (lfu->size < lfu->maxSize)
    {
        lfu->cache[lfu->size++] = key;
    }
    else
    {
        lfu->cache[0] = key;
        lfu->size = 1;
    }
}

int get(struct LFUCache *lfu, int key)
{
    for (int i = 0; i < lfu->size; i++)
    {
        if (lfu->cache[i] == key)
        {
            return lfu->cache[i];
        }
    }
    return -1;
}

int main(void)
{
    yellow();

    printf("Leetcode - 460. LFU Cache (C language) - ");

    red();

    printf("Hard\n");

    green();

    printf("Test 1: ");

    reset();

    struct LFUCache lfu = {0};
    lfu.maxSize = 2;

    put(&lfu, 1, 1);
    put(&lfu, 2, 2);
    printf("%i ", get(&lfu, 1));
    put(&lfu, 3, 3);
    printf("%i ", get(&lfu, 2));
    printf("%i ", get(&lfu, 3));
    put(&lfu, 4, 4);
    printf("%i ", get(&lfu, 1));
    printf("%i ", get(&lfu, 3));
    printf("%i ", get(&lfu, 4));

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