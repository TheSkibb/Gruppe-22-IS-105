//author: Kristian Skibrek
//date: 12/03/2021
//version 1.2


#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include<sys/wait.h>
#include<ctype.h>

#define BUFFER_SIZE 18
#define READ_END 0
#define WRITE_END 1

//function
void revereseCaseString(char arr[], int start, int end)
{
    for (int i = start; i < end; i++){
        
        char bokstav = arr[i];
        
        if(islower(bokstav))
            arr[i] = toupper(bokstav);

        else
            arr[i] = tolower(bokstav);
            }
}

int main(void){
    
int fd[2];
    
    
int fd_2[2];

pid_t pid;

    /*create the pipe*/
    if (pipe(fd)==-1){
        fprintf(stderr, "Pipe failed");
        return 1;
    }
    if (pipe(fd_2)==-1){
        fprintf(stderr, "pipe failed");
        return 1;
    }

    /*fork a child process*/
    pid = fork();

    if (pid < 0){
        fprintf(stderr, "Fork Failed");
        return 1;
    }

    if (pid > 0){/*the parent process*/
        /*close the unused end of the pipe*/
        char write_msg[BUFFER_SIZE] = "THis Is a meSSage";
        char read_msg[BUFFER_SIZE];
        
        close(fd[READ_END]);
        close(fd_2[WRITE_END]);
        
        /*write to the pipe*/
        write(fd[WRITE_END], write_msg, strlen(write_msg)+1);

        /*close the write end of the pipe*/
        close(fd[WRITE_END]);
        wait(NULL); //venter til child prosessen er ferdig med å lese fra pipen
        read(fd_2[READ_END], read_msg, BUFFER_SIZE);
        printf(" parent end : %s\n", read_msg); //printer det parent prosessen mottar fra pipen
    }

    else{/*child process*/
        
        char read_msg[BUFFER_SIZE];
        /*close the unused end of the pipe*/
        close(fd[WRITE_END]);
        close(fd_2[READ_END]);

        /*read from the pipe*/
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf(" child end : %s\n", read_msg); //printer det child prosessen mottar fra pipen
        
        revereseCaseString(read_msg, 0, BUFFER_SIZE);
        
        write(fd_2[WRITE_END], read_msg, strlen(read_msg)+1);

        /*close the write end of the pipe*/
    }

    return 0;

}

