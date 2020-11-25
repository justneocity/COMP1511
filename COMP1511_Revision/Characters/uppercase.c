//Converts all lowercase to uppercase
//Rifa Jamal
//z5311190
//01/05/2020
//COMP1511 Revision

#include <stdio.h>

int swap_case(int character);

int main(void) {
    
    int character = getchar();
    
    while (character != EOF) {
        int print_character = swap_case(character);
       
        putchar(print_character);
           
        character = getchar();
    }
    return 0;   
}

int swap_case(int character) {

    if (character >= 'a' && character <= 'z') {
        int alphabetPosition = character - 'a';
        return 'A' + alphabetPosition;       
    } else {
        return character;
    }
    
}
