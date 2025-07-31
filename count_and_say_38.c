/* Leetcode - 38. Count and Say (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 38. Count and Say (C language) - Medium\n");

    int nTest[NUMBER_OF_TESTS] = {1, 4};

    char start[ARRAY_SIZE] = "1";
    char temp[ARRAY_SIZE] = "";

    int counterStart = 0;
    int counter = 0;

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int n = nTest[test];

        for (int j = 0; j < n - 1; j++)
        {
            for (int i = 0; i < 8; i++)
            {
                if (start[counterStart] == start[i])
                {
                    counter++;
                }
                else
                {
                    char str[2] = "";
                    sprintf(str, "%d", counter);
                    strcat(temp, str);
                    
                    strcpy(str, "");

                    str[0] = start[counterStart];
                    strcat(temp, str);

                    counter = 0;
                    counterStart = i;
                    i--;
                }
            }
            
            strcpy(start, temp);
            strcpy(temp, "");

            counter = 0;
            counterStart = 0;
        }
        
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("\"%s\" | ", start);

        green();

        printf("Passed\n");

        reset();
    }

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