#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#ifndef DT_DIR
#define DT_DIR     4
#define DT_REG     8
#endif


// char *filetype(const char *path) {
//     struct stat st;
//     if (stat(path, &st) == -1)
//         return "UNKNOWN";

//     if (S_ISDIR(st.st_mode)) return "Directory";
//     if (S_ISREG(st.st_mode)) return "File";
//     return "0";
// }

// Determine the Type of File that is in the Overall Directory
char*filetype (unsigned char type){
    char *str;
    switch(type){
        case DT_DIR: str = "Directory"; break;
        case DT_REG: str = "File"; break;
        default: str = "UNKNOWN";
    }
    return str;
}

// Determines the File Size for Files only
void printFileSIZE(const char *filename){
    struct stat sb;
    if(stat(filename, &sb) == 0){
        printf(" --- File Size = %lld bytes | ", (long long) sb.st_size);
    }
}

// Determines the word count for file with
void wordCount(const char *Directory){
    FILE *filp;
    int count = 0;
    char c, prev = ' ';
    filp = fopen(Directory, "r");
    if(filp == NULL){
        printf("File Not Found\n");
        return;
    }
    while((c = fgetc(filp)) != EOF){
        if((c == ' ' || c == '\n' || c == '\t') &&
            (prev != ' ' && prev != '\n' && prev != '\t'))
                count++;
            prev = c;
    }
    fclose(filp);
    printf("Words: %d\n", count);
    return;
}


// Takes 
void getDirectory(const char *directName) {
    DIR *dp;
    struct dirent *dirp;

    dp = opendir(directName);
    if (dp == NULL) {
        perror("Directory Name Invalid");
        return;
    }
     while ((dirp = readdir(dp)) != NULL) {
        // Skip "." and ".."
        if (dirp->d_type == DT_DIR && 
            (dirp->d_name[0] == '.' && 
            (dirp->d_name[1] == '\0' || 
             (dirp->d_name[1] == '.' && dirp->d_name[2] == '\0')))) 
        {
            continue;
        }
        printf("[%s]---%s\n", filetype(dirp->d_type) , dirp->d_name);

        if(dirp->d_type == DT_REG) {
            pid_t pid = fork();
            if(pid < 0){
                perror("Fork Did Not Work");
                continue;
            }
            else if(pid == 0){
                char filepath[1024];
                printf("  Child Process PID:%d | With File %s", getpid(), dirp->d_name);
                snprintf(filepath, sizeof(filepath), "%s/%s", directName, dirp->d_name);
                printFileSIZE(filepath);
                wordCount(filepath);
                exit(0);
            }
            else{
                waitpid(pid, NULL, 0);
            }
        }
        printf("\n");
    }
    closedir(dp);
}



int main(int argc, char* argv[]){

    if(argc < 2){
        printf("Usage: %s <dirname>\n", argv[0]);
        exit(-1);
    }

    struct dirent *dirent;
    DIR *parentDir = opendir(argv[1]);
    if(parentDir == NULL){
        printf("Error Opening Directory -- %s\n", argv[1]);
        exit(-1);
    }

    printf("Directory Name --- %s with -%s- Directory\n", argv[0], argv[1]);
    getDirectory(argv[1]);
    return 0;

}