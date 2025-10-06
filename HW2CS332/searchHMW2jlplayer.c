
#include <stdio.h>
#include <dirent.h>
#include <getopt.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int listDirectories(const char *dirname) {
    struct dirent *dirent;
    DIR *parentDir = opendir(dirname);

    if (parentDir == NULL) {
        fprintf(stderr, "Error opening directory: %s\n", dirname);
        return -1;
    }
    
    int count = 1;
    while ((dirent = readdir(parentDir)) != NULL) {
        // Skip "." and ".."
        if (dirent->d_name[0] == '.' && 
           (dirent->d_name[1] == '\0' || 
           (dirent->d_name[1] == '.' && dirent->d_name[2] == '\0')))
            continue;
        printf("[%d] %s\n", count++, dirent->d_name);
    }
    closedir(parentDir);
    return 0;
}

int main (int argc, char *argv[]){

    int opt;
    while((opt = getopt(argc,argv, "Ssf")) != -1){
        switch(opt){
            case 'S': 
             if(optind != argc -1){
                fprintf(stderr, "Usage: %s -S <directory>\n", argv[0]);
                return 1;
            }      
                listDirectories(argv[optind]);   
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
    printf("(Directory Name): %s\n",fn);

}
/*/ 
make run ARGS="-S HMW2CS332"

make run ARGS="-S projects"


*/  

