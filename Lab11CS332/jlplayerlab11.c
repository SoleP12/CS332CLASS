#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
* To Compile: gcc -Wall jlplayerlab11.c
* To Run: ./a.out <command>
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char line[BUFSIZ];
    char command[1024];

    while (1) {
        printf("Enter Command (or quit to exit): ");
        scanf(" %[^\n]", command);  // 

        if (strcmp(command, "quit") == 0) {
            printf("Exiting...\n");
            break;
        }

        // Execute the command
        fp = popen(command, "r");
        if (fp == NULL) {
            perror("popen");
            continue;
        }

        // Print command output
        while (fgets(line, sizeof(line), fp) != NULL) {
            printf("%s", line);
        }

        // Close the pipe
        if (pclose(fp) == -1) {
            perror("pclose");
        }

        printf("\n");  // Add spacing between commands
    }

    return 0;
}
