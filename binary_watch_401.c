/* Leetcode - 401. Binary Watch (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_TESTS 2
#define MAX_RESULTS 720    
#define TIME_STR_LEN 6    

void reset ();
void green ();
void yellow ();
void red ();

int count_ones(unsigned int x);
char** readBinaryWatch(int turnedOn, int *outCount);
void printArrayChars(char** arr, int arrSize);

int main(void) {
    yellow();

    printf("Leetcode - 401. Binary Watch (C language) - ");

    green();

    printf("Easy\n");

    int n[NUMBER_OF_TESTS] = {1,9};          

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int resultCount = 0;
        char **result = readBinaryWatch(n[test], &resultCount);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printArrayChars(result, resultCount);

        for (int i = 0; i < resultCount; i++) {
            free(result[i]);
        }
        free(result);

        green();

        printf("Passed\n");
    }
    
    reset();
    
    return 0;
}

void printArrayChars(char** arr, int arrSize)
{
    if (arrSize == 0) {
        printf("[] | ");
        return;
    }

    printf("[");

    for (int i = 0; i < arrSize; i++) {
        printf("%s", arr[i]);
        if (i < arrSize - 1) {
            printf(", ");
        }
    }

    printf("] | ");
}


int count_ones(unsigned int x) {
    int c = 0;
    while (x) {
        c += x & 1;
        x >>= 1;
    }
    return c;
}

char** readBinaryWatch(int turnedOn, int *outCount) {
    char **times = malloc(MAX_RESULTS * sizeof(char*));
    if (!times) {
        perror("malloc");
        exit(1);
    }

    for (int i = 0; i < MAX_RESULTS; i++) {
        times[i] = malloc(TIME_STR_LEN);
        if (!times[i]) {
            perror("malloc");
            exit(1);
        }
    }

    int idx = 0;
    for (int h = 0; h < 12; h++) {
        for (int m = 0; m < 60; m++) {
            if (count_ones(h) + count_ones(m) == turnedOn) {
                snprintf(times[idx], TIME_STR_LEN, "%d:%02d", h, m);
                idx++;
            }
        }
    }

    *outCount = idx;

    return times;
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