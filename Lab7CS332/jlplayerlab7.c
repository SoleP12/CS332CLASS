#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv) {
    pid_t pid;
    int status;

    FILE *filePtr = fopen(argv[1], "r");
    
    if (filePtr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    char buffer[256];
     while (fgets(buffer, sizeof(buffer), filePtr)) {
        time_t start_time = time(NULL);
        char *start_str = ctime(&start_time);

        
        printf("Start Time: %s\n", start_str);
        printf("Commands: %s", buffer);
       

        pid_t pid = fork();

        pid = fork();
        if (pid < 0) {
        // fork() failed
        perror("fork");
        exit(EXIT_FAILURE);
    }
     else if (pid == 0) {
        // Child process
        int status = system(buffer);
        printf("This is the child process [PID: %ld]\n", (long)getpid());
        exit(WEXITSTATUS(status));
    }
    else{
        int status;    
        wait(&status);
        time_t end_time = time(NULL);
        char *end_str = ctime(&end_time);
        if (WIFEXITED(status)) {
            printf("Command exited with status: %d\n", WEXITSTATUS(status));
        } else {
            printf("Command did not terminate normally.\n");
        }

        printf("End Time:   %s\n", end_str);
        printf("----------------------------------------\n");
        
    }








    }

    
   
    // else {
    //     // Parent process
    //     printf("Wait for child process to terminate\n");

    //     wait(&status); // Wait for child to finish

    //     if (WIFEXITED(status)) {
    //         printf("Child process exited with status = %d\n", WEXITSTATUS(status));
    //     } else {
    //         printf("Child process did not terminate normally\n");
    //     }
    //     printf("Parent process [PID: %ld]\n", (long)getpid());
    // }

   












    printf("\n");
    












    fclose(filePtr);
    return 0;
}




// gcc -o jlplayerlab7 jlplayerlab7.c
// ./jlplayerlab7 command.txt