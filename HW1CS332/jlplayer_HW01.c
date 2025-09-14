// gcc -o jlplayer_HW01 jlplayer_HW01.c
// ./jlplayer_HW01
#include <stdio.h>

// Write the function sumOfDigits that takes a positive integer n and returns an int which is
//the sum of its digits.
// • If n is less than or equal to 0, return "-1"
 int sumOfDigits(int n){
    int temp = 0;
    int sum = 0;
    int OG = n;
        if (n <= 0){
            return -1;
        }else{
            while(n>0){
               temp = n%10;
               sum += temp;
               n = n/10;
            }
        }
        return printf("Sum of Digits is %d, With number being %d \n",sum,OG);

    }

/////////////////////////////////////////////////////////////////////////
// Write the function UABMaxMinDiff that takes an array of integers arr and returns the difference
// between the maximum and minimum elements in the array. You can pass the size of the array as an
// input parameter.
int UABMaxMinDiff(int array[]){
   int N;

    printf("Enter the size of the array: ");
    for(int i = 0; i = array;i++){
        scanf("%d", &N);
    }
    
}

/////////////////////////////////////////////////////////////////////////
// Write the function replaceEvenWithZero that takes an array of integers arr and returns a
// new array. The function should replace every even number in the array with 0. You can pass
// the size of the array as an input parameter
int replaceEvenWithZero(){
    printf("Hello");
}
/////////////////////////////////////////////////////////////////////////
// Write the function perfectSquare that takes an integer n and returns True if n is a perfect
// square, and False otherwise. A perfect square is a number that can be expressed as k * k for
// some integer k.
int perfectSquare(){
    printf("Hello");
}

/////////////////////////////////////////////////////////////////////////
// Write the function countVowels that takes a string s and returns an integer. The function should count
// the number of vowels (a, e, i, o, u) in the string, ignoring case.
int countVowels(){
    printf("Hello");
}

/////////////////////////////////////////////////////////////////////////

int main(){

    // sumOfDigits(23);
    // sumOfDigits();
    // sumOfDigits();
    // sumOfDigits();
    // sumOfDigits();

    int array[10];
    UABMaxMinDiff(array);
    
    // UABMaxMinDiff();
    // UABMaxMinDiff();

    // replaceEvenWithZero();
    // replaceEvenWithZero();
    // replaceEvenWithZero();

    // perfectSquare();
    // perfectSquare();
    // perfectSquare();
    // perfectSquare();

    // countVowels();
    // countVowels();
    // countVowels();
    // countVowels();



}