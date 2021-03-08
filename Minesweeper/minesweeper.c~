// Assignment 1 20T1 COMP1511: Minesweeper
// minesweeper.c
//
// This program was written by RIFA JAMAL (z5311190)
// Completed on 29/03/2020
//

#include <stdio.h>
#include <stdlib.h>

// Possible square states.
#define VISIBLE_SAFE    0
#define HIDDEN_SAFE     1
#define HIDDEN_MINE     2

// The size of the starting grid.
#define SIZE 8

// The possible command codes.
#define DETECT_ROW              1
#define DETECT_COL              2
#define DETECT_SQUARE           3
#define REVEAL_SQUARE           4
#define GAMEPLAY_MODE           5
#define DEBUG_MODE              6
#define REVEAL_RADIAL           7

// Add any extra #defines here.
#define TRUE                    1
#define FALSE                   0

//Reveal Radial Directions
#define NORTH                   0
#define NORTH_EAST              1
#define EAST                    2
#define SOUTH_EAST              3
#define SOUTH                   4
#define SOUTH_WEST              5
#define WEST                    6
#define NORTH_WEST              7

#define END                     8

void initialise_field(int minefield[SIZE][SIZE]);
void print_debug_minefield(int minefield[SIZE][SIZE]);

// Stage 1 functions to detect number of mines in row or column
void detect_mines_row(int minefield[SIZE][SIZE], int *hints);
void detect_mines_column(int minefield[SIZE][SIZE], int *hints);

//Stage 2 Functions
void detect_squares(int minefield[SIZE][SIZE], int *hints);
void reveal_square(int minefield[SIZE][SIZE], int *gameover, 
                    int mines, int *first_turn);
int check_win(int minefield[SIZE][SIZE], int mines);

//Stage 3 Functions
void print_gameplay_minefield(int minefield[SIZE][SIZE], int *gameover);
void check_mode(int minefield[SIZE][SIZE], int gameModeOn);
int detect_mines(int i, int j, int minefield[SIZE][SIZE]);
int end_point(int i);

//Stage 4 Functions
void reveal_radial(int minefield[SIZE][SIZE], int *gameover, int mines, 
                    int *first_turn);
int on_border (int row, int col);
void reveal_diagonal (int *row, int *col, int direction);
//Safe Turn
void safe_minefield(int minefield[SIZE][SIZE], int row, int col);  


// Place your function prototyes here.

int main(void) {
    int minefield[SIZE][SIZE];
    initialise_field(minefield);
    
    // TODO: Scan in the number of pairs of mines.
   
    int mines;
    printf("Welcome to minesweeper!\n");
    printf("How many mines? ");
    scanf("%d", &mines);
    
    // TODO: Scan in the pairs of mines and place them on the grid.
    
    int row = 0; 
    int column = 0;
    
    printf("Enter pairs:\n");
    
    int counter = 0;
    while (counter < mines) {
        scanf("%d %d", &row, &column);
        if (row >= 0 && row < SIZE 
            && column >= 0 && column < SIZE) {
            minefield[row][column] = HIDDEN_MINE;
        } counter ++;
    }
    
    printf("Game Started\n");
    print_debug_minefield(minefield);  
    

    // TODO: Scan in commands to play the game until the game ends.
    // A game ends when the player wins, loses, or enters EOF (Ctrl+D).
    // You should display the minefield after each command has been process
    
    int command;
    int gameover = 0; //Once game has ended, gameover becomes 1
    int hints = 0;
    int gameModeOn = FALSE; 
    int count = 0;
    int first_turn = 0;
    
    //While loop scans in first command, then moves into its relevant functions
    while (gameover == 0 && scanf("%d", &command) == 1) {
        
        //Check for first turn
        if (count == 0 && (command == REVEAL_SQUARE 
            || command == REVEAL_RADIAL)) {
            first_turn = TRUE;
        } else if (count != 0 && (command == REVEAL_SQUARE 
            || command == REVEAL_RADIAL)) {
            first_turn = FALSE;
        }
     
        if (command == DETECT_ROW) {
            detect_mines_row(minefield, &hints);  
        } else if (command == DETECT_COL) {
            detect_mines_column(minefield, &hints);
        } else if (command == DETECT_SQUARE) {
            detect_squares(minefield, &hints);
        } else if (command == REVEAL_SQUARE) {
            reveal_square(minefield, &gameover, mines, &first_turn);
        } else if (command == GAMEPLAY_MODE) {
            printf("Gameplay mode activated\n");
            gameModeOn = TRUE;
        } else if (command == DEBUG_MODE) {
            printf("Debug mode activated\n");
            gameModeOn = FALSE;     
        } else if (command == REVEAL_RADIAL) {
            reveal_radial(minefield, &gameover, mines, &first_turn);
        }
   
        //Print minefield - Gameplay or Debug Mode
        if (gameModeOn == TRUE) { //Gameplay mode
            print_gameplay_minefield(minefield, &gameover);
        } else if (gameModeOn == FALSE) { //Debug mode
            print_debug_minefield(minefield);
        }
        
        count++;
    }
    
    return 0;      
}

