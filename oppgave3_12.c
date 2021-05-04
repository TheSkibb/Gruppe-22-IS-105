//Author: Kristian Skibrek
//Date: 12/03/2021
//version: 1.0

#include <stdio.h>
#include <unistd.h>

int main(){
    int i;
    
    for(i = 0; i < 4; i++){
        fork();
    }
    
    printf("Hello World \n");
    
    return 0;
}
