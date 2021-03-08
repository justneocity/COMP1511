// Assignment 2 20T1 COMP1511: CS bEats
// test_beats.c
//
// This program was written by Rifa Jamal (z5311190)
// Completed with style check on 26/04/2020
//
// Version 1.0.0: Assignment released.
#include <stdio.h>
#include <stdlib.h>

#include "test_beats.h"
#include "beats.h"


// Test function for `add_note_to_beat`
int test_add_note_to_beat(void) {

    // Test 1: Rejecting negative inputs.
    Beat test_beat = create_beat();
    if (add_note_to_beat(test_beat, -1, -1) != INVALID_OCTAVE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_note_to_beat(test_beat, -1, 0) != INVALID_OCTAVE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_note_to_beat(test_beat, 1, -1) != INVALID_KEY) {
        return DOES_NOT_MEET_SPEC;
    }

    // Test 2: Rejecting inputs out of boundary for octave and key
    if (add_note_to_beat(test_beat, 10, 1) != INVALID_OCTAVE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_note_to_beat(test_beat, 9, 12) != INVALID_KEY) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_note_to_beat(test_beat, 12, 15) != INVALID_OCTAVE) {
        return DOES_NOT_MEET_SPEC;
    }

    // Test 3: Test for note added after previous note
    //check for same note added
    (add_note_to_beat(test_beat, 3, 4));
    if (add_note_to_beat(test_beat, 3, 4) != NOT_HIGHEST_NOTE) {
        return DOES_NOT_MEET_SPEC;
    }
    
    (add_note_to_beat(test_beat, 5, 5));
    if (add_note_to_beat(test_beat, 5, 5) != NOT_HIGHEST_NOTE) {
        return DOES_NOT_MEET_SPEC;
    }
    
    return MEETS_SPEC;
     
}       

// Test function for `count_notes_in_octave`
int test_count_notes_in_octave(void) {

    // Test 1: Counting invalid octaves.
    Beat test_beat = create_beat();
    add_note_to_beat(test_beat, 1, 1);
    if (count_notes_in_octave(test_beat, -1) != 0) {
        return DOES_NOT_MEET_SPEC;
    }
    if (count_notes_in_octave(test_beat, 11) != 0) {
        return DOES_NOT_MEET_SPEC;
    }

    // Test 2: Test in count octave produces right number of notes
    add_note_to_beat(test_beat, 1, 1);
    add_note_to_beat(test_beat, 1, 2);
    add_note_to_beat(test_beat, 2, 1);
    
    if (count_notes_in_octave(test_beat, 3) != 0) {
        return DOES_NOT_MEET_SPEC;
    }
    if (count_notes_in_octave(test_beat, 2) != 1) {
        return DOES_NOT_MEET_SPEC;
    }

    // Test 3: No notes in beat
    
    //create a new beat and don't add any notes
    test_beat = create_beat();
    
    if (count_notes_in_octave(test_beat, 1) != 0) {
        return DOES_NOT_MEET_SPEC;
    }
    if (count_notes_in_octave(test_beat, 5) != 0) {
        return DOES_NOT_MEET_SPEC;
    }
    
    return MEETS_SPEC;
}

// Test function for `add_beat_to_track`
int test_add_beat_to_track(void){
    
    // Test 1: Track contains no beats and beat added later
    //create track and create beat
    
    Track test_track = create_track();
    Beat test_beat = create_beat();
    
    if (count_beats_left_in_track(test_track) != 0 ) {
        return DOES_NOT_MEET_SPEC;
    }
    
    //Added one beat
    test_beat = create_beat();
    add_beat_to_track(test_track, test_beat);
    
    if (count_beats_left_in_track(test_track) != 1 ) {
        return DOES_NOT_MEET_SPEC;
    }
    
    // Test 2: Selected beat is first and selected beat is last
    
    //create track and add beats
    test_track = create_track(); 
    test_beat = create_beat(); 
    add_beat_to_track(test_track, test_beat);
    select_next_beat(test_track);
    
    test_beat = create_beat();
    add_beat_to_track(test_track, test_beat);
    
    
    if (count_beats_left_in_track(test_track) != 1 ) {
        return DOES_NOT_MEET_SPEC;
    }
    
    select_next_beat(test_track);
    
    if (count_beats_left_in_track(test_track) != 0 ) {
        return DOES_NOT_MEET_SPEC;
    }
    
    // Test 3: Does add beat to track change currently selected beat?
    
    //create track and add beats
    test_track = create_track();
    test_beat = create_beat();
    add_beat_to_track(test_track, test_beat);
    select_next_beat(test_track);
    
    if (count_beats_left_in_track(test_track) != 0 ) {
        return DOES_NOT_MEET_SPEC;
    }
    
    test_beat = create_beat();
    add_beat_to_track(test_track, test_beat);
    
    if (count_beats_left_in_track(test_track) != 1 ) {
        return DOES_NOT_MEET_SPEC;
    }
    
    return MEETS_SPEC;
}

