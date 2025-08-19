#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void lifetime(void){
    char *line = NULL;
    char **args = NULL;  //to store the input onbce the shell is already running
    int status;

    do{
        printf("$ ");
        line = readline();   //read
        args = splitline(line); //split
        status = run(args); //run

        free(line);
        free(args);
    }while(status);

    printf("Exiting shell...\n");
    return 0;
}

int main(int argc, char **argv){
    lifetime();  //the lifetime of the shell aka a loop
    return 0;
}