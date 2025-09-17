#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;

    printf("Enter the words you want to enter: ");
    scanf("%d", &N); //Expects pointer to an address to unpack

    int *ptrToMemory = (int*)malloc(N * sizeof(int));
    if(ptrToMemory == NULL){
        printf("Memory not allocated. \n");
        return 1;
    }
    

    free(ptrToMemory);

}

