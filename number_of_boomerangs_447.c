/* Leetcode - 447. Number of Boomerangs (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

typedef struct {
    int dist;   
    int count;  
} Pair;

void reset ();
void green ();
void yellow ();
void red ();

int numberOfBoomerangs(int pointsVar[ARRAY_SIZE][2], int pointsSizeVar);
int findIndex(Pair *arr, int size, int dist);

int main()
{
    yellow();

    printf("Leetcode - 447. Number of Boomerangs (C language) - Medium\n");

    int points[NUMBER_OF_TESTS][ARRAY_SIZE][2] = {{{0,0},{1,0},{2,0}},{{1,1},{2,2},{3,3}},{{1,1}}};
    int pointsSize[NUMBER_OF_TESTS] = {3,3,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", numberOfBoomerangs(points[test], pointsSize[test]));

        green();

        printf("Passed\n");
    }

    green();
    
    return 0;
}

int findIndex(Pair *arr, int size, int dist) {
    for (int i = 0; i < size; i++) {
        if (arr[i].dist == dist)
            return i;
    }
    return -1;
}

int numberOfBoomerangs(int pointsVar[ARRAY_SIZE][2], int pointsSizeVar)
{
    int result = 0;

    for (int i = 0; i < pointsSizeVar; i++) {

        Pair distCount[2000];  
        int distSize = 0;

        for (int j = 0; j < pointsSizeVar; j++) {
            if (i == j) continue;

            int dx = pointsVar[i][0] - pointsVar[j][0];
            int dy = pointsVar[i][1] - pointsVar[j][1];

            int dist2 = dx * dx + dy * dy;

            int idx = findIndex(distCount, distSize, dist2);

            if (idx == -1) 
            {
                distCount[distSize].dist = dist2;
                distCount[distSize].count = 1;
                distSize++;
            } 
            else 
            {
                distCount[idx].count++;
            }
        }

        for (int k = 0; k < distSize; k++) {
            int m = distCount[k].count;
            if (m >= 2) {
                result += m * (m - 1);
            }
        }
    }

    return result;
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