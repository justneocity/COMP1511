//Dice Stat
//Rifa Jamal 26/02

//This will show all possible rolls of two dice and report the odds of rolling a particular number

#include <stdio.h>

int main (void) {
    int diceOneSize = 0;
    int diceTwoSize = 0;
    int target = 0;
    int numRolls = 0;
    double numSuccesses = 0;
    
    
    // User decides the two dice sizes
    printf("Please enter the size of the first die: ");
    scanf("%d", &diceOneSize);
    printf("Please enter the size of the second die: ");
    scanf("%d", &diceTwoSize);
    printf("Please type in the target value: ");
    scanf("%d", &target);
    // Then loop through all possible roll outcomes and printf
    int counterOne = 1;
    while (counterOne <= diceOneSize) {
        //printf("counterOne = %d\n", counterOne);
        int counterTwo = 1;
        while (counterTwo <= diceTwoSize) {
            numRolls++;
            int total = counterOne + counterTwo;
            if (total == target){
                numSuccesses++;
                printf (" %d + %d = %d\n", counterOne, counterTwo, total);
            }
           
            counterTwo++;
    }
    counterOne++;
}

    printf("We rolled %d %f times out of %d total rolls.\n", target, numSuccesses, numRolls
    );
    double percentage = numSuccesses/(numRolls * 1.0) * 100;
    printf ("Success chance is %lf percentage.\n", percentage);
    return 0;
}
