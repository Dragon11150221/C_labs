#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
  char *arr[11];
  srand((unsigned)time(NULL));
  size_t length;
  size_t max_size = 100;

  int n = 0;
  char ch='\0';
  while (n<11){
    arr[n] = (char *) malloc(max_size); // set 100 byte
    if(arr[n] == NULL){
        perror("Unable to malloc buffer");
        exit(1);
    }
    length = getline(&arr[n],&max_size,stdin); // get a whole line to arr[n]
    if (length >100||length<10){
      printf("invalid input");
      exit(1);
    }
    arr[n] = (char *) realloc(arr[n], length); // elimate rest memory
    *(arr[n]+length-1) = '\0'; // change the \n to \0

    n++;
  }
  printf("successfully read 11 things to do.\n");
  // print loop
  while (ch!=EOF){
    printf("Enter ctrl+z to exit, else enter input: ");
    ch = getchar();
    if (ch == '\n'){
      int x = rand() %11;
      printf("%s\n",(arr[x]));
      ch = '\0';

    }
  }

  printf("program end, byebye");
}
