//Weekly Test Week 3
//Rifa Jamal z5311190
// Date: 10/03/2020

#include <stdio.h>

int main(void) {

    int numberOne;
    int numberTwo;
    
    //printf("\n");
    scanf("%d %d", &numberOne,
     &numberTwo);
    
    int multiply = numberOne * numberTwo;
    int positive = multiply * -1;
    
    if (multiply > 0) {
        printf("%d\n", multiply);
    } else if (multiply < 0) {
        printf("%d\n", positive);
    } else if (multiply == 0) {
        printf("zero\n");
    }  
   
    
    return 0;
    
}
