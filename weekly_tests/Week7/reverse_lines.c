//Weekly Test Week 7
//Rifa Jamal z5311190
//Reverse lines of input
//7/04/2020

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main(void) {
    
    char alphabet_input[MAX_LINE_LENGTH];
    
    while (fgets(alphabet_input, MAX_LINE_LENGTH, stdin) != NULL) {
        //find length of string before new line and \0
        int length = 0;
        while (alphabet_input[length] != '\0' 
            && alphabet_input[length] != '\n') {
            length++;
        }
        //loop through reverse string
        int i = length - 1;
        while (i >= 0) {
            putchar(alphabet_input[i]);
            i--;
        }   
        printf("\n");
    }
    
    return 0;   
}      
