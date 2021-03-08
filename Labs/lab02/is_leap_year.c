//This program is used to display number as word
//Written 24/02/2020d
//by Rifa Jamal z5311190
//for COMP1511 Lab 02 Exercise 2

#include <stdio.h>
int main(void) {
    int year;
    
    // User writes value of year
    printf("Enter year: ");
    scanf("%d", &year);
    
    //if (year is not divisible by 4) then (it is a common year)
    //if year is not divisible by 100) then (it is a leap year)
    //year is not divisible by 400) then (it is a common year)
    //else it is a leap year)
    
    if (year % 4!=0) {
        printf("%d is not a leap year.\n", year);
    } else if (year % 100!=0) {
        printf("%d is a leap year.\n", year);
    } else if (year % 400!=0) {
        printf("%d is not a leap year.\n", year);
    } else {
        printf("%d is a leap year.\n", year);
    }
    
    return 0;
} 
    
    