void detect_mines_row(int minefield[SIZE][SIZE], int *hints) {
    
    //Detect_mines_row is a hint to find number of mines in a row
    
    int number;
    scanf("%d", &number);
    
    int i = 0;
    int mine = 0;
    if (*hints >= 3) {
        printf("Help already used\n");
    } else {
        while (i < SIZE) {
            if (minefield[number][i] == HIDDEN_MINE) {
                mine++;
            } i++;
        } printf("There are %d mine(s) in row %d\n", mine, number);
        *hints = *hints + 1;   
    }
    
}   
    
void detect_mines_column(int minefield[SIZE][SIZE], int *hints) {
    
    //Detect_mines_column is a hint to find number of mines in a column.
    
    int number;
    scanf("%d", &number);
    int i = 0;
    int mine = 0;
    if (*hints >= 3) {
        printf("Help already used\n");
    } else {
        while (i < SIZE) {
            if (minefield[i][number] == HIDDEN_MINE) {
                mine++;
            } 
            i++;
        } printf("There are %d mine(s) in column %d\n", mine, number);
        *hints = *hints + 1;
    }
}
 
void detect_squares(int minefield[SIZE][SIZE], int *hints) {

    //Detect_squares is a hint to find number of mines in square
    //of variable size around a certain point(row,column)
    
    int row;
    int column;
    int size;
    scanf("%d %d %d", &row, &column, &size);
    
    //Formula for row and column corner in a square of any size
    int row_corner = row - ((size - 1)/2);
    int col_corner = column - ((size - 1)/2);
    int mine = 0;
    
    //Check for invalid points. They will increment if outside minefield.
    while (row_corner < 0) {
        row_corner++;
    } while (col_corner < 0) {
    } col_corner++;
    
    if (*hints >= 3) {
        printf("Help already used\n");
    } else {     
        while (row_corner <= (row + (size -1)/2 )) {
            col_corner = 0;
            while (col_corner <= (column + (size - 1)/2)) {
                if (minefield[row_corner][col_corner] == HIDDEN_MINE) {
                    mine++;
                }
                col_corner++;
                if (col_corner == 7) {
                    col_corner = col_corner + size;
                }
            } row_corner++;
            if (row_corner == 7) {
                row_corner = row_corner + size;
            }

        } 
        printf("There are %d mine(s) in the square centered at ", mine); 
        printf("row %d, column %d of size %d \n", row, column, size);
        
        *hints = *hints + 1;
    }

} 

