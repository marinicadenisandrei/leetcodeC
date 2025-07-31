#include <stdio.h>
#include <math.h>

int checkMirrorState(int *lista, int size);
int removeNullElement(int *lista, int size);
int checkBinaryList(int size);


int main()
{
    // Test 1
    int root[] = {1,2,2,3,4,4,3};

    //Test 2
    int root[] = {1,2,2,0,3,0,3};

    int size_root = sizeof(root)/sizeof(root[0]);


    size_root = removeNullElement(root,size_root);

    if (checkBinaryList(size_root) == 1)
    {
        int tree[] = {};

        int counter_first = 0;
        int counter_last = 0;
        int power = 1;

        int counter_add = 0;
        int flag = 1;

        for (int i = 0; i < 3; i++)
        {
            for (int j = counter_first; j <= counter_last; j++)
            {
                tree[counter_add] = root[j];
                counter_add++;
            }

            for (int k = 0; k < counter_add; k++)
            {
                if (counter_add > 1)
                {
                    if(checkMirrorState(tree, counter_add) == 0){
                        flag = 0;
                        // printf("here");
                        break;
                    }
                }
            }

            if (flag == 0)
            {
                break;
            }
        
            counter_first = counter_last + 1;
            counter_last = counter_first + pow(2,power) - 1;
            power++;
            counter_add = 0;
        }

        (flag = 1) ? printf("True") : printf("False");
    }
    else
    {
        printf("False");
    }
    

    return 0;
}

int checkMirrorState(int *lista, int size)
{

    int final = size-1;
    int flag = 1;

    for (int i = 0; i < size/2; i++)
    {
        // printf("%i %i\n", lista[i], lista[final]);
        if (lista[i] != lista[final])
        {
            flag = 0;
            break;
        }
        final--;
    }
    
    return flag;

}

int removeNullElement(int *lista, int size)
{

    for (int i = 0; i < size; i++)
    {
        if (lista[i] == 0)
        {
            for (int j = i; i < size; i++)
            {
                lista[j] = lista[j+1];
            }
            size--;
            i = 0;   
        }
        
    }

    return size;

}

int checkBinaryList(int size)
{

    int binar_nr = 0;
    int power = 0;
    int flag = 1;

    while(binar_nr < size)
    {
        binar_nr += pow(2,power);
        // printf("%i\n", binar_nr);
        power++;
    }

    (binar_nr != size) ? flag = 0 : 1; 

    return flag;
    
}