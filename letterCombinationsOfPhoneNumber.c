/* Leetcode - 17. Letter Combinations of a Phone Number (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_TESTS 3

struct numberToLetters
{
    int number;
    char letters[10];
};

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 17. Letter Combinations of a Phone Number (C language) - Medium\n");
    
    struct numberToLetters database[50] = {{0, ""}, {1,""}, {2, "abc"},{3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqn"}, {8, "tuv"}, {9, "wxyz"}};
    int sizeDatabase = 8;

    char digits[10][10] = {"23", "", "2"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        if (strlen(digits[test]) == 1)
        {
            for (int i = 0; i < strlen(database[digits[test][0] - '0'].letters); i++)
            {
                printf("%c ", database[digits[test][0] - '0'].letters[i]);
            }
            
        }
        
        char output[100][100][100] = {};
        char final[100][100] = {};

        int firstIndexOutput = 0;

        for (int i = 0; i < strlen(database[digits[test][0] - '0'].letters); i++)
        {
            for (int j = 0; j < strlen(database[digits[test][1] - '0'].letters); j++)
            {
                output[0][firstIndexOutput][0] = database[digits[test][0] - '0'].letters[i];
                output[0][firstIndexOutput][1] = database[digits[test][1] - '0'].letters[j];

                firstIndexOutput++;
            }
        }

        int counter = 0;
        int bigCounter = 1;

        for (int i = 2; i < strlen(digits[test]); i++)
        {
            for (int j = 0; j < strlen(database[digits[test][i] - '0'].letters); j++)
            {
                for (int k = 0; k < firstIndexOutput; k++)
                {
                    for (int l = 0; l < strlen(output[bigCounter-1][k]); l++)
                    {
                        output[bigCounter][counter][l] = output[bigCounter-1][k][l];
                    }

                    output[bigCounter][counter][strlen(output[bigCounter][counter])] = database[digits[test][i] - '0'].letters[j];
                    counter++;
                }
                
            }
            if (strlen(digits[test]) - i > 1)
            {
                counter = 0;
                bigCounter++; 
            }       
        }

        if (strlen(digits[test]) == 2)
        {
            counter = firstIndexOutput;
            bigCounter = 0;
        }

        for (int i = 0; i < counter; i++)
        {
            printf("%s ", output[bigCounter][i]);
        }

        printf("| ");

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