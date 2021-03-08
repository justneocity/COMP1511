// Assignment 2 20T1 COMP1511: CS bEats
// beats.c
//
// This program was written by Rifa Jamal (z5311190)
// Started on 16/04/2020
// Completed on 25/04/2020
//
// Version 1.0.0: Assignment released.
// Version 1.0.1: Fix default return value of add_musical_note_to_beat.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Add any extra #includes your code needs here.

#include "beats.h"

#include <string.h>

// Add your own #defines here.

#define MIN_OCTAVE 0
#define MAX_OCTAVE 9

#define MIN_KEY 0
#define MAX_KEY 11

////////////////////////////////////////////////////////////////////////

// You don't have to use the provided struct track, you are free to
// make your own struct instead.
// If you use the provided struct track, you will have to add fields
// to store other information.

struct track {
    struct beat *head;
    struct beat *selected_beat;
};

struct beat {
    struct note *notes;
    struct beat *next;
    struct note *last;
};

struct note {
    int octave;
    int key;
    struct note *next;
};

// Add any other structs you define here.

////////////////////////////////////////////////////////////////////////

// Add prototypes for any extra functions you create here.

////////////////////////////////////////////////////////////////////////

// Return a malloced Beat with fields initialized.
Beat create_beat(void) {
    Beat new_beat = malloc(sizeof (struct beat));
    assert(new_beat != NULL);

    new_beat->next = NULL;
    new_beat->notes = NULL;
    new_beat->last = NULL;

    return new_beat;
}

// You can find descriptions of what each function should do in beats.h

////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

// Add a note to the end of a beat.
int add_note_to_beat(Beat beat, int octave, int key) {

    //create a new node: new_note and a current pointer 
    //that traverses through the list
    struct note *new_note = malloc(sizeof(struct note));
    struct note *current;
 
    //allocate new note its octaves and keys that were inputted
    new_note->octave = octave;
    new_note->key = key;
    new_note->next = NULL;
    
    current = beat->notes;
    
    //check for invalid octave and invalid key   
    if (octave < MIN_OCTAVE || octave > MAX_OCTAVE) {
        return INVALID_OCTAVE;
    } else if (key < MIN_KEY || key > MAX_KEY) {
        return INVALID_KEY;
    } else {      
        //if list is empy add the first note
        if (current == NULL) {
            beat->notes = new_note;
        } else {
            //if list is not empty, traverse to end and add note
            while (current->next != NULL) {
                current = current->next;
            }  
            //check if lower note entered
            if (octave == current->octave && key == current->key) {
                return NOT_HIGHEST_NOTE;
            } else if (octave == current->octave && key < current->key) {
                return NOT_HIGHEST_NOTE;
            } else if (octave < current->octave) {
                return NOT_HIGHEST_NOTE;
            } else { 
                                         
                //add new note
                current->next = new_note;   
            } 
        }
        return VALID_NOTE;
    }
      
}

// Print the contents of a beat.
void print_beat(Beat beat) {

    if (beat->notes == NULL) {
        printf("\n");
    } else {
        struct note *new_note = beat->notes;
        while (new_note != NULL) {
            printf("%d %02d ", new_note->octave, new_note->key);
            new_note = new_note->next;   
            
            if (new_note != NULL) {
                printf ("| ");
            }
        }
        printf("\n");
    }
    return;
}

