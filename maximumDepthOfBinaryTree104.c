#include <stdio.h>
#include <math.h>

#define LEN_TEST 2

int removeNullElements(int *list, int size);
int checkMaximumDepth(int size);

int main()
{

    int root[LEN_TEST][10] = {{3,9,20,0,0,15,7}, {1,0,2}};
    int sizes[] = {7,3};


    for (int i = 0; i < LEN_TEST; i++)
    {
        int size = sizes[i];
        size = removeNullElements(root[i], size);

        printf("Test %i: %i | Passed\n", i+1, checkMaximumDepth(size));
    }

    return 0;
}


int removeNullElements(int *list, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (list[i] == 0)
        {
            for (int j = i; j < size; j++)
            {
                list[j] = list[j+1];
                size--;
                i = 0;
            }
        }
    }
    
    return size;
}

int checkMaximumDepth(int size)
{
    int binary = 2;
    int counter = 0;
    int result = 0;

    while (result < size)
    {
        result = pow(binary,counter);
        counter++;
    }

    return counter;
}