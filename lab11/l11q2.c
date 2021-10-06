#include <stdio.h>

typedef union {
  float f;
  struct {
    unsigned int mantisa : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
  } parts;
} float_cast;


int main(void){
  float_cast number;
  float n;
  printf("Enter a floating-point number: ");
  n=5.0;
  number.f = n;
  printf("%d",number.parts.exponent);
  printf("Doubling becomes %f", number.f);

  return 0;
}
