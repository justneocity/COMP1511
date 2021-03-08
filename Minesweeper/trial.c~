//TRIAL


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

void initialise_field(int minefield[SIZE][SIZE]);
void print_debug_minefield(int minefield[SIZE][SIZE]);

// functions to detect number of mines in row or column
void detect_mines_row(int minefield[SIZE][SIZE]);
void detect_mines_column(int minefield[SIZE][SIZE]);

// Place your function prototyes here.

int main(void) {
    int minefield[SIZE][SIZE];
    initialise_field(minefield);
    
    int mines;
    
    //detect_mines_row(minefield);
    //detect_mines_column(minefield);
    
    
    // TODO: Scan in the number of pairs of mines.
    
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
        
        if (row < SIZE && column < SIZE) {
            minefield[row][column] = HIDDEN_MINE;
        }
        counter ++;
    
    }
    
    printf("Game Started\n");
    print_debug_minefield(minefield);  

    // TODO: Scan in commands to play the game until the game ends.
    // A game ends when the player wins, loses, or enters EOF (Ctrl+D).
    // You should display the minefield after each command has been process
    
    int row_or_column;
    //int loop = scanf("%d", &row_or_column);
    int loop_counter = 0;
    
    while (loop_counter < 2 && scanf("%d", &row_or_column)) {
        if (row_or_column == DETECT_ROW) {
            detect_mines_row(minefield);  
        } else if (row_or_column == DETECT_COL) {
            detect_mines_column(minefield);
        } print_debug_minefield(minefield);
        //loop = scanf("%d", &row_or_column);
     loop_counter ++;  
     }
    return 0;
        
}
void detect_mines_row(int minefield[SIZE][SIZE]) {
    
    //int number;
    //int row_number;
    
    //scanf("%d %d", &row_number, &number);
    //row_number = DETECT_ROW;
    
    int number;
    scanf("%d", &number);
    
    int i = 0;
    int mine = 0;
    while (i < SIZE) {
        if (minefield[number][i] == HIDDEN_MINE) {
        mine++;
        
        } 
        i++;
    } printf("There are %d mine(s) in row %d\n", mine, number);
    
    //initialise_field(minefield);
    //print_debug_minefield(minefield);
}   
    
void detect_mines_column(int minefield[SIZE][SIZE]) {
    
    //int numberTwo = 0;
    //int col_number;
    
    //scanf("%d %d", &col_number, &number);
    //col_number = DETECT_COL;
    
    int number;
    scanf("%d", &number);
    int j = 0;
    int mine = 0;
    while (j < SIZE) {
        if (minefield[number][j] == HIDDEN_MINE) {
        mine++;
        
        } 
        j++;
    } printf("There are %d mine(s) in column %d\n", mine, number);
    
    //initialise_field(minefield);
    //print_debug_minefield(minefield);
}       

