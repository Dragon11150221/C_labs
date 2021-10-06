#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int power(int a, int b){
  // since pow in math.h use double as argument and result, I write one for convenience
  if (b==0){
    return 1;
  }
  int x =a;
  for (int i=1;i<b;i++){
    x *= a;
  }
  return x;
}
int f(int n) {
  static int i;

  i+=n;
  printf("return %d\n", i);
  return i;
}

// Assumes little endian
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    printf("%d",size);
    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}
/*
int main(int argv, char* argc[])
{
    int i = 23;
    float f = 23.45f;
    float a = 1531.1;
    float b = 1531.1*2;
    printBits(sizeof(i), &i);
    printBits(sizeof(f), &f);
    printBits(sizeof(a), &a);
    printBits(sizeof(b), &b);

    return 0;
}*/

int input(char *s,int length);
/*
int main()
{
    char *buffer;
    size_t bufsize = 32;
    size_t characters;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }

    printf("Type something: ");
    characters = getline(&buffer,&bufsize,stdin);
    printf("%zu characters were read.\n",characters);
    printf("You typed: '%s'\n",buffer);

    return(0);


}
*/

int fff(int n){
  static int i ;
  i +=n;
  return i;
}
int x =9999;
int main(){
  int z= 1;
  printf("%d",++x);
  int a[30][5];
  int b[10];
  for(int i=0;i<30;i++){
    for (int j=0;j<5;j++){
      a[i][j] = i*10+j;
    }
  }
  printf("%d\n",(*(a+5))[3]);  printf("%d\n",a[3][5]);
  printf("%d\n",a[5][3]);


  int i = 3;
  i+=fff(i);
  printf("%d\n",i);

  i+=fff(i);
  printf("%d\n",i);


  char *s ="abc\012";
  printf("%.5s\n",s);

  char s1[30] = "CMPUT 201";
  char s2[30] = "Hello!";
  strcpy(s1,s2);
  s1[6]='a';
  s2[9]='a';
  printf(s2);
}
