#include <stdio.h>

void removeElementByIndex(int *lista, int index, int size_list);

int main()
{

    int root[] = {1,0,2,3};
    
    int size = sizeof(root)/sizeof(root[0]);

    for (int i = 0; i < size; i++)
    {
        if (root[i] == 0)
        {
            removeElementByIndex(root, i, size);
            size--;
        }
        
    }

    for (int i = 0; i < size; i++)
    {
        printf("%i", root[i]);
    }
    
    

    return 0;
}

void removeElementByIndex(int *lista, int index, int size_list)
{

    for (int i = index; i < size_list; i++)
    {
        lista[i] = lista[i+1];
    }
}