#include <stdio.h>
#include <dirent.h>
#include <getopt.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>


int showFilesOnly = 0;
long sizeLimit =-1;

int listDirectories(const char *dirname) {
    struct dirent *dirent;
    DIR *parentDir = opendir(dirname);

    if (parentDir == NULL) {
        fprintf(stderr, "Error opening directory: %s\n", dirname);
        return -1;
    }

    int count = 1;
    while ((dirent = readdir(parentDir)) != NULL) {
        if (dirent->d_name[0] == '.' && 
           (dirent->d_name[1] == '\0' || 
           (dirent->d_name[1] == '.' && dirent->d_name[2] == '\0')))
            continue;

        char fullPath[1024];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", dirname, dirent->d_name);

        struct stat sb;
        if (stat(fullPath, &sb) == -1) {
            perror("stat");
            continue;
        }

        if (showFilesOnly && S_ISDIR(sb.st_mode))
            continue;
        
        printf("[%d] %s ", count++, dirent->d_name);
        
        printf(" ---- Permissions: ");
        permissions(fullPath);
        printf(" ---- Last File Access: ");
        lastAccess(fullPath);
        printf(")\n");
    }

    closedir(parentDir);
    return 0;
}


int printSize(const char *path){
    struct stat sb;
    if (stat(path, &sb) == -1) {
        perror("stat");
        return -1;
    }

    if (S_ISDIR(sb.st_mode)) {
        printf("0");
        return 0;
    } else {
        printf("%ld", sb.st_size);
        return sb.st_size;
    }
}

int permissions(const char *path){
     struct stat sb;
    if (stat(path, &sb) == -1) {
        perror("stat");
        return -1;
    }
    char perms[11];
    perms[0] = S_ISDIR(sb.st_mode) ? 'd' : '-';
    perms[1] = (sb.st_mode & S_IRUSR) ? 'r' : '-';
    perms[2] = (sb.st_mode & S_IWUSR) ? 'w' : '-';
    perms[3] = (sb.st_mode & S_IXUSR) ? 'x' : '-';
    perms[4] = (sb.st_mode & S_IRGRP) ? 'r' : '-';
    perms[5] = (sb.st_mode & S_IWGRP) ? 'w' : '-';
    perms[6] = (sb.st_mode & S_IXGRP) ? 'x' : '-';
    perms[7] = (sb.st_mode & S_IROTH) ? 'r' : '-';
    perms[8] = (sb.st_mode & S_IWOTH) ? 'w' : '-';
    perms[9] = (sb.st_mode & S_IXOTH) ? 'x' : '-';
    perms[10] = '\0';

    printf("%s", perms);
    return 0;

}
int lastAccess(const char *path){
     struct stat sb;
    if (stat(path, &sb) == -1) {
        perror("stat");
        return -1;
    }

    char timebuf[100];
    struct tm *tm_info = localtime(&sb.st_atime);
    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", tm_info);
    printf("%s", timebuf);

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
                fprintf(stderr, "Unknown File Tag: -%c\n", optopt);     
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
make run ARGS="-S projects"
*/  