int detect_mines(int i, int j, int minefield[SIZE][SIZE] ) {
   
    int row_corner = (i - 1);
    int col_corner = (j - 1);
    int mine = 0;
    
    if (row_corner < 0) {
        row_corner = 0;
    } 
    if (col_corner < 0) {
        col_corner = 0;
    }
    
    //Iterator refers to endpoint
    int row_interator = row_corner;
    if (i < 7 && j < 7) {
        while (row_interator <= i + 1) {
            int col_iterator = col_corner;
            while (col_iterator <= j + 1) {
                if (minefield[row_interator][col_iterator] == HIDDEN_MINE) {
                    mine++;
                } col_iterator++;
            } row_interator++;
        }
    } else if (i == 7 || j == 7) {
        while (row_interator <= i) {
            int col_iterator = col_corner;
            while (col_iterator <= j) {
                if (minefield[row_interator][col_iterator] == 
                    HIDDEN_MINE) {
                    mine++;
                } col_iterator++;
            } row_interator++;
        }
    
    }  
    return mine;   
}   
   
     
void reveal_square(int minefield[SIZE][SIZE], int *gameover, int mines, 
                    int *first_turn) {

    int row;
    int col;
   
    scanf("%d %d", &row, &col);
   
   /*
   Layout of square:
   ____________________________________________
   |  top left   |  top middle |    top right  |
   |  row - 1    |  row - 1    |     row - 1   |
   |  col - 1    |  col        |     col + 1   |
   |_____________|_____________|_______________|       
   | middle left |    CELL     |  middle right |
   |  row        | [row][col]  |    row        |
   |  col - 1    |             |    col + 1    |
   |_____________|_____________|_______________|  
   | bottom left |bottom middle| bottom right  |
   |   row + 1   |  row + 1    |     row + 1   |
   |   col - 1   |   col       |     col +1    |
   |_____________|_____________|_______________|               
    
   */
   
    //Check for first turn
    
    if (minefield[row][col] == HIDDEN_MINE && *first_turn == TRUE) {
        safe_minefield(minefield, row, col);
        *gameover = 0;
        
    } else if (minefield[row][col] == HIDDEN_MINE && *first_turn == FALSE) {
        printf("Game Over\n");
        *gameover = 1;
        return;
        
        //Check if any points in the square is a HIDDEN MINE
        // if true, then only reveal the middle cell [row][col]
        
    } else {
        int row_corner;
        int col_corner;
        int visible = 1;
        
        // Top left point
        row_corner = row - 1;
        col_corner = col - 1;
        if (row_corner >= 0 && col_corner >= 0) {
            if (minefield[row_corner][col_corner] == HIDDEN_MINE) {
                visible = 0;
            }
        }
        
        // Top middle point
        row_corner = row - 1;
        col_corner = col;
        if (row_corner >= 0 && col_corner >= 0) {
            if (minefield[row_corner][col_corner] == HIDDEN_MINE) {
                visible = 0;
            }
        }
        
        // Top right point
        row_corner = row - 1;
        col_corner = col + 1;
        if (row_corner >= 0 && col_corner <= 7) {
            if (minefield[row_corner][col_corner] == HIDDEN_MINE) {
                visible = 0;
            }
        }
        
        // Middle Left point
        row_corner = row;
        col_corner = col - 1;
        if (row_corner >= 0 && col_corner >= 0) {
            if (minefield[row_corner][col_corner] == HIDDEN_MINE) {
                visible = 0;
            }
        }

        // Middle right point
        row_corner = row;
        col_corner = col + 1;
        if (row_corner >= 0 && col_corner <= 7) {
            if (minefield[row_corner][col_corner] == HIDDEN_MINE) {
                visible = 0;
            }
        }        
        
        // Bottom left point
        row_corner = row + 1;
        col_corner = col - 1;
        if (row_corner <= 7 && col_corner >= 0) {
            if (minefield[row_corner][col_corner] == HIDDEN_MINE) {
                visible = 0;
            }
        }
        
        // Botton middle point
        row_corner = row + 1;
        col_corner = col;
        if (row_corner <= 7 && col_corner <= 7) {
            if (minefield[row_corner][col_corner] == HIDDEN_MINE) {
                visible = 0;
            }
        }
        
        // Bottom right point
        row_corner = row + 1;
        col_corner = col + 1;
        if (row_corner <= 7 && col_corner <= 7) {
            if (minefield[row_corner][col_corner] == HIDDEN_MINE) {
                visible = 0;
            }
        }
        
        // Otherwise if no points in square are a HIDDEN MINE
        // all points in square are revealed (visible = 1)
        
        minefield[row][col] = VISIBLE_SAFE;
        if (visible == 1) {
            
            // Top left point
            row_corner = row - 1;
            col_corner = col - 1;
            if (row_corner >= 0 && col_corner >= 0) {
                minefield[row_corner][col_corner] = VISIBLE_SAFE;
            }
        
            //Top middle point
            row_corner = row - 1;
            col_corner = col;
            if (row_corner >= 0 && col_corner >= 0) {
                minefield[row_corner][col_corner] = VISIBLE_SAFE;
            }
        
            //Top right point
            row_corner = row - 1;
            col_corner = col + 1;
            if (row_corner >= 0 && col_corner <= 7) {
                minefield[row_corner][col_corner] = VISIBLE_SAFE;
            }
        
            //Middel left point
            row_corner = row;
            col_corner = col - 1;
            if (row_corner >= 0 && col_corner >= 0) {
                minefield[row_corner][col_corner] = VISIBLE_SAFE;
            }

            //Middle right point
            row_corner = row;
            col_corner = col + 1;
            if (row_corner >= 0 && col_corner <= 7) {
                minefield[row_corner][col_corner] = VISIBLE_SAFE;
            }        
        
            //Bottom left point
            row_corner = row + 1;
            col_corner = col - 1;
            if (row_corner <= 7 && col_corner >= 0) {
                minefield[row_corner][col_corner] = VISIBLE_SAFE;
            }
        
            //Botton middle point
            row_corner = row + 1;
            col_corner = col;
            if (row_corner <= 7 && col_corner <= 7) {
                minefield[row_corner][col_corner] = VISIBLE_SAFE;
            }
        
            //Bottom right point
            row_corner = row + 1;
            col_corner = col + 1;
            if (row_corner <= 7 && col_corner <= 7) {
                minefield[row_corner][col_corner] = VISIBLE_SAFE;
            } 
        }  
    }
        
    //Check is game is won - go into check_win function
        
    if (check_win(minefield, mines) == 1) { //means game won
        printf("Game Won!\n");
        *gameover = 0;
    }
}       
      
