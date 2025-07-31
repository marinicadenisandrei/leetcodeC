/* Leetcode - 160. Intersection of Two Linked Lists (C language) */

#include <stdio.h>
#include <stdbool.h>

bool checkForIntersectVal(const int *array, int sizeArray, int checkIntervalVal, int skipValue);

void reset ();
void green ();
void yellow ();

int main(void)
{
    yellow();

    printf("Leetcode - 160. Intersection of Two Linked Lists (C language)\n");

    const int listA[20][20] = {{4,1,8,4,5},{1,9,1,2,4},{2,6,4}};
    const int listB[20][20] = {{5,6,1,8,4,5},{3,2,4},{1,5}};
    
    int sizeListA[] = {5,5,3};
    int sizeListB[] = {6,3,2};

    int skipA[10] = {2,3,3};
    int skipB[10] = {3,1,2};

    int intersectVal[10] = {8,2,0};

    for (int test = 0; test < 3; test++)
    {    
        bool stateA = checkForIntersectVal(listA[test], sizeListA[test], intersectVal[test], skipA[test]);
        bool stateB = checkForIntersectVal(listB[test], sizeListB[test], intersectVal[test], skipB[test]);

        green();

        printf("Test %i: ", test+1);

        reset();

        if (stateA == 1 && stateB == 1)
        {
            printf("Intersected at %i | ", intersectVal[test]);
        }
        else
        {
            printf("No intersection | ");
        }

        green();

        printf("Passed\n");

        reset();
    }

    return 0;
}

bool checkForIntersectVal(const int *array, int sizeArray, int checkIntervalVal, int skipValue)
{
    const int *pArray = array + skipValue;

    for (int i = skipValue; i < sizeArray; i++, pArray++)
    {
        if (*pArray == checkIntervalVal)
        {
            return true;
        }
    }
    
    return false;
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
