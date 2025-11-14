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

    // Initalize Infinite Loop
    while (1) {
        printf("Enter Command (or quit to exit): ");
        scanf(" %[^\n]", command);  // 

        if (strcmp(command, "quit") == 0) {
            printf("Exiting program...bye\n");
            break;
        }

        fp = popen(command, "r");
        if (fp == NULL) {
            perror("popen");
            continue;
        }

        
        while (fgets(line, sizeof(line), fp) != NULL) {
            printf("%s", line);
        }

        
        if (pclose(fp) == -1) {
            perror("pclose");
        }
        
    }

    return 0;
}
