#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>


void getDirectory(const char *directName) {
    DIR *dp;
    struct dirent *dirp;

    dp = opendir(directName);
    if (dp == NULL) {
        perror("opendir");
        return;
    }
    while ((dirp = readdir(dp)) != NULL) {
        printf("%s\n", dirp->d_name);
    }
    closedir(dp);
}

void listFiles(const char* dirname){
    DIR* dir = opendir(".");
    if (dir == NULL){
        return 1;
    }
    struct dirent* entity;
    entity = readdir(dir);
    while(entity != NULL){
        printf("%hhd %s\n", entity->d_type, entity->d_name);
        entity = readdir(dir);
    }
}


int main(int argc, char* argv[]){
    printf("Directory Name --- %s", argv[1]);

    getDirectory(argv[1]);


}