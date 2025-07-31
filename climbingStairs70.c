#include <stdio.h>



int main(){

    int n = 5;
    int list[10] = {};
    int counter = 0;

    int list_steps[] = {1,2};
    int counter_final = 0;

    int flag_stop = 0;

    int len_lista_steps = sizeof(list_steps)/sizeof(list_steps[0]);

    while (flag_stop == 0)
    {
        
        for (int i = 0; i < len_lista_steps; i++)
        {   
            if(list_steps[i] < n)
            {
                list[counter] = list_steps[i] + 1;
                list[counter+1] = list_steps[i] + 2;  
                counter += 2;
            }
            else
            {
                list[counter] = list_steps[i];
                counter += 1;
            }
        }


        // verificare lista finala 

        for (int i = 0; i < counter; i++)
        {
            if(list[i] >= n)
            {
                flag_stop = 1;
            }
            else
            {
                flag_stop = 0;
                break;
            }
        }


        if(flag_stop == 0)
        {
            for (int i = 0; i < counter; i++)
            {
                list_steps[i] = list[i];
                list[i] = 0;
            }

            len_lista_steps = counter;
            counter = 0;
            
        }
        else
        {
            break;
        }
    }

    int NumOfSteps = 0;

    for (int i = 0; i < len_lista_steps+1; i++)
    {
        if (list[i] == n)
        {
            NumOfSteps += 1;
        }
        
    }

    printf("%i steps", NumOfSteps);
    

    return 0;

}

