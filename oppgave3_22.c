#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <math.h>

int main(){
    //variabler for å lage shared mamory objekt
    const int SIZE = 4069; //størrelse
    const char *name = "OS"; //navn
    
    int shm_fd; //file descriptor
    void *ptr; //pointer
    
    
    //input med error checking, sjekker om input er en integer
    int num;
    printf("\nEnter an integer: ");
    int conv = scanf("%d", &num);
    
    if(conv == 0){ //om input ikke er en int, feiler programmet
        printf("that is not an integer\n");
        
    }
    else{
        
    pid_t pid = fork();
        
    if(pid == 0){//child process
        //lager et shared-memory object
        shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
        //konfigurerer størrelsen
        ftruncate(shm_fd, SIZE);
        //memory mapper objektet
        ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
        
        const char *space = " ";
        
        //legger til første nummer
        sprintf(ptr, "%u%s", num, space);
        int lenghtOfNum = floor(log10(abs(num))) + 1;
        ptr += lenghtOfNum + strlen(space);
        
        //collatz
        while(num > 1){
            if(num%2 > 0){
                num = 3*num + 1;
            }
            else{
                num /= 2;
            }
            //legger til det nye nummeret
            sprintf(ptr, "%u%s", num, space);
            int lenghtOfNum = floor(log10(abs(num))) + 1;
            ptr += lenghtOfNum + strlen(space);
            }
    }
    else{//parent process
        wait(NULL);
        
        //åpner shared memory object
        shm_fd = shm_open(name, O_RDONLY, 0666);
        ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
        
        //skriver ut fra objektet
        printf("\n%s\n", (char *)ptr);
        
        //sletter objektet
        shm_unlink(name);
        
        printf("\n");
    }
}
    return 0;
}

