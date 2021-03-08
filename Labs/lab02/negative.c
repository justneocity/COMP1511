//This program is used to identify positive, negative and zero numbers
//Written 24/02/2020d
//by Rifa Jamal z5311190
//for COMP1511 Lab 02 Exercise 2

#include <stdio.h>
int main(void) {
    int number;

    //Define integer
   
    scanf("%d", &number);
    
    //if and else if statements to identify number
    if (number > 0) {
        printf("You have entered a positive number.\n");
    } else if (number < 0) {
        printf("Don't be so negative!\n");
    } else {
        printf("You have entered zero.\n");
    }
    return 0;

}

