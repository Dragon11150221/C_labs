#include <stdio.h>


int helper(int *p, int n, int x){
  // this function find the index of next number
  // argument *p always start from the first of the list
  // argument n is length
  // argument x is the current value
  int index = 0,y = 1000; // set up the smallest value of current found, since max is 1000, 1000 is the initial.
  for (int i =0; i<n;i++){
    if (*(p+i)>x&&*(p+i)<y){ // looking throught the whole list and find the next index
     y = *(p+i);
     index = i;
    }
  }
  return index;
}


int main() {
  // set up interface
  int n;
  printf("Enter the length of the array: ");
  scanf("%d",&n);
  int a[n],orders[n];
  printf("Enter %d distinct positive integers: ", n);
  for(int i=0;i<n;i++){
    scanf("%d", &a[i]);
  }
  // get the first value of x
  orders[0] = helper(&a[0], n, 0);

  for (int i=1;i<n;i++){ // looking through the whole list, use the last result to get the as next argument
    orders[i] = helper(&a[0], n, a[orders[i-1]]);
  }
  // print result out
  printf("Index order: ");
  for (int i=0;i<n;i++){
    printf("%d ", orders[i]);
  }
  printf("\n");

}
