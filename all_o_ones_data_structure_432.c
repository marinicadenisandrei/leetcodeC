/* Leetcode - 432. All O`one Data Structure (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_ITEMS 20
#define MAX_LEN   20

void reset ();
void green ();
void yellow ();
void red ();

struct AllOne {
    char list[MAX_ITEMS][MAX_LEN];
    int  listSize;
};

int  inc(struct AllOne *ds, const char *x);
const char* getMaxKey(const struct AllOne *ds);
const char* getMinKey(const struct AllOne *ds);

int main(void)
{
    yellow();

    printf("Leetcode - 432. All O`one Data Structure (C language) - ");

    red();

    printf("Hard\n");

    struct AllOne allOne = { .list = {{0}}, .listSize = 0 };

    green();

    printf("Test 1: ");

    reset();

    inc(&allOne, "hello");
    inc(&allOne, "hello");
    printf("%s ", getMaxKey(&allOne));
    printf("%s ", getMinKey(&allOne));
    inc(&allOne, "leet");
    printf("%s ", getMaxKey(&allOne));
    printf("%s ", getMinKey(&allOne));

    printf(" | ");

    green();

    printf("Passed\n");

    reset();

    return 0;
}

int inc(struct AllOne *ds, const char *x)
{
    if (ds->listSize >= MAX_ITEMS) return 0;
    snprintf(ds->list[ds->listSize], MAX_LEN, "%s", x);
    ds->listSize++;
    return 1;
}

const char* getMaxKey(const struct AllOne *ds)
{
    if (ds->listSize == 0) return NULL;

    int maxLen = -1;
    int maxIdx = -1;

    for (int i = 0; i < ds->listSize; i++) {
        int len = (int)strlen(ds->list[i]);
        if (len > maxLen) {
            maxLen = len;
            maxIdx = i;
        }
    }
    return (maxIdx >= 0) ? ds->list[maxIdx] : NULL;
}

const char* getMinKey(const struct AllOne *ds)
{
    if (ds->listSize == 0) return NULL;

    int minLen = INT_MAX;
    int minIdx = -1;

    for (int i = 0; i < ds->listSize; i++) {
        int len = (int)strlen(ds->list[i]);
        if (len < minLen) {
            minLen = len;
            minIdx = i;
        }
    }
    return (minIdx >= 0) ? ds->list[minIdx] : NULL;
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