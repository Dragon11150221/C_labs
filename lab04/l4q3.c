
#include <stdio.h>
#include <strings.h>
#include <string.h>

int main(){
  // init needed elements
  int i,j,length=100;
  char result_type, message[length];
  // the main loop, stop if exit entered
  while (1){
    // prompt needed type

    printf("Integer conversion in decimal (d), octal (o), or hexadecimal (h)? ");
    scanf("%c", &result_type);
    getchar();
    //get message
    if (result_type =='d'||result_type =='o'||result_type =='h'){
      printf("Enter a message: ");

      i=0;
      while (1){
        scanf("%c", &message[i]);
        if(message[i]=='\n'){
          message[i]='\0';
          break;
        }
        i++;
      }
      if (!strcasecmp(message,"exit")){
        break;
      }
    }
    //print it out
    j=0;
    switch (result_type) {
      case 'd':
      while(j<i){
        printf("%d ", message[j]);
        j++;
      }
      case 'o':
      while(j<i){
        printf("%o ", message[j]);
        j++;
      }
      case 'h':
      while(j<i){
        printf("%x ", message[j]);
        j++;
      }
      default: ;;
    }
    printf("\n" );

  }

}
