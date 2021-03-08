//Lab03 - Ordering Three Integers
//Rifa Jamal z5311190
//2/03/2020


#include <stdio.h>

int main(void) {

    int numberOne;
    int numberTwo;
    int numberThree;

    //User will enter first integer

    printf ("Enter integer: ");
    scanf ("%d", &numberOne);

    //User will enter second integer

    printf ("Enter integer: ");
    scanf ("%d", &numberTwo);

    //User will enter thr integer

    printf ("Enter integer: ");
    scanf ("%d", &numberThree);

    if (numberOne <= numberTwo && numberTwo <= numberThree) {
        printf("The integers in order are: %d %d %d\n", numberOne, numberTwo, 
            numberThree);
  
    } else if (numberOne <= numberThree && numberThree <= numberTwo) {
        printf("The integers in order are: %d %d %d\n", numberOne, numberThree, 
            numberTwo);

    } else if (numberTwo <= numberOne && numberOne <= numberThree) {
        printf("The integers in order are: %d %d %d\n", numberTwo, numberOne, 
            numberThree);

    } else if (numberTwo <= numberThree && numberThree <= numberOne) {
        printf("The integers in order are: %d %d %d\n", numberTwo, numberThree, 
            numberOne);
    
    } else if (numberThree <= numberOne && numberOne <= numberTwo) {
        printf("The integers in order are: %d %d %d\n", numberThree, numberOne, 
            numberTwo);
    
    } else {
        printf("The integers in order are: %d %d %d\n", numberThree, numberTwo, 
            numberOne);
    }
    
    return 0;

}
