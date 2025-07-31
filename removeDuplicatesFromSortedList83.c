#include <stdio.h>

void removeElementsByIndex(int *list, int size, int index);

int main(){

    int head[] = {1,1,2,3,3,3,4,4,4,4,5,5,5,5,5,5,5,7};
    int size = sizeof(head)/sizeof(head[0]);

    for (int i = 0; i < size; i++)
    {
        if (head[i] == head[i+1])
        {
            removeElementsByIndex(head, size, i+1);
            size -= 1;
            i = 0;
        }
        
        
    }

    for (int i = 0; i < size; i++)
    {
        printf("%i", head[i]);
    }
    
    

    return 0;
}

void removeElementsByIndex(int *list, int size, int index)
{   
    for (int i = index; i < size; i++)
    {
        list[i] = list[i+1];
    }
}