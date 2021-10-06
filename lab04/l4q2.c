
#include <stdio.h>

int main(){
  char user_input[15];
  printf("enter a string of 15 characters: " );
  scanf("%s", user_input);

  for(int i=0;i<3;i++){
    for(int j=0;j<5;j++){
      printf("%c", user_input[i*5+j]);
    }
    printf("\n");
  }

  int satisfy = 1;
  for(int i=0;i<3;i++){
    for(int j=0;j<5;j++){
      char *instance = &user_input[2];
      if(i==0&&j!=2&&user_input[j]==*instance){
        satisfy = 0;
      }
      if(i==1&&(j==0||j==4)&&user_input[j]==*instance){
        satisfy = 0;
      }
      if(i==1&&j>0&&j<4&&user_input[5+j]!=*instance){
        satisfy = 0;
      }
      if(i==2&&user_input[10+j]!=*instance){
        satisfy = 0;

      }
    }
  }
  if(satisfy){
    printf("you have entered a pyramid.\n");
  }
  else{
    printf("you have not entered a pyramid.\n");
  }

}
