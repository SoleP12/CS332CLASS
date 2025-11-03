#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

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


char*filetype (unsigned char type){
    char *str;
    switch(type){
        case DT_DIR: str = "Directory"; break;
        case DT_REG: str = "File"; break;
        default: str = "UNKNOWN";
    }
    return str;
}

void printFileSIZE(const char *filename){
    struct stat sb;
    if(stat(filename, &sb) == 0){
        printf("|File Size == %lld|", (long long) sb.st_size);
    }
}

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
        printf("[%s]--%s", filetype(dirp->d_type) , dirp->d_name);

        if(dirp->d_type == DT_REG) {
            char filepath[1024];
            snprintf(filepath, sizeof(filepath), "%s/%s", directName, dirp->d_name);
            printFileSIZE(filepath);
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