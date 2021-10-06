#include <stdio.h>

float db(float *p){
  unsigned char* cp = (unsigned char*)p; // use pointer to point on each byte
  if ((*(cp+2)>>7)&1){ // since float type we need to the exponent +1
    *(cp+3)+=1; // if the 8th of exponent is 1 add 1 to the previous byte
  }
  *(cp+2)+=10000000; // add 1 to the 8th exponent

  return *p;
}

int main(void){
  float n,result; // interface
  printf("Enter a floating-point number: ");
  if (scanf("%f", &n) == 1){
    result = db(&n);
    printf("Doubling becomes %f", result);
  }
  return 0;

}
