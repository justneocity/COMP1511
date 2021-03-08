//lab05 COMP1511
//Rifa Jamal z5311190
//16/03/2020
//Boxes

#include <stdio.h>

int main(void) {

    int boxes; 
    
    printf("How many boxes: ");
    scanf("%d", &boxes);
  
    int size = (boxes * 4) - 1;
   
    int row = 1; // Row counter
    int col = 1; // Column counter
    
    int squares = (boxes * 2);

    // Print each row
    while (row <= size) {
        col = 1;
        if (row < squares) {
            // Print each column
            while (col <= size) {

                // If current row is odd
                if ((row % 2) != 0) {

                    // If current column is odd
                    if ((col % 2) != 0) {
                        printf("1");
                    } else {
                        // If current column is even
                        if ((col < row) || ((size - col) < row)) {
                            printf("0");
                        } else {
                            printf("1");
                        }
                    }
                } else {
                    // If current row is even

                    // If current column is odd
                    if ((col % 2) != 0) {
                        if ((col < row) || ((size - col) < row)) {
                            printf("1");
                        } else {
                            printf("0");
                        }
                    } else {
                        // If current column is even
                        printf("0");
                    }
                }
                col++;
            }
        } else if (row == squares) {
            while (col <= size) {
                if ((col % 2) != 0) {
                    printf("1");
                } else {
                    printf("0");
                };
                col++;
            }
        } else {
            // For printing each column
            while (col <= size) {

                // If the current row is odd
                if ((row % 2) != 0) {

                    // If the current column is odd
                    if ((col % 2) != 0) {
                        printf("1");
                    } else {
                        // If the current column is even
                        if ((col > row) || ((size - col) >= row)) {
                            printf("0");
                        } else {
                            printf("1");
                        }
                    }
                } else {
                    // If the current row is even

                    // If the current column is odd
                    if ((col % 2) != 0) {
                        if ((col > row) || ((size - col) >= row)) {
                            printf("1");
                        } else {
                            printf("0");
                        }
                    } else {
                        // If the current column is even
                        printf("0");
                    }
                }
                col++;
            }
        }

        printf("\n");
        row++;
    }

    return 0;

}

