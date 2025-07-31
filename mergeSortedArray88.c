#include <stdio.h>

void sortedArray(int *lista1, int size2);

int main(void)
{
    int nums1[10] = {1,2,3,0,0,0};
    int nums2[] = {2,5,6};
    int m = 3;
    int n = 3;
    int var = 0;

    for (int i = 3; i < m+n; i++)
    {
        nums1[i] = nums2[i-n];
    }

    sortedArray(nums1, m+n);

    return 0;
}

void sortedArray(int *lista1, int size)
{
    int var = 0;

    for (int i = 0; i < size-1; i++)
    {
        if(lista1[i] > lista1[i+1]){
            var = lista1[i];
            lista1[i] = lista1[i+1];
            lista1[i+1] = var;
            i = 0;
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf("%i", lista1[i]);
    }

}