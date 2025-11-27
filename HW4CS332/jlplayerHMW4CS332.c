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
#define AMOUNT_OF_RANDINT 500
#define MAX_VALUE_RAND 1001
#define CHILD_PRODUCER_THREADS 20
#define CHILD_NUMBERS_TO_READ 250


int generateRadNum(int **arr, int count){
    
    
}



int main(){
    srand(time(NULL));

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    pid_t pid = fork();
    


}