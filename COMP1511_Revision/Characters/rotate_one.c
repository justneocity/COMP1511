//Revision shift letters 1 forward
//Rifa Jamal z5311190
//COMP1511 
//1/05/2020

#include <stdio.h>

int shift_one(int character);

int main(void) {
    
    int character = getchar();
    
    while (character != EOF) {
        int print_character = shift_one(character);
       
        putchar(print_character);
           
        character = getchar();
    }
    return 0;   
}

int shift_one(int character) {

    if (character >= 'a' && character <= 'z') {
        int alphabetPosition = character + 1;
        
        if (alphabetPosition > 'z') {
            alphabetPosition = 'a' + (alphabetPosition - 'z' - 1);
        }
        return alphabetPosition;
    } else if (character >= 'A' && character <= 'Z') {
        int alphabetPosition = character + 1;
        
        if (alphabetPosition > 'Z') {
            alphabetPosition = 'A' + (alphabetPosition - 'Z' - 1);
        }
        
        return alphabetPosition;         
    } else {
        return character;
    }
    
}