// Test function for `remove_selected_beat`
int test_remove_selected_beat(void){
    
    // Test 1: Remove Selected Beat doesnt remove a beat 
    // Check if the beat after selected_beat reduces by one
    
    Track test_track = create_track();
    Beat test_beat = create_beat();

    add_beat_to_track(test_track, test_beat);
    
    test_beat = create_beat();
    add_beat_to_track(test_track, test_beat);
    
    test_beat = create_beat();
    add_beat_to_track(test_track, test_beat);
    
    select_next_beat(test_track);
    
    remove_selected_beat(test_track);
    
    if (count_beats_left_in_track(test_track) != 1 ) {
        return DOES_NOT_MEET_SPEC;
    }
    
    select_next_beat(test_track);
    remove_selected_beat(test_track);
    
    if (count_beats_left_in_track(test_track) != 1 ) {
        return DOES_NOT_MEET_SPEC;
    }
    
   
    // Test 2: Check if remove selected beat works the same for 
    // first and last beat removed from track
    
    test_track = create_track();
    
    test_beat = create_beat();
    add_beat_to_track(test_track, test_beat);
    test_beat = create_beat();
    add_beat_to_track(test_track, test_beat);
    test_beat = create_beat();
    add_beat_to_track(test_track, test_beat);
    
    select_next_beat(test_track);
    remove_selected_beat(test_track);
  
    if (count_beats_left_in_track(test_track) != 1 ) {
        return DOES_NOT_MEET_SPEC;
    }
    
    select_next_beat(test_track);
    remove_selected_beat(test_track);
    
    if (count_beats_left_in_track(test_track) != 1 ) {
        return DOES_NOT_MEET_SPEC;
    }

    // Test 3: Check is remove_selected_beat does not remove multiple beats
    
    test_track = create_track();
    
    test_beat = create_beat();
    add_beat_to_track(test_track, test_beat);
    test_beat = create_beat();
    add_beat_to_track(test_track, test_beat);
    test_beat = create_beat();
    add_beat_to_track(test_track, test_beat);
    test_beat = create_beat();
    add_beat_to_track(test_track, test_beat);
    
    select_next_beat(test_track);
    select_next_beat(test_track);
    remove_selected_beat(test_track);
  
    if (count_beats_left_in_track(test_track) != 1 ) {
        return DOES_NOT_MEET_SPEC;
    }
    
    select_next_beat(test_track);
    remove_selected_beat(test_track);
    
    if (count_beats_left_in_track(test_track) != 2) {
        return DOES_NOT_MEET_SPEC;
    }
    
    return MEETS_SPEC;
}

// Test function for `add_musical_note_to_beat`
int test_add_musical_note_to_beat(void){
    
    // Test 1: Check is add_musical_note recognises a valid note
    
    Beat test_beat = create_beat();
    if (add_musical_note_to_beat(test_beat, "3G") != VALID_NOTE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_musical_note_to_beat(test_beat, "4B#") != VALID_NOTE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_musical_note_to_beat(test_beat, "1A######") != VALID_NOTE) {
        return DOES_NOT_MEET_SPEC;
    }

    // Test 2: Check is add_musical_note rejects an invalid note
    
    if (add_musical_note_to_beat(test_beat, "-1A") != INVALID_MUSICAL_NOTE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_musical_note_to_beat(test_beat, "12G") != INVALID_MUSICAL_NOTE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_musical_note_to_beat(test_beat, "1A%#%") != INVALID_MUSICAL_NOTE) {
        return DOES_NOT_MEET_SPEC;
    }
    
    // Test 3: Check if add_musical_note (using command 'm') 
    //correctly adds a note to the beat while also 
    //adding notes using command 'a'    
    
    add_musical_note_to_beat(test_beat, "1G");
    
    if (count_notes_in_octave(test_beat, 1) != 1) {
        return DOES_NOT_MEET_SPEC;
    }
    if (count_notes_in_octave(test_beat, 2) != 0) {
        return DOES_NOT_MEET_SPEC;
    }
    
    add_note_to_beat(test_beat, 1, 1);
    add_musical_note_to_beat(test_beat, "1F");
    
    if (count_notes_in_octave(test_beat, 1) != 3) {
        return DOES_NOT_MEET_SPEC;
    }
    
    return MEETS_SPEC;
}
