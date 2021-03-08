//Weekly test Week 4
//Rifa Jamal z5311190
//18/03/2020


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
        printf("Middle: %d\n", numberTwo);
  
    } else if (numberOne <= numberThree && numberThree <= numberTwo) {
        printf("Middle: %d\n", numberThree);

    } else if (numberTwo <= numberOne && numberOne <= numberThree) {
        printf("Middle: %d\n", numberOne);

    } else if (numberTwo <= numberThree && numberThree <= numberOne) {
        printf("Middle: %d\n", numberThree);
    
    } else if (numberThree <= numberOne && numberOne <= numberTwo) {
        printf("Middle: %d\n", numberOne);
    
    } else {
        printf("Middle: %d\n", numberTwo);
    }
    
    return 0;

}
