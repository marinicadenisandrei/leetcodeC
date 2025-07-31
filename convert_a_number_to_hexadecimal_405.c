/* Leetcode - 405. Convert a Number to Hexadecimal (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

char *toHex(int numVar);

int main(void) 
{
    yellow();

    printf("Leetcode - 405. Convert a Number to Hexadecimal (C language) - ");

    green();

    printf("Easy\n");

    int num[NUMBER_OF_TESTS] = {26,-1};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        char *hexStr = toHex(num[test]);
    
        if (!hexStr) {
            fprintf(stderr, "Eroare la alocare\n");
            return 1;
        }

        printf("%s | ", hexStr);
        
        free(hexStr);

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

char *toHex(int numVar)
{
    char *buf = malloc(9); 
    if (!buf) return NULL;
    sprintf(buf, "%08X", numVar);
    return buf;
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