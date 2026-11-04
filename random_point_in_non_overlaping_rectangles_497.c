/* Leetcode - 497. Random Point in Non-overlapping Rectangles (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int** rects;
    int rectsSize;
    int* points;
} Solution;


// Constructor
Solution* solutionCreate(int** rects, int rectsSize, int* rectsColSize) {
    Solution* obj = malloc(sizeof(Solution));

    obj->rects = rects;
    obj->rectsSize = rectsSize;
    obj->points = malloc(rectsSize * sizeof(int));

    int total = 0;

    for (int i = 0; i < rectsSize; i++)
    {
        int x1 = obj->rects[i][0];
        int y1 = obj->rects[i][1];
        int x2 = obj->rects[i][2];
        int y2 = obj->rects[i][3];

        int points = (x2 - x1 + 1) * (y2 - y1 + 1);
        total += points;
        obj->points[i] = total;
    }
    
    return obj;
}


int* solutionPick(Solution* obj, int* retSize) {
    int total = obj->points[obj->rectsSize - 1];
    int random = rand() % total + 1;
    int selected = 0;

    for (int i = 0; i < obj->rectsSize; i++) {
        if (random <= obj->points[i]) {
            selected = i;
            break;
        }
    }

    int x1 = obj->rects[selected][0];
    int y1 = obj->rects[selected][1];
    int x2 = obj->rects[selected][2];
    int y2 = obj->rects[selected][3];

    int x = x1 + rand() % (x2 - x1 + 1);
    int y = y1 + rand() % (y2 - y1 + 1);

    *retSize = 2;

    int* result = malloc(2 * sizeof(int));

    result[0] = x;
    result[1] = y;

    return result;
}

void solutionFree(Solution* obj) {
    if (obj == NULL) return;

    free(obj->points);
    free(obj);
}

void reset ();
void green ();
void yellow ();
void red ();

int main(void) {
    yellow();

    printf("Leetcode - 497. Random Point in Non-overlapping Rectangles\n");

    srand((unsigned int)time(NULL));

    int rect1[] = {-2, -2, 1, 1};
    int rect2[] = {2, 2, 4, 6};

    int* rects[] = {rect1, rect2};

    int rectsSize = 2;
    int rectsColSize[] = {4, 4};

    Solution* obj = solutionCreate(rects, rectsSize, rectsColSize);

    green();

    printf("Test 1: ");

    reset();

    for (int i = 0; i < 5; i++) {
        int retSize = 0;

        int* point = solutionPick(obj, &retSize);

        printf("[%d, %d] ",point[0], point[1]);

        free(point);
    }

    printf("| ");

    green();

    printf("Passed\n");

    reset();

    solutionFree(obj);

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