//Lab03 Three_Five
//Rifa Jamal z5311190

#include <stdio.h>

int main(void) {

    //initialise counter to n
    int counter = 1;
    int number;
    
    //User enters counter value
    printf("Enter number: ");
    scanf("%d", &number);
    
    //loop until not <=1
    while (counter < number) {
        if (counter % 3 == 0 || counter % 5 == 0) {
            printf("%d\n", counter);
        }
    
        //increment counter
        counter = counter + 1;
    }

    return 0;

}
