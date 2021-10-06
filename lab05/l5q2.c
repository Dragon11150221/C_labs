

#include <stdio.h>


int calculate_fibonacci(int index) {
    if (index <3){
      return index;
    }
    else{
      return calculate_fibonacci(index-1)+calculate_fibonacci(index-2)+calculate_fibonacci(index-3);
    }
}

int main() {
    int index;
    char c; // c is used to catch user input other than integer, reference in readme
    while(1){
      printf("Enter a position index: ");
      if (scanf("%d%c", &index, &c)!=2||index<0||c != '\n'){
        break;
      }
      printf("%d\n", calculate_fibonacci(index));
    }

    return 0;
}
