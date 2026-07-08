/* Leetcode - 478. Generate Random Point in a Circle (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 1
#define PI 3.14159265358979323846

void reset ();
void green ();
void yellow ();
void red ();

typedef struct {
    float radius;
    float x_center;
    float y_center;
} Solution;

float (*randPoint(Solution s))[2];
void printCoordinates(float (*numbers)[2]);

int main()
{
    yellow();

    printf("Leetcode - 478. Generate Random Point in a Circle (C language) - Medium\n");

    srand(time(NULL));

    Solution solution = {1.0, 0.0, 0.0};

    float (*numbers)[2] = randPoint(solution);

    if (numbers == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    green();

    printf("Test 1: ");

    reset();

    printCoordinates(numbers);
    free(numbers);

    green();

    printf("Passed\n");

    reset();

    return 0;
}

float (*randPoint(Solution s))[2] {
    float (*arr)[2] = malloc(sizeof(float[1][2]));

    if (arr == NULL) {
        return NULL;
    }

    float angle = ((float) rand() / RAND_MAX) * 2.0f * PI;
    float distance = sqrtf((float) rand() / RAND_MAX) * s.radius;

    arr[0][0] = s.x_center + distance * cosf(angle);
    arr[0][1] = s.y_center + distance * sinf(angle);

    return arr;
}

void printCoordinates(float (*numbers)[2])
{
    printf("[%f, %f] | ", numbers[0][0], numbers[0][1]);
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