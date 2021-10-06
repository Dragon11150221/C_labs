
#include <stdio.h>

float calculate_addition(float num_one, float num_two) {
    return num_one + num_two;
}

int main() {
    float number1, number2;
    printf("enter the first number:");
    scanf("%f", &number1);
    printf("enter the second number:");
    scanf("%f", &number2);
    //set up two float variables and interface to accept from user input
    //print the sum of the entered two float numbers

    printf("%f\n", calculate_addition(number1, number2));
    return 0;
}
