#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void stringreader(char **arrayCHR, int N){
    char charArray[100];
    for (int i = 0; i<N;i++){
        printf("Enter Sentence: ");
        scanf("%s", charArray);
        array[i] = malloc(strlen(charArray)+1);
        strcpy(charArray[i], charArray);
    }
}

void insertSort(char **arrayCHR, int N){
    for(int i = 0; i<N; i++){
        int ithLocal = i;
        while(ithLocal > 0 && strcmp(arrayCHR[ithLocal-1], arrayCHR[ithLocal]>0)){
            char *temp = arrayCHR[ithLocal];
            
        }

    }

}




int main(){
    int N;

    printf("Enter amount of strings: ");
    scanf("%d", &N);

    char **ptrToMemory = malloc(N * sizeof(char*));
    if(ptrToMemory == NULL){
        printf("Memory not allocated");
    }
    stringreader(ptrToMemory,N);
    insertSort(ptrToMemory,N);
    showStr(ptrToMemory,N); 


    free(ptrToMemory);

}

