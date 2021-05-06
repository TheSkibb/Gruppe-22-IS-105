//author: kristian skibrek
//date: 05/05/2021
//version 1.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {

    //input filnavnet man vil kopiere fra, legges is variablen readFile    
    printf("hvilken fil vil du kopiere?: ");
    char inputStr[20];
    scanf("%s", inputStr);
    const char* readFile = inputStr;
    //åpner filen som er gitt som input og gir den en file descriptor
    //O_RDONLY gjør at programmet kun kan lese fra filen
    int fdRead = open(readFile, O_RDONLY); 

    //feilsjekking
    if (fdRead == -1) {  
        perror("feil under åpning av input filen");
        exit(EXIT_FAILURE);
    }
    else{
        printf("(%s mottat)\n\n", inputStr);
    }

    //tar imot input for hva den nye filen skal hete
    printf("Hva vil du at den nye filen skal hete: ");
    scanf("%s", inputStr);
    const char* writeFile = inputStr;

    //åpner denne filen og gir den en file descriptor
    //O_CREAT hvis filen ikke eksisterer fra før av, lager programmet den
    //O_WRONLY programmet kan kun skrive til filen, 
    //O_TRUNC trunkerer filen (sletter alt eksisterende innhold)
    //S_IRUSR gir brukeren tillatelse til å lese fra filen
    //S_IWUSR git brukeren tillatelse til å skrive i filen
    int fdWrite = open(writeFile, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);

    if (fdRead == -1||fdWrite == -1) {
        perror("feil under åpning av output fil");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("(%s mottat)\n\n", inputStr);
    }
    
    //variabler til å lese fra filen
    char c;
    int bytes;
    //loop for å lese fra den ene filen og skrive det over i den andre
    while((bytes = read(fdRead, &c, sizeof(c))) > 0){
        write(fdWrite, &c, sizeof(c));
    }
     
    //printer i terminalen at skrivingen er ferdig
    printf("Tekst kopiert!\n");

    //lukker filene
    close(fdRead);
    close(fdWrite);

    exit(EXIT_SUCCESS);
}
