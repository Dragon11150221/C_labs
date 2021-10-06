#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  // init
  int point, number, index=0, pointList[2] = {0,0},i;
  srand(time(NULL));   // Initialization

  // whole game loop
  while (pointList[0] < 1000 && pointList[1] < 1000){
    scanf("%d", &number);
    //add value
    point = number*(-5) +5;
    for(i=number;i>0;i--){
      point += (rand() % 7 + 1);
    }
    pointList[index] += point;
    // change player
    if (index == 0){
      index = 1;
    }
    else{
      index = 0;
    }
  }

  //print result
  if(index ==1){
    printf("Alex wins with %d points.\n",pointList[0]);
  }
  else{
    printf("Bob wins with %d points.\n", pointList[1]);
  }
}
