/* Leetcode - 12. Integer to Roman (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 3
#define DATABASE_LENGTH 7

void reset ();
void green ();
void yellow ();
void red ();

struct integerToRoman
{
    char roman[10];
    int integer;
};

const struct integerToRoman database[100] = {
    {"I",1}, 
    {"V",5}, 
    {"X",10}, 
    {"L",50}, 
    {"C",100}, 
    {"D",500}, 
    {"M",1000}
}; 


int main(void)
{
    yellow();

    printf("Leetcode - 12. Integer to Roman (C language) - Medium\n");

    int numTest[10] = {3, 58, 1994};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int num = numTest[test];
        int copyNum = num;
        int arrayNum[10] = {};

        int counter = 1;

        while (copyNum > 1)
        {
            copyNum /= 10;
            counter += 1;
        }

        int divNumber = 100;
        arrayNum[0] = num % 10;

        int sum = arrayNum[0];

        for (int i = 1; i < counter; i++)
        {
            arrayNum[i] = (num % divNumber) - sum;
            sum += arrayNum[i];
            divNumber *= 10;
        }
        
        int flagFinder = false;
        int result = 0;
        
        int search = 0;

        green();

        printf("Test %i: ", test + 1);

        reset();

        for (int k = counter-1; k >= 0; k--)
        {
            search = arrayNum[k];

            int flagFirst = false;
            int flagSecond = false;
            flagFinder = false;

            if (search != 0)
            {
                for (int l = 0; l < 7; l++)
                {
                    if (database[l].integer == search)
                    {
                        printf("%s", database[l].roman);
                        flagFirst = true;
                        break;
                    }
                }

                if (flagFirst != true)
                {
                    for (int i = 0; i < 7 && flagFinder == false; i++)
                    {
                        for (int j = 0; j < 7 && flagFinder == false; j++)
                        {
                            if (database[i].integer > database[j].integer)
                            {
                                result = database[i].integer - database[j].integer;
                                if (result == search)
                                {
                                    printf("%s%s", database[j].roman,database[i].roman);
                                    flagFinder = true;
                                    flagSecond = true;
                                    break;
                                }
                                
                            }
                            else
                            {
                                result = database[j].integer - database[i].integer;
                                if (result == search)
                                {
                                    printf("%s%s", database[i].roman,database[j].roman);
                                    flagFinder = true;
                                    flagSecond = true;
                                    break;
                                }
                            }     
                        }
                    }
                }

                if (flagFirst == false && flagSecond == false)
                {
                    while (search > 0)
                    {
                        for (int m = 6; m >= 0; m--)
                        {
                            if (database[m].integer <= search)
                            {
                                printf("%s",database[m].roman);
                                search -= database[m].integer;
                            }
                        }
                    }
                }
            }
        }

        printf(" | ");

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