// Count the number of notes in a beat that are in a given octave.
int count_notes_in_octave(Beat beat, int octave) {

    struct note *head = beat->notes;
    struct note *current = NULL;
    
    //start check from the head note and traverse through beat
    current = head;
    
    int count = 0;
    while (current != NULL) {
        if (current->octave == octave) {
            count ++;
        }
        current = current->next;
    }

    return count;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

// Return a malloced track with fields initialized.
Track create_track(void) {
    // Note: there is no fprintf in this function, as the
    // Stage 1 autotests call create_track but expect it to return NULL
    // (so this function should do nothing in Stage 1).

    //Allocate memory to track
    Track track = malloc(sizeof(struct track));   
    assert(track != NULL);
    
    //Set head of linked list to be NULL, i.e. track is empty
    track->head = NULL;
    track->selected_beat = NULL;
    
    return track;
}

// Add a beat after the current beat in a track.
void add_beat_to_track(Track track, Beat beat) {
    
    //Case 1: there is no selected beat in track
    if (track->selected_beat == NULL) {
        //track beat is empty and has no selected beat
        if (track->head == NULL) {
            track->head = beat;   
        }
        //track has beats but no selected_beat
        else if (track->head != NULL) {
            beat->next = track->head;
            track->head = beat;
        } 
    } 
    //Case 2: track beat has a selected beat
    else if (track->selected_beat != NULL) {
        struct beat *current = track->head;
        while (current != track->selected_beat) {
            current = current->next;
        }
        beat->next = current->next;
        current->next = beat;  
    }    
     
    return;
}

// Set a track's current beat to the next beat.
int select_next_beat(Track track) {
    
    //If track is empty, set head to selected_beat
    if (track->selected_beat == NULL) {
        track->selected_beat = track->head;
        
        //If selected_beat is the last beat, track has stopped playing
    } else {
        track->selected_beat = track->selected_beat->next; 
    }
    
    //Check if there is a selected beat in track 
    //(and if it has not passed the last beat to NULL)
    if (track->selected_beat == NULL) {
        return TRACK_STOPPED;
    } else {
        return TRACK_PLAYING;
    }
    
}

// Print the contents of a track.
void print_track(Track track) {

    int count = 1;
    struct beat *new_beat = track->head;
    struct beat *selected = track->selected_beat;
    
    while (new_beat != NULL) {
   
        if (new_beat == selected) {
            printf (">[%d] ", count);
        } else {
            printf(" [%d] ", count);
        }
        
        //Go to print_beat function from stage 1 
        //to print beats in track
        print_beat(new_beat);
     
        new_beat = new_beat->next;
        count ++;
    }
  
    return;
}

// Count beats after the current beat in a track.
int count_beats_left_in_track(Track track) {

    struct beat *current = track->selected_beat;
    struct beat *tmp = track->head;

    int count = 0;
    //Traverse through list and check for number of beats
    if (current != NULL) {
        while (current->next != NULL) {
            current = current->next;
            count ++;      
        }
    } else {
        while (tmp != NULL) {  
            count ++;
            tmp = tmp->next;
        }
    }
    return count;
   
}

////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

// Free the memory of a beat, and any memory it points to.
void free_beat(Beat beat) {
    // Note: there is no printf in this function, as the
    // Stage 1 & 2 autotests call free_beat but don't check whether
    // the memory has been freed (so this function should do nothing in
    // Stage 1 & 2, rather than exit).
    
    struct note *current_note;
    current_note = beat->notes;
    struct note *remNode = NULL;
    
    while (current_note != NULL) {
        remNode = current_note;
        current_note = current_note->next;
        free(remNode);
    }
    free(beat);
        
    return;
}

// Free the memory of a track, and any memory it points to.
void free_track(Track track) {
    // Note: there is no printf in this function, as the
    // Stage 1 & 2 autotests call free_track but don't check whether
    // the memory has been freed (so this function should do nothing in
    // Stage 1 & 2, rather than print an error).
    
    struct beat *current_beat;
    current_beat = track->head;
    struct beat *remNode = NULL;
    
    while (current_beat != NULL) {
        remNode = current_beat;
        current_beat = current_beat->next;
        free_beat(remNode);
    }
    free(track);
}

// Remove the currently selected beat from a track.
int remove_selected_beat(Track track) {

    //previous pointer
    struct beat *prev = NULL; 
    //current pointer
    struct beat *curr = track->head;
    struct beat *remNode = track->selected_beat;
    
    int result;
    
    //Beat is already selected
    if (remNode != NULL) {
        //remNode at head
        if (remNode == track->head) {
            
            track->head = track->head->next;
            
            result = select_next_beat(track);
            free_beat(remNode);
            return result; 
                       
            //Selected beat at end of list    
        } else if (remNode->next == NULL) {
            while (curr->next != remNode) {
                prev = curr;
                curr = curr->next;
            }
            
            curr->next = NULL;
            track->selected_beat = NULL;
            free_beat(remNode);
            return TRACK_STOPPED;
            
            //Selected beat in middle    
        } else {
            while (curr != remNode) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            result = select_next_beat(track);
            free_beat(remNode);
            return result;     
        }
    } else {
        return TRACK_STOPPED; 
    }
      
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

// Add note to beat, given its 'musical notation'.
int add_musical_note_to_beat(Beat beat, char *musical_notation) {
    
    
    //create a new struct new note an current that traverses the list
    struct note *new_note = malloc(sizeof(struct note));
    struct note *current;
    
    //allocate new note its octaves and keys that were inputted
    new_note->octave = musical_notation[0];
    new_note->key = musical_notation[1];
    new_note->next = NULL;
    
    //set current to first note in beat
    current = beat->notes;
     
    //Use length to find how many # entered
    int length = strlen(musical_notation);
      
    //check for invalid octave and invalid key   
    if (new_note->octave < '0' || new_note->octave > '9') {
        free(new_note);
        return INVALID_MUSICAL_NOTE;
    } else if (new_note->key < 'A' || new_note->key > 'G') {
        free(new_note);
        return INVALID_MUSICAL_NOTE;
    } else {  
       
        int i = 2;
        while (i != strlen(musical_notation)) {
            if (musical_notation[i] != '#') {
                free(new_note);
                return INVALID_MUSICAL_NOTE;  
            }
            i++;
        }
        //Change ASCII value of octave to its actual number
        new_note->octave = new_note->octave - 48;
        
        //Change letters to keys based on its ASCII values
        if (new_note->key == 'A') {
            new_note->key = new_note->key - 65 + length - 2;
        } else if (new_note->key == 'B') {
            new_note->key = new_note->key - 64 + length - 2;
        } else if (new_note->key == 'C') {
            new_note->key = new_note->key - 64 + length - 2;
        } else if (new_note->key == 'D') {
            new_note->key = new_note->key - 63 + length - 2;
        } else if (new_note->key == 'E') {
            new_note->key = new_note->key - 62 + length - 2;
        } else if (new_note->key == 'F') {
            new_note->key = new_note->key - 62 + length - 2;
        } else if (new_note->key == 'G') {
            new_note->key = new_note->key - 61 + length - 2;
        } 
        
        //change octave and key based on # entered      
        while (new_note->key >= 12) {
            new_note->key = new_note->key - 12;
            new_note->octave = new_note->octave + 1;
        }

        //check if same note
        struct note * curr = beat->notes;
        while (curr != NULL) {
            if (new_note->octave == curr->octave 
            && new_note->key == curr->key) {
                free(new_note);
                return INVALID_MUSICAL_NOTE;    
            } 
            curr = curr->next;
        }
               
        //if list is empty add the first note
        if (beat->notes == NULL) {
            beat->notes = new_note;
            
            //list is not empty    
        } else {
            struct note *prev = NULL;
            
            //traverse until note is less then next note
            while (current != NULL
                && new_note->octave > current->octave) {
                prev = current;
                current = current->next;
            }   
    
            while (current != NULL
                && new_note->octave == current->octave
                && new_note->key > current->key) {
                prev = current;
                current = current->next;
            }
                    
            //only one note in beat
            if (prev == NULL) {
                new_note->next = beat->notes;
                beat->notes = new_note; 
                
                //2 notes in beat
            } else if (beat->notes->next == NULL) {
                struct note *p = beat->notes;
                p->next = new_note;
            
                //2+ notes in beat                        
            } else {               
                new_note->next = prev->next;
                prev->next = new_note;                
            }
        }
        
        return VALID_NOTE;     
        
    }
 
}

////////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                          //
////////////////////////////////////////////////////////////////////////

// Cut a range of beats to the end of a track.
void cut_range_to_end(Track track, int range_length) {
    
    //Range length should be >= 1 to have effect
    if (range_length < 1) {
        return;
    } else if (track->selected_beat != NULL && track->head != NULL) {
    
        //before selected is the beat before selected_beat
        struct beat *before_selected = track->head;
        
        //Before range is the last beat of the section I'm moving
        struct beat *before_range = track->selected_beat;  
        
        //After range is the beat after the last beat of the section 
        //that is being moved to the end
        //Before selected will link to after range
        struct beat *after_range = track->selected_beat;  
      
        //Traverse to node before range length
        int count = 0;
        while (before_range->next != NULL && count < (range_length - 1)) {
            before_range = before_range->next;
            count++;    
        }
        after_range = before_range->next;
      
        if (before_range->next == NULL) {
            //do nothing
        }
        //selected beat at head
        else if (before_selected == track->selected_beat) {
            struct beat *last = track->head;
            while (last->next != NULL) {
                last = last->next;
            }
            track->head = after_range;
            last->next = before_selected;
            
            before_range->next = NULL;
        
            //selected beat not at head             
        } else {
            //traverse before_selected so it is before the selected beat  
            while (before_selected->next != track->selected_beat) {
                before_selected = before_selected->next;
            }
            before_selected->next = after_range;
    
            struct beat *current_two = track->head;
            while (current_two->next != NULL) {
                current_two = current_two->next;
               
            }
            current_two->next = track->selected_beat;
            before_range->next = NULL;
                   
        }
    
    }  
    
}

// Reverse a list of beats within a range of a track.
int reverse_range(Track track, int range_length) {
    
    //Range length should be > 1 to have effect when reversing
    if (range_length <= 1) {
        return 0;
        //If no selected beat, reverse_range will have no effect
    } else if (range_length > 0 && track->selected_beat == NULL)  {
        return 0;
        //If selected_beat is the last beat, reverse_range will have no effect
    } else if (track->selected_beat->next == NULL && range_length > 0) {
        return 0;
        //selected_beat is not the last beat and list is not empty
    } else if (track->selected_beat != NULL && track->head != NULL) {
    
        struct beat *before_selected = track->head;
        struct beat *before_range = track->selected_beat;  
        struct beat *after_range = track->selected_beat;  
      
        //Traverse to node before range length
        int count = 0;
        while (before_range->next != NULL && count < (range_length - 1)) {
            before_range = before_range->next;
            count++;    
        }
        after_range = before_range->next;
      
        struct beat *current = track->selected_beat;
        struct beat *next = NULL;
        struct beat *prev = NULL;
        
        if (before_range->next == NULL || before_range == NULL) {
            //reverse all neats from selected to NULL
            
            while (current != NULL) {
         
                //save next
                next = current->next;
                //reverse
                current->next = prev;
                //traverse
                prev = current;
                current = next;    
            }
            
            if (before_selected == track->selected_beat) {
                track->head = before_range;
                before_range->next = before_selected;
                track->selected_beat->next = after_range;
            } else {
                while (before_selected->next != track->selected_beat) {
                    before_selected = before_selected->next; 
                }
                before_selected->next = prev;
                track->selected_beat->next = after_range;      
            }
            return count;
                
        }
        
        //selected beat at head
        else if (before_selected == track->selected_beat) {
            while (current != before_range) {
         
                //save next
                next = current->next;
                //reverse
                current->next = prev;
                //traverse
                prev = current;
                current = next;   
            }
            track->head = before_range;    
            track->head->next = prev; 
            track->selected_beat->next = after_range;

        } else {
            while (before_selected->next != track->selected_beat) {
                before_selected = before_selected->next;    
            }
            
            while (current != after_range) {
         
                //save next
                next = current->next;
                //reverse
                current->next = prev;
                //traverse
                prev = current;
                current = next;
                
            } 
            
            if (range_length < 3) {
                before_selected->next = before_range;
                before_range->next = track->selected_beat; 
                track->selected_beat->next = after_range;
            } else if (range_length >= 3) {
                before_selected->next = prev;
                track->selected_beat->next = after_range;     
            } 
                    
        }
        
    }  
  
    return (range_length - 1);
    
}
