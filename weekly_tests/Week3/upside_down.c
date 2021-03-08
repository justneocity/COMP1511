//Weekly Test Week 3
//Rifa Jamal z5311190
// Date: 10/03/2020

#include <stdio.h>
int main(void) {

    double numberOne, numberTwo, numberThree;
    
    printf("Please enter three numbers: ");
    scanf("%lf %lf %lf", &numberOne, &numberTwo, &numberThree);
    
    if (numberOne > numberTwo && numberTwo > numberThree) {
        printf("down\n");
    } else if (numberOne < numberTwo && numberTwo < numberThree) {
        printf("up\n");
    } else {
        printf("neither\n");
    }
      
    return 0;
    
}
