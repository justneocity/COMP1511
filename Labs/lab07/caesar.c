//Lab07 Caesar Cipher - shift
//Rifa Jamal z5311190
//COMP1511 
//5/04/2020

#include <stdio.h>

int encrypt(int character, int shift);
int shift_alphabet (int character, int shift, int start, int end);

int main(void) {
    
    int shift = 0;
    //int start;
    //int end;
    
    scanf("%d", &shift);
    
    int character = getchar();
   
    
    while (character != EOF) {
        
        int print_character = encrypt(character, shift);
       
        putchar(print_character);
           
        character = getchar();
    }
    
    return 0;   
}

int encrypt(int character, int shift) {

    if (character >= 'a' && character <= 'z') {
        int new_character = shift_alphabet (character, shift, 'a', 'z');
        return new_character;       
    } else if (character >= 'A' && character <= 'Z') {
        int new_character = shift_alphabet (character, shift, 'A', 'Z');
        return new_character;       
    } else {
        return character;
    }  
}

int shift_alphabet (int character, int shift, int start, int end) {

    int shifted_character = character + shift; 
    
    while (shifted_character < start || shifted_character > end) {
        if (shifted_character > end) {
            shift = shifted_character - end - 1;
            //shift = (shifted_character % 26);
            shifted_character = start + shift;
        } else if (shifted_character < start) {
            shift = start - shifted_character - 1;
            //shift = start - (shifted_character % 26);
            shifted_character = end - shift;
        }
    }   
            
 
    return shifted_character;
}

