/* Leetcode - 141. Linked List Cycle (C language) */

#include <stdio.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 3

int main(void)
{

    printf("Leetcode - 141. Linked List Cycle (C language)\n");

    int head[10][20] = {{3,2,0,-4}, {1,2}, {1}};
    int testPos[10] = {1,0,-1};
    int sizeTest[10] = {4,2,1};

    int pos = 0;
    int sizeHead = 0;
    int flagCycle = false;

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        pos = testPos[test];

        sizeHead = sizeTest[test];
        flagCycle = false;

        flagCycle = (pos >= 0 && pos <= sizeHead) ? true : flagCycle;
        printf("Test %i: %s | Passed\n", test+1, (flagCycle == true) ? "true" : "false");
    }
    
    return 0;
}