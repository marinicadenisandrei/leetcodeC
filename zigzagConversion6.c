/* Leetcode - 6. Zigzag Conversion (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 6. Zigzag Conversion (C language) - Medium\n");

    char s[100] = "PAYPALISHIRING";
    int size_s = 14;

    int numRowsTest[10] = {3,4};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {   
        green();

        printf("Test %i: ", test + 1);    

        reset();

        int numRows = numRowsTest[test];

        int iterationNumber = numRows + (numRows - 2);

        bool flag = true;

        int depth = iterationNumber;
        int counter = 0;

        char output[50][50] = {};
        int sizeOutput = 0;
        int sizeInOutput_1 = 0;
        int sizeInOutput_2 = 0;


        for (int i = 0; i < 14; i += iterationNumber)
        {
            output[sizeOutput+1][sizeInOutput_2] = ' ';
            sizeInOutput_2 = 1;

            for (int j = i; j < depth; j++, counter++)
            {   
                if (counter < numRows)
                {
                    output[sizeOutput][sizeInOutput_1] = s[j];
                    sizeInOutput_1++;
                }
                else
                {
                    output[sizeOutput+1][sizeInOutput_2] = s[j];
                    sizeInOutput_2++;
                }
            }

            output[sizeOutput+1][sizeInOutput_2] = ' ';

            sizeOutput += 2;

            sizeInOutput_1 = 0;
            sizeInOutput_2 = 0;

            depth += iterationNumber;
            counter = 0;        
        }
        
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < sizeOutput; j += 2)
            {
                if (output[j][i] != ' ')
                {
                    printf("%c",output[j][i]);
                }

                if (output[j+1][numRows - 1 - i] != ' ')
                {
                    printf("%c", output[j+1][numRows - 1 - i]);
                }
                
            }   
        }

        green();

        printf(" | Passed\n");

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