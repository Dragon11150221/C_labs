
#include <stdio.h>

int main(){
  // init
  int length,i,temp,step,number;

  // get length
  printf("Enter the length of the array: " );
  scanf("%d", &length);

  int integers[length];
  // scan integers to array
  printf("Enter %d integers to be sorted: ",length );
  for(i=0;i<length;i++){
    scanf("%d", &integers[i]);
  }

  // bubble sort
  for(step=0;step<length-1;step++){
    for(i=0;i<length-step-1;i++){
      if(integers[i]>integers[i+1]){
        temp=integers[i+1];
        integers[i+1]=integers[i];
        integers[i]=temp;
      }
    }
  }

  // print result
  printf("In sorted non-decreasing order: ");
  for(i=0;i<length;i++){
    printf("%d ", integers[i]);
  }
  printf("\n");

  // get value
  printf("Enter the integer you wish to locate: " );
  scanf("%d",&number );

  // find in array
  int first=0,last= length-1,middle=last/2;
  do{
    if(first>last){
      middle =-1;
      break;
    }
    if(integers[middle]==number){
      break;
    }
    else if (integers[middle]>number){
      last=middle-1;
    }
    else if (integers[middle]<number){
      first=middle+1;
    }
    middle=(first+last)/2;

  } while(1);
  printf("It's found at position/index: %d\n", middle);


}
