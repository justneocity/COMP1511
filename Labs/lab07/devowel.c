//Lab07 Devowel text - print without lowercase vowels
//Rifa Jamal z5311190
//COMP1511 
//4/04/2020

#include <stdio.h>

int is_vowel(int character);

int main(void) {
    
    int character = getchar();
    
    while (character != EOF) {
        int print_character = is_vowel(character);
        
        if (print_character == 0) { 
            putchar(character);
            //character = getchar();
        }
        character = getchar();
    }
    return 0;   
}
 
int is_vowel(int character) {

    if (character == 'a' 
        || character == 'e' 
        || character == 'i' 
        || character == 'o' 
        || character == 'u' 
    ) { 
        return 1;
    }
    else {
        return 0;
    }
}
