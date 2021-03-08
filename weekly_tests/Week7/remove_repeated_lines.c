//Weekly Test Week 7
//Rifa Jamal z5311190
//remove repeated line
//7/04/2020

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256


/*int main(void) {
    char input[MAX_LINE_LENGTH];
    char output[MAX_LINE_LENGTH];
    char check_input[MAX_LINE_LENGTH];
    int result;

    while (fgets(input, MAX_LINE_LENGTH, stdin) != NULL) {
        
        //remove new lines
        int length = strlen(input);
        input[length - 1] = '\0';
        
        //save line of input into check_input
        strcpy(check_input, input);
     
        // comparing strings
        result = strcmp(input, check_input);
        
        if (result != 0) {
            strcpy(output, check_input);
            printf("%s\n", output);
        } else {
            printf("\n");
        }
    }    

    return 0;
}*/




int main(void) {
    
    char input[MAX_LINE_LENGTH];
    char check_input[MAX_LINE_LENGTH][MAX_LINE_LENGTH];
    //second array first [] how many can be stored, can store multiple lines
    //second [] = max value of line
    
    int i = 0;
    int j = 0;
    int check = 0;
    
    //this loop will continuosly record strings
    while (fgets(input, MAX_LINE_LENGTH, stdin) != NULL) {
        
        //remove new line and replace with \0
        int length = strlen(input);
        input[length - 1] = '\0';
        
        // check if line has been inputted before
        i = 0;
        check = 0;
        while (i < j) {
            
            if  (strcmp(input, check_input[i]) == 0) {
               
                check++;
            }  
            
            i++;
        }
        
        // Save previous lines of input into 2D check input array
        while (i <= j) {
            
            strcpy(check_input[i], input);
            i++;
        }
        
        // j counts how many times the loop has run
        j++;
        
        // if not, print the line
        if (check == 0) {
            
            printf("%s\n", input);
        } 
    }
    
    return 0;
}


