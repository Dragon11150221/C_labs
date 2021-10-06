
#include <stdio.h>

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

int coefficient(int n,int arr[],int index){
  // continuely break the number until it is 0
  // n is length
  // arr is the result array
  // index is the current index in arr[]
  if (n<=0){ //ending statement
    return 0;
  }

  int a = n % power(3,index+1), value; //get the remainder
  int k = power(3,index); // k is used as interval, when 0-k, k-2k, 2k-3k, the value is 1, -1, 0
  if (a>0&& a<=k){
    value =1;
  }
  else if (a>k&&a<=2*k){
    value = -1;
  }
  else {
    value = 0;
  }
  // printf("a is %d, k is %d, value is %d, index is %d\n", a,k,value,index); << test words
  // store result and call itself by next index
  arr[index] = value;
  n-= power(3,index)*value; // elimanate current result from the number
  return 1+coefficient(n,arr,index+1);

}


int main(){
  // interface
  int number, arr[10];
  printf("Enter a positive integer: ");
  scanf("%d",&number);

  if (number<1||number>1000){
    printf("invalid input");
  }
  // find result
  int k = coefficient(number,arr,0);
  // print result
  int *a = &arr[0];
  printf("Coefficient sequence: ");
  for (int i = 0; i < k; i++) {
      printf("%d ", *(a + i));
  }
  printf("\n");

  return 0;
}
