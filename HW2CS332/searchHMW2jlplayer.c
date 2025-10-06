
#include <stdio.h>
#include <dirent.h>
#include <getopt.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

void printstat(struct stat sb){
    printf("File Type: ");

    switch (sb.st_mode & S_)
    {
    case __S_IFDIR: printf("Directory: \n");
    case __S_IFREG: printf("Regular File\n");
    default: printf("Unknown File Type")
    }


}





int main (int argc, char *argv[]){
    int opt;
    while((opt = getopt(argc,argv, "Ssf")) != -1){
        switch(opt){
            case 'S':          
                break;

            case 's':          
                break;

            case 'f':          
                break;

            case '?': 
                fprintf(stderr, "Unknown option: -%c\n", optopt);     
                break;

            default: 
            printf("Escape: Ctrl + C\n"); 
                break;
        }
    }
    if(optind != argc-1){
        printf("Option Argument not included\n");
        return 1;
    }
    char *fn = argv[optind];
    printf("(FileName): %s\n",fn);

}
