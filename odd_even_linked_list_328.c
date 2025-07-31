/* Leetcode - 328. Odd Even Linked List (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

struct Node
{
    int data;
    struct Node *next;
}*first;

void create(int A[], int n);
void display(struct Node *p);
void oddEvenList(struct Node *head);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 328. Odd Even Linked List (C language) - Medium\n");

    int head[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2,3,4,5},{2,1,3,5,6,4,7}};
    int headSize[NUMBER_OF_TESTS] = {5,7};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        create(head[test], headSize[test]);
        oddEvenList(first);
        display(first);

        free(first);

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

void oddEvenList(struct Node *head)
{
    struct Node * first = head;

    int array1[10] = {};
    int array1Size = 0;

    int array2[10] = {};
    int array2Size = 0;
    
    int toggle = 1;

    while (head != NULL)
    {
        if (toggle)
        {
            array1[array1Size++] = head->data;
        }
        else
        {
            array2[array2Size++] = head->data;
        }
        head = head->next;
        toggle = !toggle;
    }

    head = first;

    for (int i = 0; i < array1Size; i++)
    {
        head->data = array1[i];
        head = head->next;
    }
    
    for (int i = 0; i < array2Size; i++)
    {
        head->data = array2[i];
        head = head->next;
    }

    head = first;
}

int length(struct Node *p)
{
    int l = 0;

    while (p != NULL)
    {
        l++;
        p=p->next;   
    }

    return l;
}

void create(int A[], int n)
{
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    printf("[");

    while (p != NULL)
    {
        printf("%d%s", p->data, ((p->next != NULL) ? ", " : ""));
        p=p->next;   
    }

    printf("] | ");
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