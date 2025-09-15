// gcc -o jlplayer_HW01 jlplayer_HW01.c
// ./jlplayer_HW01
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


// char s[100];

// Write the function sumOfDigits that takes a positive integer n and returns an int which is
//the sum of its digits.
// • If n is less than or equal to 0, return "-1"
int sumofDigitsHelper(){
    int number;
    printf("Enter a number for sum of digits: ");
    scanf("%d", &number);
    return number;
}
int sumOfDigits(int n){
    int temp = 0;
    int sum = 0;
    int OG = n;
        if (n <= 0){
            printf("-1\n");
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
int UABMaxMinDiff(int array[], int sizeofarray){
    int max = array[0];
    int min = array[0];
    int diff;
    for(int i = 0; i < sizeofarray; i++){
        if(array[i] > max){
            max = array[i];
        }
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    diff = max - min;
    return printf("The difference between max and min is: %d\n", diff);
int UABMaxMinDiff(int array[], int sizeofarray){
    int max = array[0];
    int min = array[0];
    int diff;
    for(int i = 0; i < sizeofarray; i++){
        if(array[i] > max){
            max = array[i];
        }
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    diff = max - min;
    return printf("The difference between max and min is: %d", diff);
}

/////////////////////////////////////////////////////////////////////////
// Write the function replaceEvenWithZero that takes an array of integers arr and returns a
// new array. The function should replace every even number in the array with 0. You can pass
// the size of the array as an input parameter

int replaceEvenWithZero(int array[], int sizeofarray){
    printf("Original Array is: ");
    for (int i = 0; i < sizeofarray; i++) {
        printf("[%d] ", array[i]);
    }
    for(int i = 0; i < sizeofarray;i++){
        if(array[i] %2 == 0){
            array[i] = 0;
        }
    }
    printf("Replaced Even With Zero: ");
    for (int i = 0; i < sizeofarray; i++) {
        printf("[%d] ", array[i]);
    }
    printf("\n");

int replaceEvenWithZero(int array[], int sizeofarray){
    for(int i = 0; i < sizeofarray;i++){
        if(array[i] %2 == 0){
            array[i] = 0;
        }
    }
    printf("Replaced Even With Zero: ");
    for (int i = 0; i < sizeofarray; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}


/////////////////////////////////////////////////////////////////////////
// Write the function perfectSquare that takes an integer n and returns True if n is a perfect
// square, and False otherwise. A perfect square is a number that can be expressed as k * k for
// some integer k.
int perfectSquareHelper(){
    int number;
    printf("Enter a number for perfect square: ");
    scanf("%d", &number);
    return number;
}
int perfectSquare(int N){
    if(N<=0){
        printf("False\n");
        return false;
    }
    else{
        printf("Number for PS is: %d: ", N);
        for(int i = 0; i*i<=N;i++){
            if (i*i == N){
                printf("True\n");
                return true;
            }
        }
    }
    printf("Number for PS is: %d ", N);
    printf("False\n");
    return false;
    
}
    

int perfectSquareHelper(){
    int N;
    printf("Enter your number: ");
    scanf("%d", &N);
    return N;
}

int perfectSquare(){
    int A = perfectSquareHelper();
    if (A % 2 ==0 && A > 0){
        return printf("True\n");
    }
    else{
        printf("False\n");
    }
    
}

/////////////////////////////////////////////////////////////////////////
// Write the function countVowels that takes a string s and returns an integer. The function should count
// the number of vowels (a, e, i, o, u) in the string, ignoring case.
int countVowelsHelper(char s []){
    printf("Enter Word: ");
    scanf("%[^\n]%*c", s);

    // scanf("%s",s); 
}
int countVowels(char s[]){
    int count = 0;
    countVowelsHelper(s);
    for(int i = 0; s[i]; i++){
        s[i] = tolower(s[i]);
    }

    for(int i = 0 ;s[i] != '\0' ;i++ ){
        if((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')){
            count++;
        }
    }
    return printf("Amount of vowels is: %d\n",count);    
}

/////////////////////////////////////////////////////////////////////////

int main(){
    // >>>int omega = sumofDigitsHelper();
    // >>>sumOfDigits(omega); 
    //Unhighlight for user input. Will corrut other scanfs in perfectsquare and countvowels keep those commented if not using
    // for correct results

    sumOfDigits(123);
    // sumOfDigits(405);
    // sumOfDigits(0);
    // sumOfDigits(7);
    // sumOfDigits(-308);

/////////////////////////////////////////////////////////////////////////
    int array[] = {3,7,2,9};
    int size = sizeof(array) / sizeof(array[0]);
                        //unhighlight together testcase1

    // int array2[] = {- 2, 4, -1, 6, 5};
    // int size2 = sizeof(array2) / sizeof(array2[0]);
                        //unhighlight together testcase2

    // int array3[] = {5,5,5,5,5,5};
    // int size3 = sizeof(array3) / sizeof(array3[0]);
                        //unhighlight together testcase3
    

    UABMaxMinDiff(array,size); //unhighlight for testcase1
    // UABMaxMinDiff(array2, size2); //unhighlight for testcase2
    // UABMaxMinDiff(array3, size3); //unhighlight for testcase3
/////////////////////////////////////////////////////////////////////////
    // int arrayrez1[] = {1,2,3,4};
    // int sizerez1 = sizeof(arrayrez1) / sizeof(arrayrez1[0]);
    //unhighlight together testcase1

    // int arrayrez2[] = {1,3,5};
    // int sizerez2 = sizeof(arrayrez2) / sizeof(arrayrez2[0]);
    //unhighlight together testcase2

    int arrayrez3[] = {2,4,6};
    int sizerez3 = sizeof(arrayrez3) / sizeof(arrayrez3[0]);
    //unhighlight together testcase3
    // sumOfDigits(23);
    // sumOfDigits(405);
    // sumOfDigits(0);
    // sumOfDigits(7);
    // sumOfDigits(-308);
/////////////////////////////////////////////////////////////////////////

    // int array[] = {3,7,2,9};
    // int size = sizeof(array) / sizeof(array[0]);

    // int array2[] = {- 2, 4, -1, 6, 5};
    // int size = sizeof(array2) / sizeof(array2[0]);

    // int array3[] = {5,5,5,5,5,5};
    // int size = sizeof(array3) / sizeof(array3[0]);
    // UABMaxMinDiff(array,size);
    // UABMaxMinDiff(array2, size);
    // UABMaxMinDiff(array3, size);
/////////////////////////////////////////////////////////////////////////
    // int arrayrez1[] = {1,2,3,4};
    // int sizerez1 = sizeof(arrayrez1) / sizeof(arrayrez1[0]);

    // int arrayrez2[] = {1,3,5};
    // int sizerez2 = sizeof(arrayrez2) / sizeof(arrayrez2[0]);

    // int arrayrez3[] = {2,4,6};
    // int sizerez3 = sizeof(arrayrez3) / sizeof(arrayrez3[0]);

    // replaceEvenWithZero(arrayrez1,sizerez1); //unhighlight for testcase1
    // replaceEvenWithZero(arrayrez2, sizerez2); //unhighlight for testcase2
    replaceEvenWithZero(arrayrez3,sizerez3); //unhighlight for testcase3
/////////////////////////////////////////////////////////////////////////

    // int alpha = perfectSquareHelper();
    // perfectSquare(alpha);
            //Unhighlight together for user input

    perfectSquare(16);
    // perfectSquare(15);
    // perfectSquare(25);
    // perfectSquare(36);
    
    /////////////////////////////////////////////////////////////////////////
    char s[100]; //unhighlight for array creation along with countVowels functions
    // countVowels(s);
    countVowels(s);
    // countVowels(s);
    // countVowels(s);
}

    // replaceEvenWithZero(arrayrez1,sizerez1);
    // replaceEvenWithZero(arrayrez2, sizerez2);
    // replaceEvenWithZero(arrayrez3,sizerez3);
/////////////////////////////////////////////////////////////////////////

    
    perfectSquare();
    // perfectSquare();
    
    // perfectSquare();
    // perfectSquare();

    // countVowels();
    // countVowels();
    // countVowels();
    // countVowels();



}