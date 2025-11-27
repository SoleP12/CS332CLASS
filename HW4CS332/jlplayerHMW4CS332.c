#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>


// gcc -O -Wall jlplayerHMW4CS332.c -lpthread -- To Compile
//                                            -- To Run
int fd[2];


#define PARENT_PRODUCER_THREADS 10
#define MAX_VALUERAND 1000
#define CHILD_PRODUCER_THREADS 20
#define CHILD_NUMBERS_TOR_READ 250


int generateRadNum(){

}



int main(){
    srand(time(NULL));

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    pid_t pid = fork();


}