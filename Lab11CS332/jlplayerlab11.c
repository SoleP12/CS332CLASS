#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int pipe(int pipefd[2]);





int main(int argc, char *argv[]){
    if (argc != 3) {
        printf("Usage: %s <command1> <command2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    scanf("Enter Unix Command: ");
}