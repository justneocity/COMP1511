//Lab07 Decode Substitution Cipher
//Rifa Jamal z5311190
//COMP1511 
//5/04/2020

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int encrypt(int character, char alphabet_input[MAX_LINE_LENGTH]);

int main(void) {
    
    //declare string or array of 26 letters
    //program will read use input of array
    
    char alphabet_input[MAX_LINE_LENGTH];
    
    //read in line of text
    fgets(alphabet_input, MAX_LINE_LENGTH, stdin);
    
    int character = getchar();
    if (character == '\n') {
        character = getchar();
    }
         
    int length = strlen(alphabet_input);
    alphabet_input[length - 1] = '\0';
    
    while (character != EOF) {
        
        int print_character = encrypt(character, alphabet_input);
       
        putchar(print_character);  
        character = getchar();
        
    }
    
    return 0;   
}

int encrypt(int character, char alphabet_input[MAX_LINE_LENGTH]) {

    int counter = 0;
    
    if (character >= 'a' && character <= 'z') {
        while (alphabet_input[counter] != character) {
            counter++;
        } return counter + 'a';      
    } else if (character >= 'A' && character <= 'Z') {
        character = character + 'a' - 'A';
        while (alphabet_input[counter] != character) {
            counter++;
        } return counter + 'A';
        
    } else {
        return character; 
    }  
}

