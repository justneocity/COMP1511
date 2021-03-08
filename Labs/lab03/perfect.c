//Lab03 Three_Five
//Rifa Jamal z5311190

#include <stdio.h>

int main(void) {

    int number;
    int counter = 1;
    int sum = 0;
    
    //user enters number value
    printf("Enter number: ");
    scanf("%d", &number);
    
    printf("The factors of %d are: \n", number);
    
    //print factors of number
    //loop all factors of number
    
    while (counter <= number) {
        if (number % counter == 0) {
            printf("%d\n", counter);
            
            sum = sum + counter; 
        }
        
        //increment counter
        counter = counter + 1;
            
    }

    //add the factors
   
    printf("Sum of factors = %d\n", sum);

    //check for perfect number
    
    if (sum == 2*number) {
        printf("%d is a perfect number\n", number); 
    } else {
        printf("%d is not a perfect number\n", number);
    }
            
    return 0;
    
    
}
