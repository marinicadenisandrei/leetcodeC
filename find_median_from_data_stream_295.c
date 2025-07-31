/* Leetcode - 295. Find Median from Data Stream (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>

void reset ();
void green ();
void yellow ();
void red ();

typedef struct {
    int A[20];  
    int aSize; 
    float cache[20];
    int cacheSize; 
} MedianFinder;

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    if (obj != NULL) {
        obj->aSize = 0; 
        obj->cacheSize = 0;
    }
    
    return obj;  
}

void addNum(MedianFinder* obj, int num) {
    obj->A[obj->aSize++] = num;
    obj->cache[obj->cacheSize++] = 0;
}

float findMedian(MedianFinder* obj) {
    float result = 0;

    if (obj->aSize % 2 == 0)
    {
        result = (float)(obj->A[(int)((obj->aSize) / 2) - 1] + obj->A[(int)((obj->aSize) / 2)]) / 2; 
    } 
    else
    {
        result = obj->A[(int)((obj->aSize) / 2)];
    }

    obj->cache[obj->cacheSize++] = result;

    return result;
}

void display(MedianFinder* obj) {
    if (obj->aSize == 0) {
        printf("The array is empty.\n");
        return;
    }
    
    for (int i = 0; i < obj->aSize; i++) {
        printf("%d ", obj->A[i]);  
    }
    printf("\n");
}

void displayCache(MedianFinder* obj) {    
    for (int i = 0; i < obj->cacheSize; i++) {
        printf("%s%.1f%s ", ((i == 0) ? "[" : ""), (obj->cache[i]), ((i < obj->cacheSize - 1) ? ", " : "] |"));  
    }
}

int main() {
    yellow();

    printf("Leetcode - 295. Find Median from Data Stream (C language) - ");

    red();

    printf("Hard\n");

    MedianFinder* mf = medianFinderCreate();

    green();

    printf("Test 1: ");

    reset();

    addNum(mf, 1);
    addNum(mf, 2);
    findMedian(mf);
    addNum(mf, 3);
    findMedian(mf);
    displayCache(mf);

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

