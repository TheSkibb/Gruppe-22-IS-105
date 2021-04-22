//Author: Kristian Skibrek
//Date: 12/03/2020
//version: 1.0

// A C program to demonstrate Zombie Process.  
// Child becomes Zombie as parent is sleeping 
// when child process exits. 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <stdio.h>
 
int main() 
{ 
    // Fork returns process id 
    // in parent process 
    pid_t child_pid = fork(); 
  
    // Parent process  
    if (child_pid > 0){ 
        sleep(10);
	printf("parent process done \n"); 
  	}
    // Child process 
    else        
	printf("child process done \n");
        exit(0); 
  
    return 0; 
} 