int check_win(int minefield[SIZE][SIZE], int mines) {
    
    int i = 0;
    int j = 0;
    int count = 0;

    while (i < SIZE ) {
        j = 0;
        while (j < SIZE) {
            if (minefield[i][j] == VISIBLE_SAFE) {
                count++;
            } j++;
        }
        i++;
    }
    // If mines + VISIBLE_SAFE (count) = 64 (in 8*8 minefield)
    // then all valid points have been revealed and Game Won
    int sum;
    sum = count + mines;

    if (sum == 64) {
        return 1;
    }  
    return 0;
}

void reveal_radial(int minefield[SIZE][SIZE], int *gameover, int mines, 
                    int *first_turn) {

    int row;
    int col;
   
    scanf("%d %d", &row, &col);
   
    
    //Case 1 = Safe Turn case
    
    if (minefield[row][col] == HIDDEN_MINE && *first_turn == TRUE) {
        safe_minefield(minefield, row , col);
        *gameover = 0;
        
    } else if (minefield[row][col] == HIDDEN_MINE && *first_turn == FALSE) {
        printf("Game Over\n");
        *gameover = 1;
        return;
        //ends function without changing to VISIBLE_SAFE
     
    } 
        
    // Reveal Square around selected point
    int direction = 0; //this will determine if reveal_radial is still going
    int mines_radial = detect_mines(row, col, minefield);
    
    if (mines_radial > 0) {
        minefield[row][col] = VISIBLE_SAFE;
        direction = END;
    } else if (mines_radial == 0) {
        direction = NORTH; //start reveal 
    } 
    minefield[row][col] = VISIBLE_SAFE;

    //direction will increment from 0 - 7 
    //representing points on the compass
    while (direction != END) {
        int current_row = row;
        int current_column = col;
        int end = FALSE;
        //check to reveal further
        while (end == FALSE) { 
            //Check if coordinate on border in separate function
            end = on_border(current_row, current_column);
            //or continue of not on border
            if (end == FALSE) {
                //Change coordinates or row/col based on direction 
                reveal_diagonal(&current_row, &current_column, direction);
                end = on_border(current_row, current_column);
       
                int mine_radial = 
                    detect_mines(current_row, current_column, minefield);
                if (mine_radial > 0) {
                    end = TRUE;
                }
                minefield[current_row][current_column] = VISIBLE_SAFE;
            }
        }

        direction++;
    }

}   

    /* 
            Representation of direction
  
                N.W   N   N.E 
                   \  |   / 
                    \ |  /  
                W----Cell----E 
                    /  | \ 
                   /   |  \ 
                S.W    S   S.E 
  
            Cell-->Current Cell (row, col) 
            N -->  North        (row-1, col) 
            S -->  South        (row+1, col) 
            E -->  East         (row, col+1) 
            W -->  West         (row, col-1) 
            N.E--> North-East   (row-1, col+1) 
            N.W--> North-West   (row-1, col-1) 
            S.E--> South-East   (row+1, col+1) 
            S.W--> South-West   (row+1, col-1) 
    */       

