//Author: Kristian Skibrek
//Date: 12/03/2021
//version: 1.0

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	
    //input med error checking, sjekker om input er en integer
    int num;
    printf("\nEnter an integer: ");
    int conv = scanf("%d", &num);
    
    if(conv == 0){ //om input ikke er en int, feiler programmet
        printf("that is not an integer\n");
    }
    else{
        
    //deler programmet it to prosesser
    pid_t pid = fork();
        
    if(pid == 0){ //child process
        
        printf("%u", num); //printer første nummer (input)
        
        //colatz conj.
        while(num > 1){
            
            if(num%2 > 0){ // oddetall
                num = 3*num + 1;
            }
            
            else{ //partall
                num /= 2;
            }
            printf(", %u", num);
            }
        
        printf("\n");
    }
    else{//parent process
        wait(NULL); //venter med å terminate til child prosenssen er ferdig
    }
}
	return 0;
}
