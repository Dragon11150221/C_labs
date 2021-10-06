#include <stdio.h>

int main() {

    int i, j;
    int a=0,b=0,x=0,y=0,change_turn=0;

    printf("Enter two positive integers: ");
    scanf("%d%d", &i, &j); // need to validate both being positive
    int print_i = i, print_j = j;
    // set initial value of coeffient a and b
    i>j ? (a=1) :  (b = 1);
    i<j ? (x = 1) : (y = 1);
    // the while loop
    while (i != j) {
      if (i > j){
        i -= j;
        if (i < j){
          change_turn = 1;
        }
      }
      else{
        j -= i;
        if (i > j){
          change_turn = 1;
        }

      }
      // add coeffient
      a -= x;
      b -= y;
      if (change_turn){
        int temp1 = x; // swap them to previous value
        int temp2 = y;
        x = a;
        y = b;
        a= temp1;
        b= temp2;
        change_turn = 0;
      }
    }
    if (b<0){ // print them as needed format
      printf("GCD: %d = %d * %d + (%d) * %d\n", i,a,print_i,b,print_j);
    }
    else{
      printf("GCD: %d = (%d) * %d + %d * %d\n", i,a,print_i,b,print_j);
    }
    return 0;
}
