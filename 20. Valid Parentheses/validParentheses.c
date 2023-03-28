#include <stdio.h>
#include <string.h>

#define VALID_P 3

int main()
{
    char s[] = "()[]{}";
    char valid[3][4] = {"()","[]","{}"};
    int flag = 0;
    int len_s = strlen(s);
    char paranteza[] = "";
    int flag_impar = 1;
    
    if (len_s % 2 == 1){
        flag_impar = 0;
    }
    
    for(int i = 0; i < len_s; i+=2){
        
        paranteza[0] = s[i];
        paranteza[1] = s[i+1];
        
        for(int j = 0; j < VALID_P; j++){
            if(valid[j][0] == paranteza[0] && valid[j][1] == paranteza[1]){
                flag = 1;
                break;
            }
            else{
                flag = 0;
            }
        }
        
        if (flag == 0){
            break;
        }
    }
    
    if (flag_impar == 0){
        printf("false");
    }
    else if (flag == 0){
        printf("false");
    }
    else {
        printf("true");
    }
    
    return 0;
}









