/* Leetcode - 382. Linked List Random Node (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void reset ();
void green ();
void yellow ();
void red ();

struct Solution
{
    int size;
    int *s;
};

void create(struct Solution *s, int *array, int arraySize)
{
    s->size = arraySize;
    s->s=(int *)malloc(s->size * sizeof(int));

    for (int i = 0; i < arraySize; i++)
    {
        s->s[i] = array[i];
    }
}

int getRandom(struct Solution *s)
{
    int randomNumber = rand() % s->size;

    return s->s[randomNumber];
}

int main()
{
    yellow();

    printf("Leetcode - 382. Linked List Random Node (C language) - Medium\n");

    srand(time(0));

    struct Solution solution;

    int input[3] = {1,2,3};
    int inputSize = 3;

    green();

    printf("Test 1: ");

    reset();

    create(&solution, input, inputSize);
    printf("%i ", getRandom(&solution));
    printf("%i ", getRandom(&solution));
    printf("%i ", getRandom(&solution));
    printf("%i ", getRandom(&solution));
    printf("%i ", getRandom(&solution));

    green();

    printf("| ");

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