//TRIAL FROM WED MARCH WK 6
void reveal_square(int minefield[SIZE][SIZE]) {

    int row;
    int column;
    
    scanf("%d %d", &row, &column);
    
    //check each separate square
    
    //case 1 = game over
    if (minefield[row][column] == HIDDEN_MINE) {
        printf("Game over");
        print_debug_minefield(minefield);
    } 
    
    int row_corner = row - 1;
    int col_corner = column - 1;
    //like a flag = remain 1 if dont encounter mine, 0 is encounter mine
    int visible = 1;
    
    //Case 1 = valid points (not on border)
    if (row_corner >= 0 && col_corner >= 0) {
        if (minefield[row_corner][col_corner] == HIDDEN_MINE) {
           visible = 0;
        } else if (minefield[row_corner][col_corner + 1] == HIDDEN_MINE) {
           visible = 0;
        } else if (minefield[row_corner][col_corner + 2] == HIDDEN_MINE) {
            visible = 0;
        } else if (minefield[row][column - 1] == HIDDEN_MINE) {
            visible = 0;
        } else if (minefield[row][column + 1] == HIDDEN_MINE) {
           visible = 0;
        } else if (minefield[row + 1][col_corner] == HIDDEN_MINE) {
           visible = 0;
        } else if (minefield[row + 1][column] == HIDDEN_MINE) {
           visible = 0;
        } else if(minefield[row + 1][column + 1] == HIDDEN_MINE) {
           visible = 0;
        }
      
        minefield[row][column] = VISIBLE_SAFE;    
    } 
    
    //case 2 = all boxes in square are visible safe
    if (row_corner >= 0 && col_corner >= 0) {
        if (minefield[row_corner][col_corner] == HIDDEN_SAFE) {
            minefield[row_corner][col_corner] = VISIBLE_SAFE; 
        } else if (minefield[row_corner][col_corner + 1] == HIDDEN_SAFE) {
            minefield[row_corner][col_corner + 1] = VISIBLE_SAFE;
        } else if (minefield[row_corner][col_corner + 2] == HIDDEN_SAFE) {
            minefield[row_corner][col_corner + 2] = VISIBLE_SAFE;
        } else if (minefield[row][column - 1] == HIDDEN_SAFE) {
            minefield[row][column - 1] = VISIBLE_SAFE;
        } else if (minefield[row][column + 1] == HIDDEN_SAFE) {
            minefield[row][column + 1] = VISIBLE_SAFE;
        } else if (minefield[row + 1][col_corner] == HIDDEN_SAFE) {
            minefield[row + 1][col_corner] = VISIBLE_SAFE; 
        } else if (minefield[row + 1][column] == HIDDEN_SAFE) {
            minefield[row + 1][column] = VISIBLE_SAFE;
        } else if(minefield[row + 1][column + 1] == HIDDEN_SAFE) {
            minefield[row + 1][column + 1] = VISIBLE_SAFE;
        }
        
        minefield[row][column] = VISIBLE_SAFE;
        
    } 
    
    //Case 3 = if on edge i.e. row_corner == 0 && col_corner == 0
    //is it done in above if??
}   
    //Case 4 - win game   
 
 // prev trialroy
 /* 
    int row_corner = row - 1;
    int col_corner = col - 1;
    int mine_counter = 0;
   
    if (row >= 1 && column >= 1 && row <= 6 && column <= 6) {
    
        
        if (minefield[row][column] == HIDDEN_MINE) {
            printf("Game over");
            print_debug_minefield(minefield);
            
        } else if (minefield[row - 1][column - 1] == HIDDEN_MINE || minefield[row - 1][column] == HIDDEN_MINE || minefield[row - 1][column + 1] == HIDDEN_MINE || minefield[row][column - 1] == HIDDEN_MINE || minefield[row][column + 1] == HIDDEN_MINE || minefield[row + 1][column - 1] == HIDDEN_MINE || minefield[row + 1][column] == HIDDEN_MINE || minefield[row + 1][column + 1] == HIDDEN_MINE) {
        
        minefield[row][column] = VISIBLE_SAFE;
        
        } else {
            minefield[row - 1][column - 1] = VISIBLE_SAFE;
            minefield[row - 1][column] = VISIBLE_SAFE;
            minefield[row - 1][column + 1] = VISIBLE_SAFE;
            minefield[row][column - 1] = VISIBLE_SAFE;
            minefield[row][column] = VISIBLE_SAFE;
            minefield[row][column + 1] = VISIBLE_SAFE;
            minefield[row + 1][column - 1] = VISIBLE_SAFE;
            minefield[row + 1][column] = VISIBLE_SAFE;
            minefield[row + 1][column + 1] = VISIBLE_SAFE;
        }
    //check first row
    } else if (row == 0) {
        if (minefield[row][column] == HIDDEN_MINE) {
            printf("Game over");
            print_debug_minefield(minefield); 
        } else if (minefield[row + 1][column] ==
    
    
    int row_counter = 0;
    while (row_counter < 3) {
        
            int col_counter;
            while (col_counter < 3) { 
            if (minefield[row_corner + row_counter]
                    [col_corner + col_counter] == 2) {
            mine_counter++;
            }      
            col_counter++;
            }
    row_counter++;
    }  
        
    if (minefield[row][column] == HIDDEN_MINE) {
        printf("Game Over")
        print_debug_minefield(minefield);
    } else if (minefield[row_corner + row_counter]
            [col_corner + col_counter] == HIDDEN_MINE) {
        minefield[row][column] == VISIBLE SAFE
    } else if (minefield[row_corner + row_counter]
            [col_corner + col_counter] == VISIBLE_SAFE) {
        minefield[row_corner + row_counter]
            [col_corner + col_counter] == VISIBLE_SAFE
    
    
    
    int i;
    int mine;
    
    
    while (i < SIZE) {
        if (minefield[i][mine] == HIDDEN_MINE) {
            mine++;
        printf("Game Over");
        } else if (detect_squares(minefield) == 1) {
            print_debug_minefield(minefield);
        } else if (detect_squares(minefield) == 0) {
            print_debug_minefield(minefield);
        } 
        i++;
    }

}
*/ 
/*
    //CORNERS
    else if (row == 0||row == SIZE - 1||col == 0||col == SIZE - 1){
        if(row == 0 && col == 0) { //top left corner
            //check for Hidden Mines
            if (minefield[row][col+1] == HIDDEN_MINE) {
                minefield[row][col]=VISIBLE_SAFE;
            } else if (minefield[row+1][col] == HIDDEN_MINE) {
                minefield[row][col]=VISIBLE_SAFE;
            } else if (minefield[row+1][col+1] == HIDDEN_MINE) {
                minefield[row][col]=VISIBLE_SAFE;
            }
        } else if (row == SIZE-1 && col==0) { //bottom left
            if (minefield[row-1][col] == HIDDEN_MINE) {
                minefield[row][col]=VISIBLE_SAFE;
            } else if (minefield[row-1][col+1] == HIDDEN_MINE) {
                minefield[row][col]=VISIBLE_SAFE;
            } else if (minefield[row][col + 1] == HIDDEN_MINE) {
                minefield[row][col]=VISIBLE_SAFE;
            }
        } else if (row==0 && col== SIZE-1) { //top right
            if (minefield[row][col-1] == HIDDEN_MINE) {
                minefield[row][col]=VISIBLE_SAFE;
            } else if (minefield[row+1][col-1] == HIDDEN_MINE) {
                minefield[row][col]=VISIBLE_SAFE;
            } else if (minefield[row+1][col] == HIDDEN_MINE) {
                minefield[row][col]=VISIBLE_SAFE;
            }
        } else if (row==SIZE-1 && col==SIZE-1){ //bottom right
            if (minefield[row-1][col] == HIDDEN_MINE) {
                minefield[row][col]=VISIBLE_SAFE;
            } else if (minefield[row][col-1] == HIDDEN_MINE) {
                minefield[row][col]=VISIBLE_SAFE;
            } else if (minefield[row-1][col-1] == HIDDEN_MINE) {
                minefield[row][col]=VISIBLE_SAFE;
            }
        }
    }

    //Check of non-edges
    else if (minefield[row-1][col-1] == HIDDEN_MINE) {
        minefield[row][col]=VISIBLE_SAFE;
    } else if (minefield[row-1][col] == HIDDEN_MINE) {
        minefield[row][col]=VISIBLE_SAFE;
    } else if (minefield[row-1][col+1] == HIDDEN_MINE) {
        minefield[row][col]=VISIBLE_SAFE;
    } else if (minefield[row][col-1] == HIDDEN_MINE) {
        minefield[row][col]=VISIBLE_SAFE;
    } else if (minefield[row][col+1] == HIDDEN_MINE) {
        minefield[row][col]=VISIBLE_SAFE;
    } else if (minefield[row+1][col-1] == HIDDEN_MINE) {
        minefield[row][col]=VISIBLE_SAFE;
    } else if (minefield[row+1][col] == HIDDEN_MINE) {
        minefield[row][col]=VISIBLE_SAFE;
    } else if (minefield[row+1][col+1] == HIDDEN_MINE) {
        minefield[row][col]=VISIBLE_SAFE;
    }
    //if no hidden Mines exist adjacent 3x3 all adjacent blocks will be visible
    else {
    minefield[row-1][col-1]=VISIBLE_SAFE;
    minefield[row-1][col]=VISIBLE_SAFE;
    minefield[row-1][col+1]=VISIBLE_SAFE;
    minefield[row][col-1]=VISIBLE_SAFE;
    minefield[row][col]=VISIBLE_SAFE;
    minefield[row][col+1]=VISIBLE_SAFE;
    minefield[row+1][col-1]=VISIBLE_SAFE;
    minefield[row+1][col]=VISIBLE_SAFE;
    minefield[row+1][col+1]=VISIBLE_SAFE;

    }
    //print_debug_minefield(minefield);
} */  
    void initialise_field(int minefield[SIZE][SIZE]) {
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

// Print out the actual values of the minefield.
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

/*

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

void initialise_field(int minefield[SIZE][SIZE]);
void print_debug_minefield(int minefield[SIZE][SIZE]);

// functions to detect number of mines in row or column
void detect_mines_row(int minefield[SIZE][SIZE], int number);
void detect_mines_column(int minefield[SIZE][SIZE], int number);

// Place your function prototyes here.

int main(void) {
    int minefield[SIZE][SIZE];
    initialise_field(minefield);
    
    int mines;
    
    //detect_mines_row(minefield);
    //detect_mines_column(minefield);
    
    
    // TODO: Scan in the number of pairs of mines.
    
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
        
        if (row < SIZE && column < SIZE) {
            minefield[row][column] = HIDDEN_MINE;
        }
        counter ++;
    
    }
    
    printf("Game Started\n");
    print_debug_minefield(minefield);  

    // TODO: Scan in commands to play the game until the game ends.
    // A game ends when the player wins, loses, or enters EOF (Ctrl+D).
    // You should display the minefield after each command has been process
    
    int row_or_column;
    int number;
    int loop = scanf("%d %d", &row_or_column, &number);
    
    while (loop == 1) {
        if (row_or_column == DETECT_ROW) {
            detect_mines_row(minefield, number);  
        } else if (row_or_column == DETECT_COL) {
            detect_mines_column(minefield, number);
        } 
        
       // print_debug_minefield(minefield);   
   }  
    
}
void detect_mines_row(int minefield[SIZE][SIZE], int number) {
    
    //int number;
    //int row_number;
    
    //scanf("%d %d", &row_number, &number);
    //row_number = DETECT_ROW;
    
    int i = 0;
    int mine = 0;
    while (i < SIZE) {
        if (minefield[number][i] == HIDDEN_MINE) {
        mine++;
        
        } 
        i++;
    } printf("There are %d mine(s) in row %d\n", mine, number);
    
    initialise_field(minefield);
    print_debug_minefield(minefield);
}   
    
void detect_mines_column(int minefield[SIZE][SIZE], int number) {
    
    //int numberTwo = 0;
    //int col_number;
    
    //scanf("%d %d", &col_number, &number);
    //col_number = DETECT_COL;
    
    int j = 0;
    int mine = 0;
    while (j < SIZE) {
        if (minefield[number][j] == HIDDEN_MINE) {
        mine++;
        
        } 
        j++;
    } printf("There are %d mine(s) in column %d\n", mine, number);
    
    initialise_field(minefield);
    print_debug_minefield(minefield);
}       
    










    
   int loopcounter = 0;
    int row_or_column = 0;
    int rc_number = 0; //row or column number
    
    int mine = 0;
    
    
    
    while (loopcounter <= SIZE) {
        scanf("%d %d", &row_or_column, &rc_number);
        //detects if row or column input
        if (row_or_column == DETECT_ROW) {
            int i_row = 0; //row increment
            while (i_row < SIZE) {
                if(minefield[rc_number][i_row] == HIDDEN_MINE) {
                mine ++;
                }
            i_row++;
            printf("There are %d mine(s) in row %d\n", i_row, rc_number);
            }
        } else if (row_or_column == DETECT_COL) {
            int i_col = 0; //column increment
            while (i_col < SIZE) {
                if(minefield[rc_number][i_col] == HIDDEN_MINE) {
                mine ++;
                }
                i_col++;
                printf("There are %d mine(s) in column %d\n", i_col, rc_number);
                }
        }
    loopcounter++;
    }
    
   new while (loopcounter <= SIZE) {
        scanf("%d %d", &row_or_column, &rc_number);
        //detects if row or column input
        if (row_or_column == DETECT_ROW) {
            //int i_row = 0; //row increment
            while (i < SIZE) {
                if(minefield[i][rc_number] == HIDDEN_MINE) {
                i++;
                }
            //i_row++;
            printf("There are %d mine(s) in row %d\n", i, rc_number);
            }
        } else if (row_or_column == DETECT_COL) {
           // int i_col = 0; //column increment
            while (i < SIZE) {
                if(minefield[i][rc_number] == HIDDEN_MINE) {
                j++;
                }
                //j_col++;
                printf("There are %d mine(s) in column %d\n", i, rc_number);
                }
        }
    rc_number++;
    } 
    
  //  return 0;
//}

// Set the entire minefield to HIDDEN_SAFE.
void initialise_field(int minefield[SIZE][SIZE]) {
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

// Print out the actual values of the minefield.
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
}*/




