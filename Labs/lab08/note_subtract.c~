//Substract notes
// This program was written by Rifa Jamal (z5311190)
// on 11/03/2020

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// A struct note * IS a Note
typedef struct note *Note;

//There are 10 octaves (0 to 9) and 12 notes (0 to 11)
struct note {
    int octave;
    int key;
    Note next;
};

Note note_subtract(Note higher, Note lower);
void print_note(Note n);

int main(void) {
    int octave, key;
    scanf("%d %d", &octave, &key);
    // NOTE: the {octave, key, NULL} syntax is short for
    // a.octave = octave; a.key = key; a.next = NULL;
    struct note a = {octave, key, NULL};
    scanf("%d %d", &octave, &key);
    struct note b = {octave, key, NULL};
    Note diff = note_subtract(&a, &b);
    print_note(diff);
    free(diff);
    return 0;
}

// For a note with octave 0, and note 9,
// `print_note` should print:
// "0 09\n"
void print_note(Note new) {

    printf("%d %02d\n", new->octave, new->key);
    //02d makes it to 2 decimal places whereas
    //036 will do 3 dp i.e. 011
    
    /*
     if (n->key <= 9) {
        printf("%d 0%d\n", n->octave, n->key);
    } else if (n->key > 9) {
        printf("%d %d\n", n->octave, n->key);
    }
    */
    
}



//Returns a pointer to a malloced struct containing the difference between a 
//higher and a lower note

Note note_subtract(Note higher, Note lower) {
   
    //allocating struct note memory into *new
    Note new = malloc(sizeof(Note));
    
    new->octave = higher->octave - lower->octave;
    new->key = higher->key - lower->key;
    
    if (new->key < 0) {
        new->key = new->key + 12;
        new->octave = new->octave - 1; 
    }
    
    return new;

}
    
    
    
    
    
    
    
    
    
    /*
    //difference = (struct note *)malloc(sizeof(struct note));
    int *difference = malloc(sizeof(int));
    
    //struct noe *difference = malloc(sizeof(struct node));
    int higher;
    int lower;
    
    //subtract octaves
    if (a->octave > b->octave) {
        higher = a->octave;
        lower = b->octave;
        difference->(higher - lower);
        
    } else if (a->octave < b->octave) {
        higher = b->octave;
        lower = a->octave;
        difference->(higher - lower);  
    }
    
    //subtract keys
    if (a->key > b->key) {
        higher = a->key;
        lower = b->key;
        difference->(higher - lower);
        
        if (difference->key < 0) {
        difference->key = higher + (12 - lower);
        difference->octave--;
        }
    } else if (a->key < b->key) {
        higher = b->key;
        lower = a->key;
        difference->(higher - lower);
        
        if (difference->key < 0) {
        difference->key = higher + (12 - lower);
        difference->octave--;
        }
    }
    
    return difference;

}*/
