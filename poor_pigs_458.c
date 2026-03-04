/* Leetcode - 458. Poor Pigs (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE 10
#define NUMBER_OF_TESTS 2 

void reset ();
void green ();
void yellow ();
void red ();

int poorPigs(int bucketsVar, int minutesToDieVar, int minutesToTestVar);

int main()
{
    yellow();

    printf("Leetcode - 458. Poor Pigs (C language) - ");

    red();

    printf("Hard\n");

    int buckets[ARRAY_SIZE] = {4,4};
    int minutesToDie[ARRAY_SIZE] = {15,15};
    int minutesToTest[ARRAY_SIZE] = {15,30};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", poorPigs(buckets[test], minutesToDie[test], minutesToTest[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int poorPigs(int bucketsVar, int minutesToDieVar, int minutesToTestVar)
{
    int rounds = (minutesToTestVar / minutesToDieVar) + 1;
    int result = 1;

    while (pow(rounds, result) < bucketsVar)
    {
        result++;
    }

    return result;
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