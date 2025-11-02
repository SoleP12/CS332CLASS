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







int main(int argc, char* argv[]){
    printf("Directory Name --- %s", argv[1]);

    getDirectory(argv[1]);


}