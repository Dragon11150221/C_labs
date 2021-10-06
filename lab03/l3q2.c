#include <stdio.h>

int main(){
  int i,largest=0,secondLargest, numberList[20];
  printf("Enter 20 integers: ");
  //scan the 20 integers into a list
  for (i = 0; i < 20; i++) {
    scanf("%d", &numberList[i]);
  }
  //find the largest and secondLargest
  for (i=0; i<20; i++){
    if (numberList[i] > largest){
      secondLargest = largest;
      largest = numberList[i];
    }
  }
  //print result
  printf("Largest: %d\n",largest );
  printf("Second largest: %d\n",secondLargest);
}
