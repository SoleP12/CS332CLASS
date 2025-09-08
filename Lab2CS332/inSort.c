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
    
    // Insertion Sort 
    for(int i = 0; i < N ; i++ ) {
        sampleArray[i] = rand() % 999;
        printf("%d ", sampleArray[i]);
    }
    printf("\n");

    





    // printf(N);
    return 0;
}
// gcc -o inSort inSort.c
// ./inSort