#include <stdio.h>

int main()
{
    int list1[10] = {1,2,4};
    int list2[10] = {1,3,4};
    
    int len_list1 = 3;
    int len_list2 = 3;
    
    int var = 0;
    
    for(int i = len_list1; i < len_list1+len_list2; i ++){
        list1[i] = list2[i-len_list2];
    }
    
    for (int i = 0; i < len_list1+len_list2-1; i++)
    {
        if (list1[i] > list1[i+1])
        {
            var = list1[i];
            list1[i] = list1[i+1];
            list1[i+1] = var;
            var = 0;
            i = 0;
        }
        
    }
    
    for(int z = 0; z < len_list1 + len_list2; z++){
        printf("%i", list1[z]);
    }

    return 0;
}



