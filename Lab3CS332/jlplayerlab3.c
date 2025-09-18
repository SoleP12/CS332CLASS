#include <stdio.h>
#include <stdlib.h>







int main(){
    int N;

    printf("Enter amount of strings: ");
    scanf("%d", &N);

    char **ptrToMemory = malloc(N * sizeof(char*));
    if(ptrToMemory == NULL){
        printf("Memory not allocated");
    }

    
    free(ptrToMemory);

}

