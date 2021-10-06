#include <stdio.h>

#undef MAX_LEN
#define MAX_LEN 256
#ifndef MAX_LEN
#define MAX_LEN 512
#endif

struct{
  short s[5];
  union{
    float y;
    long z;
  } u;
} t;

int main(void) {
  printf("%d",MAX_LEN);
  char str[10];

  sprintf(str,"12345678901234567890");
  printf("%s\n",str);

}
