#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fileBefore(const char* filename){
    char ch;
    FILE *fh_input;

    fh_input = fopen(filename,"r");

    if(fh_input == NULL){
        printf("File Not Opened");
        return -1;
    }

    while ((ch = fgetc(fh_input)) != EOF){
        printf("%c", ch);
    }
    fclose(fh_input);
    return 1;
}

int fileAfter(const char* filename){
    char ch;
    FILE *fh_input;

    fh_input = fopen(filename,"r");

    if(fh_input == NULL){
        printf("File Not Opened");
        return -1;
    }

    while ((ch = fgetc(fh_input)) != EOF){
        printf("%c", ch);
    }
        

    fclose(fh_input);
    return 1;

}
int fileConcatenate(const char* file1, const char*file2){
        //char BUFFER[100];
        char ch;

        FILE *fh_input1 = fopen(file1, "a");
        FILE *fh_input2 = fopen(file2, "r"); 

        while ((ch = fgetc(fh_input2)) != EOF){
            fputc(ch, fh_input1);
        } 
        
        fclose(fh_input1);
        fclose(fh_input2);
        return 0;
} 

int main(int argc, char* argv[]){

    if(strcmp(argv[1], argv[2]) == 0){
        printf("These files have the same name");
        return -1;
    }

    // char file1[30];
    // char file2[30];

    printf("File Name of First file: ");
    printf("%s\n",argv[1]);
    fileBefore(argv[1]);
    printf("\n");

    printf("\n");
    printf("File Name of Second file: ");
    printf("%s\n",argv[2]);
    fileBefore(argv[2]);
    printf("\n");

    printf("Files Entered: %s\n", argv[1]);
    printf("Files Entered: %s\n", argv[2]);

    fileConcatenate(argv[1],argv[2]);
    printf("\n");
    printf("First file Entered after Concat:\n");
    fileAfter(argv[1]);
    printf("\n");

    printf("\n");
    printf("Second file Entered after Concat:\n");
    fileAfter(argv[2]);
    printf("\n");

    return 0;
}
// gcc -o jlplayerlab4 jlplayerlab4.c
// ./jlplayerlab4 file1.txt file2.txt