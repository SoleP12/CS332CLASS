#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    FILE *log_fp = fopen("output.log", "w");
    if (log_fp == NULL) {
        perror("fopen (log file)");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    char line[256];
    
    fclose(fp);
    fclose(log_fp);

    return 0;
}

// gcc -o jlplayerlab7 jlplayerlab7.c
// ./jlplayerlab7 command.txt