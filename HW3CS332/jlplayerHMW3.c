#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>


void getDirectory(const char *directName){
    DIR  *dp;
    struct dirent *dirp;
    
    if((dp = opendir("c:\\src\\")) == NULL){
        while((dp = readdir(dp)) != NULL){
            printf("%s\n", dirp -> d_name);
        }
        closedir(dp);
    }else{
        perror("");
        return EXIT_FAILURE;
    }

}







int main(int argc, char* argv[]){
    printf("Directory Name --- %s", argv[1]);




}