//lecture 3 comp1511

#include <stdio.h>

#define SECRET_NUMBER 7
#define MIN_VALUE 1
#define MAX_VALUE 20

int main(void) {
    int dieOne = -1;
    int dieTwo = -1;
    
    // scan in die values from user
    printf("Please type in the value of die one: ");
    scanf("%d", &dieOne);  
    
    //check inut for correct dice values
  if (MIN_VALUE <= dieOne && dieOne <= MAX_VALUE) {
    printf("Roll is valid.\n");
  }else {
  dieOne = (dieOne % MAX_VALUE);
   if (dieOne == 0) {
       dieOne = MAX_VALUE;
    }
    printf("Corrected invalid value to %d.\n", dieOne);
  
  
 /*   printf(
        "Roll of first die, %d was not between %d and %d. Program will exit now.\n",
    dieOne, MIN_VALUE, MAX_VALUE
    );
    //end program here
    return 1; */
  }
      
    printf("Please type in the value of die two: ");
    scanf("%d", &dieTwo);
  
  
 
    
    
    
    // calculate and report total
    int total = dieOne + dieTwo;
    printf("You rolled: %d total.\n", total);
    
    // Test against secret target
    if (total >= SECRET_NUMBER) { // target met
        printf("Roll was successful.\n");
    } else { // total less than SECRET_NUMBER
        printf("Roll was a failure.\n");
    }

    return 0;
}
