#include <stdio.h>

int main(){
  int n;
  //first time, while loop
  n = 99;
  while(n>1){
    printf("%d bottles of beer on the wall,\n",n);
    printf("%d bottles of beer.\n",n);
    printf("Take one down, pass it around,\n");
    n--;
    switch (n) {
      case 1: printf("%d Bottle of beer on the wall ...\n\n",n );break;
      default: printf("%d Bottles of beer on the wall,\n\n",n );break;
    }
  };
  // second time for loop
  for(n=99; n>0; n--){
    printf("%d bottles of beer on the wall,\n",n);
    printf("%d bottles of beer.\n",n);
    printf("Take one down, pass it around,\n");
    switch (n) {
      case 1: printf("%d Bottle of beer on the wall ...\n\n",n );break;
      default: printf("%d Bottles of beer on the wall,\n\n",n );break;
    }
  };
  // third time do while loop
  n=99;
  do{
    printf("%d bottles of beer on the wall,\n",n);
    printf("%d bottles of beer.\n",n);
    printf("Take one down, pass it around,\n");
    n--;
    switch (n) {
      case 1: printf("%d Bottle of beer on the wall ...\n\n",n );break;
      default: printf("%d Bottles of beer on the wall,\n\n",n );break;
    }
  } while (n>1);

}
