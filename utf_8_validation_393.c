/* Leetcode - 393. UTF-8 Validation (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

bool validUtf8(int *data, int dataSize);

int main()
{
    yellow();

    printf("Leetcode - 393. UTF-8 Validation (C language) - Medium\n");

    int data[NUMBER_OF_TESTS][ARRAY_SIZE] = {{197,130,1},{235,140,4}};
    int dataSize[NUMBER_OF_TESTS] = {3,3};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", ((validUtf8(data[test], dataSize[test])) ? "true" : "false"));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

#include <stdbool.h>

int count_leading_ones(int byte) {
    int count = 0;
    for (int mask = 1 << 7; mask > 0; mask >>= 1) {
        if ((byte & mask) != 0) {
            count++;
        } else {
            break;
        }
    }
    return count;
}

bool validUtf8(int* data, int dataSize) {
    int i = 0;

    while (i < dataSize) {
        int first_byte = data[i];
        int n_bytes = count_leading_ones(first_byte);

        if (n_bytes == 0) {
            i++;
            continue;
        }

        if (n_bytes == 1 || n_bytes > 4) {
            return false;
        }

        if (i + n_bytes > dataSize) {
            return false;
        }

        for (int j = 1; j < n_bytes; j++) {
            if ((data[i + j] & 0xC0) != 0x80) {
                return false;
            }
        }

        i += n_bytes;
    }

    return true;
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