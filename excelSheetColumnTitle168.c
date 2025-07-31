/* Leetcode - 168. Excel Sheet Column Title (C language) */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EXCEL_SIZE 26

void reset ();
void green ();
void yellow ();

int main(void)
{
    yellow();

    printf("Leetcode - 168. Excel Sheet Column Title (C language)\n");

    const int EXCEL_DEFAULT_COLUMNS_NAME[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int testsColumnNumber[] = {1,28,701};

    for (int test = 0; test < 3; test++)
    {
        int columnNumber = testsColumnNumber[test];
        int counter = 0;
        int counterFirst = -1;

        bool flag = true;

        green();

        printf("Test %i: ", test+1);

        reset();

        if (columnNumber <= 26)
        {
            printf("%c", EXCEL_DEFAULT_COLUMNS_NAME[columnNumber-1]);
        }
        else
        {
            while (flag)
            {   
                for (int i = 0; i < 26; i++)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        counter++;

                        if (counter == columnNumber-26)
                        {
                            if (counterFirst >= 0)
                            {
                                printf("%c", EXCEL_DEFAULT_COLUMNS_NAME[counterFirst]);
                            }

                            printf("%c%c", EXCEL_DEFAULT_COLUMNS_NAME[i],EXCEL_DEFAULT_COLUMNS_NAME[j]);
                            flag = false;
                            break;
                        }
                    }

                    if (flag == false)
                    {
                        break;
                    }
                }

                counterFirst++;
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

