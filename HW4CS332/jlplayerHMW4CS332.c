#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>
#include <string.h>
#include <sys/wait.h>


// gcc -O -Wall jlplayerHMW4CS332.c -lpthread -- To Compile
//                                            -- To Run

// Pipe
int fd[2];
pthread_mutex_t pipe_mut;
pthread_mutex_t pipe_read_mut;
pthread_mutex_t printf_mut;
sem_t write_sem;



#define PARENT_PRODUCER_THREADS 10
#define AMOUNT_OF_RANDINT 500
#define MAX_VALUE_RAND 1001
#define CHILD_PRODUCER_THREADS 20
#define CHILD_NUMBERS_TO_READ 250

double toal_sum = 0.0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


struct threadVari {
    int tid;            // Thread ID
    int size;           // Number of consumer threads
    int N;              // Number of elements this thread should read
    double *sum;        // Pointer to global sum
};

// Random Number Generator
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
