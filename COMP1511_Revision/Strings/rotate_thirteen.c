// Perform the ROT13 algorithm on a string
// Completed by
// Rifa Jamal (z5311190)
// Completed on 01/05/2020

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

// Add your own #defines here

void rotate_thirteen(char *string);
char rotate_one(char c);
void rotate_thirteen(char *string);
int strings_equal(char *string1, char *string2);

// Add your own function prototypes here

int main(int argc, char *argv[]) {
    // Example tests
    char test_a[MAX_LENGTH] = "Hello, world!";
    rotate_thirteen(test_a);
    assert(strings_equal("Uryyb, jbeyq!", test_a));

    char test_b[MAX_LENGTH] = "abcdefghijklmnopqrstuvwxyz";
    rotate_thirteen(test_b);
    assert(strings_equal("nopqrstuvwxyzabcdefghijklm", test_b));

    char test_c[MAX_LENGTH] = "The quick brown fox jumped over the lazy dog.";
    rotate_thirteen(test_c);
    assert(strings_equal("Gur dhvpx oebja sbk whzcrq bire gur ynml qbt.", test_c));

    // Add your own tests here

    printf("All tests passed. You are awesome!\n");

    return 0;
}

void rotate_thirteen(char *string) {
    
    int length = strlen(string);
    int i = 0;
    
    while (i < length) {
        int j = 0;
        while (j < 13) {
            string[i] = rotate_one(string[i]);
            j++;
        }
        i++;
    }

}

char rotate_one(char c) {

    if (c >= 'a' && c <= 'z') {
        int alphabetPosition = c + 1;
        
        if (alphabetPosition > 'z') {
            alphabetPosition = 'a' + (alphabetPosition - 'z' - 1);
        }
        return alphabetPosition;
    } else if (c >= 'A' && c <= 'Z') {
        int alphabetPosition = c + 1;
        
        if (alphabetPosition > 'Z') {
            alphabetPosition = 'A' + (alphabetPosition - 'Z' - 1);
        }
        
        return alphabetPosition;         
    } else {
        return c;
    }
    
}

int strings_equal(char *string1, char *string2) {
    
    return strcmp(string1, string2) == 0;
}
