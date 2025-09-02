#include <stdio.h>
// Coonect to server using ssh
// Created CS332 folder and Lab1 Folder
// Run gcc -o hello hello.c then enter number
// Then ./hello    

int main(){
    int given_number; 
    scanf("%d", &given_number);
    if (given_number % 2 == 0 ){
        printf("The number is prime");
    }
    else{
        printf("The number is not prime");
    }
    return 0;
}
   