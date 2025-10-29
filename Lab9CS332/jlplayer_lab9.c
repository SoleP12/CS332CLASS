#include <stdio.h>
#include <signal.h>

static void sig_usr(int signo) {
    if (signo == SIGUSR1) {
    printf("received SIGUSR1\n");
    } else if (signo == SIGUSR2) {
    printf("received SIGUSR2\n");
    } else {
    printf("received signal %d\n", signo);
    }
}



int main(void) {
    if (signal(SIGUSR1, sig_usr) == SIG_ERR) {
        printf("can't catch SIGUSR1\n");
        exit(-1);
    }
    if (signal(SIGUSR2, sig_usr) == SIG_ERR) {
        printf("can't catch SIGUSR2\n");
        exit(-1);
    }
    for ( ; ; )
        pause();
    return 0;
}



// SIGINT: Interrupt a process from keyboard (e.g., pressing Control-C). The process
// is terminated.

// • SIGQUIT: Interrupt a process to quit from keyboard (e.g., pressing Control-/). The
// process is terminated and a core file is generated.

// • SIGTSTP: Interrupt a process to stop from keyboard (e.g., pressing Control-Z). The
// process is stopped from executing.

// • SIGUSR1 and SIGUSR2: These are user-defined signals, for use in application
// programs.

// gcc -o jlplayer_lab9 jlplayer_lab9.c
// ./jlplayer_lab9
