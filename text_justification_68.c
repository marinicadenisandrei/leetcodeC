/* Leetcode - 68. Text Justification (C example) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 68. Text Justification (C example) - ");

    red();

    printf("Hard\n");

    char words[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {
        {"This", "is", "an", "example", "of", "text", "justification."},
        {"What","must","be","acknowledgment","shall","be"},
        {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"}
    };

    int size_words_test[ARRAY_SIZE] = {7, 6, 18};
    int maxWidthTest[ARRAY_SIZE] = {16, 16, 20};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int size_words = size_words_test[test];
        int maxWidth = maxWidthTest[test];
        
        int sum = 0;
        int sumWords = 0;
        int factor = 0;

        int history = 0;

        green();

        printf("Test %i:\n", test + 1);

        reset();

        for (int i = 0; i < size_words; i++)
        {
            sum += strlen(words[test][i]) + 1;
            sumWords += strlen(words[test][i]);
            
            if (sum >= maxWidth + 1)
            {
                sumWords -= ((sumWords + i - history) > maxWidth) ? strlen(words[test][i]) : 0;

                while (sumWords < maxWidth)
                {
                    for (int k = history; k <= i - 1; k++)
                    {
                        if (sumWords + 1 <= maxWidth)
                        {
                            strcat(words[test][k], " ");
                            sumWords++;
                        }
                        else
                        {
                            sumWords = maxWidth;
                            break;
                        }
                    }
                }

                i -= (sum != maxWidth + 1) ? 1 : 0;
                
                for (int j = history; j <= i; j++) printf("%s%s%s", (j == history) ? "\"" : "", words[test][j], (j == i) ? "\"" : "");
                
                sum = 0;
                history = i + 1;
                sumWords = 0;

                printf("\n");
            }

            if (sum > 0 && i == size_words - 1)
            {
                for (int j = history; j <= i; j++) 
                {
                    printf("%s%s ", (j == history) ? "\"" : "", words[test][j]);
                    sumWords++;
                }

                while (sumWords < maxWidth)
                {
                    printf(" ");
                    sumWords++;
                }
                
                printf("\"");
            }         
        }

        printf(" | ");

        green();

        printf("Passed\n\n");
    }

    reset();
    
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