//Change coordinates of row and column based on diagram above
void reveal_diagonal (int *row, int *col, int direction) {
    if (direction == NORTH) {
        *row = *row - 1;
    } else if (direction == NORTH_EAST) {
        *row = *row - 1;
        *col = *col + 1;
    } else if (direction == EAST) {
        *col = *col + 1;
    } else if (direction == SOUTH_EAST) {
        *row = *row + 1;
        *col = *col + 1;
    } else if (direction == SOUTH) {
        *row = *row + 1;
    } else if (direction == SOUTH_WEST) {
        *row = *row + 1;
        *col = *col - 1;
    } else if (direction == WEST) {
        *col = *col - 1;
    } else if (direction == NORTH_WEST) {
        *row = *row - 1;
        *col = *col - 1;
    } 
}

//Check if square/radial is on the border of minefield
int on_border (int row, int col) {
    int on_border = FALSE;
    if (row == 0 
    || row == SIZE - 1 
    || col == 0 
    || col == SIZE - 1) {
        on_border = TRUE;    
    }  

    return on_border;  
}


void safe_minefield(int minefield[SIZE][SIZE], int row, int col) {  

    //Find how many rows you need to move down
    
    int current_row = SIZE - 1;
    int shift_factor = 0;
    int counter = 0;
    while (minefield[row - counter][col] == HIDDEN_MINE) {
        shift_factor++;
        counter++;
    }
    
    //Shift the Hidden Mines down the column
    
    while (current_row >= 0) {
        int current_col = SIZE - 1;
        while (current_col >= 0) {
            if (minefield[current_row][current_col] == HIDDEN_MINE) {
                minefield[current_row + shift_factor][current_col] = 
                    HIDDEN_MINE;
                minefield[current_row][current_col] = HIDDEN_SAFE;   
            }
            current_col--;
        }
        current_row--;
    }
    minefield[row][col] = VISIBLE_SAFE;
    
}   
    
          
void initialise_field(int minefield[SIZE][SIZE] ) {
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            minefield[i][j] = HIDDEN_SAFE;
            j++;
        }
        i++;
    }
}

//Print out the actual values of the minefield.
void print_debug_minefield(int minefield[SIZE][SIZE]) {

   
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            printf("%d ", minefield[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    
}

//Print out gameplay mode

void print_gameplay_minefield(int minefield[SIZE][SIZE], int *gameover) {

    if (*gameover == 1) {
        printf("xx\n");
        printf("/\\\n");
       
    } else {
        printf("..\n");
        printf("\\/\n");
    }
   
    printf("    00 01 02 03 04 05 06 07\n");
    printf("   -------------------------\n");
   
    int i = 0; //row counter
    while (i < SIZE) {
        printf("0%d |", i);
       
        int j = 0; //column counter
        while (j < SIZE) {
            //Print mines in row
            if (minefield[i][j] == VISIBLE_SAFE) {
                int mines = detect_mines(i, j, minefield);
                //Print minefield;
                //blank for VISIBLE_SAFE, 0%d if there are adjacent mines
                if (mines == 0) {
                    printf("  ");
                } else {
                    printf("0%d", mines);
                }
               
                //If column on edge, print "|".
                //Else, print " " for gaps between each point
                if (j < SIZE - 1) {
                    printf(" ");
                } else {
                    printf("|\n");
                }
               
               
            } else {
                //If gameover - print () to display mines, else print ##
                if (*gameover == 1) {
                    if (minefield[i][j] == HIDDEN_MINE) {
                        printf("()");
                    } else {
                        printf("##");
                    }
                } else {
                    printf("##");
                }
               
                //If column on edge, print "|".
                //Else, print " " for gaps between each point
                if (j < SIZE - 1) {
                    printf(" ");
                } else {
                    printf("|\n");
                }
               
            }
            j++;
            
        }
        i++;
    }
   
    printf("   -------------------------\n");
}


