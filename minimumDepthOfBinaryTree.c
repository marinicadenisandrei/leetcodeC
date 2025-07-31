#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


int removeNull(int *test, int size);
int concatTwoLists(int *list1, int *list2, int *list3, int size1, int size2);

int main(void)
{

    int root[50][50] = {{3,9,2,0,0,5,7}, {2,0,3,0,4,0,5,0,6}};
    int testSize[10] = {7,8};

    for (int test = 0; test < 2; test++)
    {
        int rootSize = testSize[test];

        int left[10] = {};
        int right[10] = {};
        int temp[10] = {};

        int sizeLeft = 0;
        int sizeRight = 0;
        int sizeTemp = 0;

        int counter = 1;
        int power = 1;

        int depth = 1;
        int copy_d = 0;

        while(rootSize >= 0)
        {

            depth += pow(2,power);
            copy_d = depth;

            for (int i = depth-pow(2,power); i < depth-(pow(2,power)/2); i++)
            {
                left[sizeLeft] = root[test][i];
                sizeLeft++;
            }

            for (int j = depth-(pow(2,power)/2); j < depth; j++)
            {
                right[sizeRight] = root[test][j];
                sizeRight++;
            }
            
            sizeTemp = concatTwoLists(temp, left, right, sizeLeft, sizeRight);
            
            sizeTemp = removeNull(temp, sizeTemp);
    
            if (sizeTemp == 1)
            {
                counter++;
                copy_d -= 1;
            }
            else
            {
                power++;
            }        

            rootSize -= copy_d;
            sizeTemp = 0;
            sizeLeft = 0;
            sizeRight = 0;
        
        }

        printf("Test %i: %i | Passed\n", test+1, counter+1);

    }
}

int removeNull(int *test, int size)
{

    for (int i = 0; i < size; i++)
    {
        if (test[i] == 0)
        {
            for (int j = i; j < size; j++)
            {
                test[j] = test[j+1];
            }
            size--;
            i = 0;
        }
        
    }
    
    return size;
}

int concatTwoLists(int *list1, int *list2, int *list3, int size1, int size2)
{
    int size = 0;

    for (int i = 0; i < size1; i++)
    {
        list1[size] = list2[i];
        size++; 
    }

    for (int j = 0; j < size2; j++)
    {
        list1[size] = list3[j];
        size++; 
    }

    return size;
    
}