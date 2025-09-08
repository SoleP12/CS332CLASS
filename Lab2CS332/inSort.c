#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void insertSort(){

}

int main(){
    int N;

    printf("Enter the size of the array: ");
    scanf("%d", &N); //Expects pointer to an address to unpack
    int sampleArray[N];
    printf("Your array is %d elements: \n" , N); //Expects actual value
    printf("Capacity of the array :%lu\n", sizeof(sampleArray)/sizeof(sampleArray[0]));

    // printf(); sd

    // Insertion Sort

    // printf(N);
    return 0;
}
// gcc -o inSort inSort.c
// ./inSort