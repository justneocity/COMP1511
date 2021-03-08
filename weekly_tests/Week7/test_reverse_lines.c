//test reverse lines


#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main(void) {
    
    char input_array[MAX_LINE_LENGTH];
    char reverse_array[MAX_LINE_LENGTH];
    
    int character = getchar();
    
    int length = 0;
    int size = 0;
    int i = 0;
    while (character != EOF) {
        if (character != '\n') {
			input_array[i] = character;
			character = getchar();
			i++;
			length = i;
			size = length;
		} else if (character == '\n') {
            input_array[i] = character;
            int j = 0;
            while (j < size) {
	            reverse_array[j] = input_array[length-1];
	            putchar(reverse_array[j]);
	            length--;
	            j++;
            }
            i = length;
            reverse_array[j] = '\n';
            putchar(reverse_array[j]);
            character = getchar();
        } else {
            character = getchar();
		}
    }
    
    return 0;   
}

