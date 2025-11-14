#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
* To Compile: gcc -Wall jlplayerlab11.c
* To Run: ./a.out
*/

int main() {

    FILE *fp;
    char line[BUFSIZ];
    char command[1024];

    // Initalize Infinite Loop of asking for commands
    while (1) {
        printf("Enter Command (or quit to exit): ");
        scanf(" %[^\n]", command);  // 

        // Stop prompting user if quit entered
        if (strcmp(command, "quit") == 0) {
            printf("Exiting program...bye\n");
            break;
        }
        
        // Runs the terminal command and opens the pipe
        fp = popen(command, "r");
        if (fp == NULL) {
            perror("popen");
            continue;
        }

        // Gets the output of the command and diplays from the pipe(fp)
        // prints to terminal
        while (fgets(line, sizeof(line), fp) != NULL) {
            printf("%s", line);
        }

        // Closes the pipe while checking for errors
        if (pclose(fp) == -1) {
            perror("pclose");
        }
        
    }
    return 0;
}
