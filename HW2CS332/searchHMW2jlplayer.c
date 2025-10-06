#include <stdio.h>
#include <dirent.h>
#include <getopt.h>
#include <stdlib.h>


int listDirectory(){
    DIR *directory;
    struct dirent *dirent;
    directory = opendir("/HMW2CS332");

    if(directory == NULL)
    {
        printf("Directory Opening error\n");
        return 1;
    }
    while ((dirent = readdir(directory)) != NULL)
    {
        if (dirent -> d_type == DT_REG)
        {
            printf("File: %s\n", dirent->d_name);
        }
    }
    







}






int main (int argc, char *argv[]){
    int opt;
    while((opt = getopt(argc,argv, "Ssf")) != 1){
        switch(opt){
            case 'S':          break;

            case 's':          break;

            case 'f':          break;

            default: printf("This file does not exist"); break;
        }
    }
    if(optind != argc-1){
        printf("File does not exist");
        return 1;
    }
    char *fn = argv[optind];

     
}
