#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(){
    int N;

    printf("Enter the size of the array: ");
    scanf("%d", &N); //Expects pointer to an address to unpack

    int sampleArray[N];

    printf("Your array is %d elements \n" , N); //Expects actual value
    printf("Capacity of the array : %lu\n", sizeof(sampleArray)/sizeof(sampleArray[0]));

     srand(time(NULL)); 
    printf("Here is your unsorted Array: ");
    // Insertion Sort 
    for(int i = 0; i < N ; i++ ) {
        sampleArray[i] = rand() % 999;
        printf("%d ", sampleArray[i]);
    }
    printf("\n");
    printf("Here is your sorted array: ");
    int temporaryVal, currentLocal;
    for (int i = 1; i < N; i++){
        currentLocal = i;
        while (currentLocal > 0 && sampleArray[currentLocal-1]> sampleArray[currentLocal]){
            temporaryVal = sampleArray[currentLocal];
            sampleArray[currentLocal] = sampleArray[currentLocal - 1];
            sampleArray[currentLocal-1] = temporaryVal;
            currentLocal--;
        }
    }
    for(int i = 0; i<N; i++){
        printf("%d ", sampleArray[i]);
    }


    





    // printf(N);
    return 0;
}
// gcc -o inSort inSort.c
// ./inSort