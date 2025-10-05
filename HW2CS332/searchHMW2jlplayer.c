#include <stdio.h>









int main (int argc, char *argv[]){
     int a, b;

    printf("Enter Number 1: ");
    scanf("%d", &a);  // Notice the & before a

    printf("Enter Number 2: ");
    scanf("%d", &b);  // Notice the & before b

    printf("A = %d, B = %d\n", a, b);

    return 0;
}
