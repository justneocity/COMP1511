//This program is used to display number as word
//Written 24/02/2020d
//by Rifa Jamal z5311190
//for COMP1511 Lab 02 Exercise 2

#include <stdio.h>
int main(void) {
    int number;
    
    //enter number
    printf("Please enter an integer: ");
    scanf("%d", &number);
    
    //if and else if statements
    if (1 <= number && number <= 5) {
        printf("You entered ");
        if (number == 1) {
            printf("one.\n");
        } else if (number == 2) {
            printf("two.\n");
        } else if (number == 3) {
            printf("three.\n");
        } else if (number == 4) {
            printf("four.\n");   
        } else if (number == 5) {
            printf("five.\n");  
        }
    } else if (number < 1) {
        printf("You entered a number less than one.\n");
    } else {
        printf("You entered a number greater than five.\n");
    }
    return 0;
}
