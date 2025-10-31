// void controlC(int sig){
//     signal(SIGINT,SIG_IGN);
//     printf("You interupted the child proccess with ControlC");
// }


// void controlZ(int sign){
//     signal(SIGTSTP,SIG_IGN);
//     printf("You interupted the child proccess with ControlZ");
   
// }

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


int main(int argc, char **argv) {
    pid_t pid;
    int status;

    if (argc < 2) {
        printf("Usage: %s <command> [args]\n", argv[0]);
        exit(-1);
    }

    pid = fork();
    if (pid == 0) { /* this is child process */
        execvp(argv[1], &argv[1]);
        printf("If you see this statement then execl failed ;-(\n");
	perror("execvp");
	exit(-1);
    } else if (pid > 0) { /* this is the parent process */
        // Control C is ignored by the operating system when pressed
        signal(SIGINT,SIG_IGN);

        // Changes functionality and allows Control Z to be ignored by the operating system when pressed
        signal(SIGTSTP, SIG_IGN);

        // Pressing Control \ will terminate the program AKA a quit Signal
        signal(SIGQUIT, SIG_DFL);

        printf("Wait for the child process to terminate\n");
        wait(&status);                  /* wait for the child process to terminate */
        if (WIFEXITED(status)) {        /* child process terminated normally */
            printf("Child process exited with status = %d\n", WEXITSTATUS(status));
        } else {                        /* child process did not terminate normally */
            printf("Child process did not terminate normally!\n");
                                        /* look at the man page for wait (man 2 wait) to determine
                                        how the child process was terminated */
        }
    } else {                            /* we have an error */
        perror("fork");                 /* use perror to print the system error message */
        exit(EXIT_FAILURE);
    }
    printf("[%ld]: Exiting program .....\n", (long)getpid());
    return 0;
}
//  * To Compile -  gcc -Wall forkexecvp.c
//  * To run - ./a.out ./hw1 1000
//  * To Run: ./a.out <command> [args]

// SIGINT: Interrupt a process from keyboard (e.g., pressing Control-C). The process
// is terminated.

// • SIGQUIT: Interrupt a process to quit from keyboard (e.g., pressing Control-/). The
// process is terminated and a core file is generated.

// • SIGTSTP: Interrupt a process to stop from keyboard (e.g., pressing Control-Z). The
// process is stopped from executing.

// • SIGUSR1 and SIGUSR2: These are user-defined signals, for use in application
// programs.


