// Loop Demo Lecture 4
// Rifa Jamal

#include <stdio.h>

int main(void) {

// *****************************************************
    // A loop within a loop. These should draw a grid of
    // stars
    
    int y = 0;
    // loop through and print multiple rows
    while (y < 10) { // we have printed y rows
        // print a single row
  
        int x = 0;
        while (x < 10) { // we have printed x stars in this row
            printf("*");
            x = x + 1;
        }
        printf("\n"); //this is to make stars on new line each time       
        y = y + 1;
 
    }
    

    return 0;
}

