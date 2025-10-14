#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>

#define MAX_LINE 1024
#define MAX_ARGS 64

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen("output.log", "a");
    if (!in || !out) {
        perror("File error");
        return 1;
    }

    char line[MAX_LINE];
    char *args[MAX_ARGS];

    while (fgets(line, sizeof(line), in)) {
        // Remove newline
        line[strcspn(line, "\n")] = '\0';

        // Skip empty lines
        if (strlen(line) == 0) continue;

        // Split line into args
        int i = 0;
        char *token = strtok(line, " ");
        while (token && i < MAX_ARGS - 1) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        // Get start time
        time_t start = time(NULL);

        pid_t pid = fork();
        if (pid == 0) {
            execvp(args[0], args);
            perror("exec failed");
            exit(1);
        } else if (pid > 0) {
            wait(NULL);  // wait for child
            time_t end = time(NULL);

            // Log: command    start time    end time
            fprintf(out, "%s\t%s\t%s", 
                line,
                ctime(&start),
                ctime(&end));
            fflush(out);
        } else {
            perror("fork failed");
        }
    }

    fclose(in);
    fclose(out);
    return 0;
}






















// gcc -o jlplayerlab7 jlplayerlab7.c
// ./jlplayerlab7