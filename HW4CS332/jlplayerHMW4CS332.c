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


#define PARENT_PRODUCER_THREADS 10
#define AMOUNT_OF_RANDINT 500
#define MAX_VALUE_RAND 1001
#define CHILD_PRODUCER_THREADS 20
#define CHILD_NUMBERS_TO_READ 250



pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


struct threadVari {
    int tid;            // Thread ID
    int size;           // Number of consumer threads
    int N;              // Number of elements this thread should read
    double *sum;        // Pointer to global sum
};

int fd[2];
pthread_mutex_t pipe_mut;
pthread_mutex_t pipe_read_mut;
pthread_mutex_t printf_mut;
sem_t write_sem;

double toal_sum = 0.0;

// Random Number Generator
void generateRandNum(int **arr, int count){
    int used[MAX_VALUE_RAND] = {0};
    int num;

    for (int i = 0; i < count; ) {
        num = rand() % MAX_VALUE_RAND;
        if (!used[num]) {
            arr[i++] = num;
            used[num] = 1;
        }
    }
}

void* producer(void *arg){
    int id = *(int*)arg;

    int numbers[AMOUNT_OF_RANDINT];
    generateRandNum(numbers, AMOUNT_OF_RANDINT);

    for(int i =0; i < AMOUNT_OF_RANDINT; i++){
        sem_wait(&write_sem);
        pthread_mutex_lock(&pipe_mut);

        write(fd[1], &numbers[i], sizeof(int));

        pthread_mutex_unlock(&pipe_mut);
        sem_post(&write_sem);

    }
    pthread_mutex_lock(&printf_mut);
    printf("Producer %d finished producing %d numbers.\n", id, AMOUNT_OF_RANDINT);
    pthread_mutex_unlock(&printf_mut);

    return NULL;
}






















int main(){
    srand(time(NULL));
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }
    pid_t pid = fork();
}
