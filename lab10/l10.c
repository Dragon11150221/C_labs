
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int compare(char *a){
  const char * listAction[] = {"add","sub","mul","div","mod","pow","log"};

  for(int i = 0;i<7;i++){
    int result = strcmp(a,listAction[i]);
    if (result ==  0){
      return i;
    }
  }
  return -1;
}

int main(int argc, char *argv[]){

  if(argc != 4){
    printf("Usage: %s [add|sub|mul|div|mod|pow|log Num Num]\n",argv[0]);
    exit(0);
  }

  float x; char ch;
  if ((sscanf(argv[2],"%f%c",&x,&ch) && ch!=' ' && ch!='\n' && ch!='\0')||(sscanf(argv[3],"%f%c",&x,&ch) && ch!=' ' && ch!='\n' && ch!='\0')){
    printf("Usage: %s [add|sub|mul|div|mod|pow|log Num Num]\n",argv[0]);
    exit(0);
  }

  char *op = argv[1];
  double num1 = atof(argv[2]), num2 = atof(argv[3]);
  double result;
  const char * resultPrint[] = {"addition","subtraction","multiplication","division","modulo","power","logarithm"};
  int action = compare(op),error = 0,printType = 0;
  if (strchr(argv[2],'.')||strchr(argv[3],'.')){
    printType = 1;
  }

  switch (action) {
    case 0:
    result = num1+num2; break;
    case 1:
    result = num1-num2;break;
    case 2:
    result = num1*num2;break;
    case 3:
    if (num2 == 0){
      error = 1;
      break;
    }
    result = num1/num2; break;
    case 4:
    result = (int)num1%(int)num2; break;
    case 5:
    result = pow(num1,num2); printType = 1; break;
    case 6:
    result = log(num2)/log(num1); printType = 1; break;
    default:
    printf("Usage: %s [add|sub|mul|div|mod|pow|log Num Num]\n",argv[0]);
    exit(0);
  }
  if (error){
    printf("%s cannot be performed for %s, %s\n",resultPrint[action],argv[2],argv[3]);
  }
  else if (printType){
    printf("%s for %s, %s is %f\n",resultPrint[action],argv[2],argv[3],result);
  }
  else{
    printf("%s for %s, %s is %d\n",resultPrint[action],argv[2],argv[3],(int)result);
  }

  return 0;
}
