/* purposes: Assignment2
 * Authors: Jinglong Zhao
 * Reference: Assignment1
 * Dates: Started on November 22, 2020
          Last modified on November 22, 2020
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int scan_jobs(int length,int jobs[][2]){
  // scan jobs if invalid return 1 as true to game_end
  char c;
  for (int i=0;i<length;i++){
    printf("enter processing time and rejection cost: ");
    scanf("%d%c", &jobs[i][0],&c);
    if (c!=' '||jobs[i][0]<1||jobs[i][0]>1000){
      return 1;
    }
    scanf("%d%c", &jobs[i][1],&c);
    if ((c!='\n'&&c!=' ')||jobs[i][1]<1||jobs[i][1]>1000){
      return 1;
    }
  }
  return 0;
}

void print_instance(int length,int jobs[][2]){
  //print a given list
  for (int i=0;i<length;i++){
    for (int j=0;j<2;j++){
      printf("%d ", jobs[i][j]);
    }
    printf("\n");
  }
}

void sort(int length,int list[][2]){
  // bubble sort from previous lab
  int step,i,temp;
  for(step=0;step<length-1;step++){
    for(i=0;i<length-step-1;i++){
      if(list[i][0]>list[i+1][0]){
        temp=list[i+1][0];
        list[i+1][0]=list[i][0];
        list[i][0]=temp;
        temp=list[i+1][1];
        list[i+1][1]=list[i][1];
        list[i][1]=temp;
      }
    }
  }
}

int caculate(int length,int list[][2],int index){
  // calulate needed value
  int result = 0;
  for (int i=0;i<length;i++){
      result += list[i][index];
  }
  return result;
}


int main(void){
  //init some variables
  srand((unsigned)time(NULL));
  int length;
  char c;

  //get length
  printf("enter the number of jobs: ");
  scanf("%d%c",&length,&c);
  // if Invalid end the program
  if (length<1||(c!='\n'&&c!=' ')||length>1000){
    printf("Invalid instance\n");
    return 0;
  }

  int jobs[length][2], accepted_jobs[length][2], game_end;
  // scan values to jobs
  game_end = scan_jobs(length,jobs);
  if (game_end){
    printf("Invalid instance\n");
    return 0;
  }
  printf("%d\n", length);
  print_instance(length,jobs);

  // randomly uniformly take some jobs
  int k=0;
  for (int i=0;i<length;i++){
    if (rand() % 2){   // this random return 0 or 1, use as true or false
      accepted_jobs[k][0]=jobs[i][0];
      accepted_jobs[k][1]=jobs[i][1];
      k++;
    }
  }

  // sort and print accepted jobs
  printf("The accepted jobs in SPT order:\n");
  sort(k,accepted_jobs);
  print_instance(k,accepted_jobs);
  printf("\n");

  // manage and print result
  int total_time,total_cost,objective,cost;
  total_time = caculate(k,accepted_jobs,0);
  cost = caculate(length,jobs,1);
  total_cost = cost - caculate(k,accepted_jobs,1);
  objective = total_cost + total_time;

  printf("total completion time = %d\n", total_time);
  printf("total rejection cost = %d\n", total_cost);
  printf("objective = %d\n", objective);
  return 0;
}
