/* purposes: lab6 q2
 * Authors: Jinglong Zhao
 * Reference: in README.txt
 * Dates: Started on October 14, 2020
          Last modified on October 15, 2020
*/

#include <stdio.h>

int num_moves=0, num_comps=0;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    num_moves++;
    num_moves++;
}

void print_array(int a[], int n){
  int *x = &a[0];
  for (int i=0;i<n;i++){
    printf("%d ", *(x+i));
  }
  printf("\n");

}

void print_info(int arr[],int n, int num_comps,int num_moves){
  // print result
  printf("In sorted non-decreasing order: ");
  print_array(arr,n);
  printf("Number of comparisons: %d\n",num_comps);
  printf("Number of moves: %d\n",num_moves);
}


void bubblesort(int n,int arr[]){
  // bubble sort
  for(int step=0;step<n-1;step++){
    for(int i=0;i<n-step-1;i++){
      num_comps++;
      if(arr[i]>arr[i+1]){
        swap(&arr[i+1],&arr[i]);
      }
    }
  }
}


void insertionsort(int n,int arr[]){
  // insertion sort
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
        num_comps++;
        arr[j + 1] = arr[j];
        j = j - 1;
        num_moves++;
    }
    num_moves++;
    arr[j + 1] = key;

  }

}

void merge(int arr[], int left, int middle, int right){
  int i, j, k;
  int n1 = middle - left + 1;
  int n2 = right - middle;

  int left_list[n1], right_list[n2];

  for (i = 0; i < n1; i++){
    left_list[i] = arr[left + i];
  }
  for (j = 0; j < n2; j++){
    right_list[j] = arr[middle + 1 + j];
  }
  i = 0; // Initial index of first subarray
  j = 0; // Initial index of second subarray
  k = left; // Initial index of merged subarray
  // add two lists together in order
  while (i < n1 && j < n2) {
    num_comps++;
    num_moves++;
    if (left_list[i] <= right_list[j]) {
      arr[k] = left_list[i];
      i++;
    }
    else {
      arr[k] = right_list[j];
      j++;
    }
    k++;
  }

  // add the reamining elements to main list
  while (i < n1) {
    num_moves++;
    arr[k] = left_list[i];
    i++;
    k++;
  }
  while (j < n2) {
    num_moves++;
    arr[k] = right_list[j];
    j++;
    k++;
  }
}

void mergesort(int right, int left, int arr[]){
  if (left < right) {
    int middle = left + (right - left) / 2;

    mergesort(left, middle,arr);
    mergesort(middle + 1, right,arr);
    merge(arr, left, middle, right);
  }
}

int partition (int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        num_comps++;
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}

void quicksort(int arr[], int low, int high){
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}


void controller(int arr[],int n,char s){
  int arr_copy[n];
  for (int i=0;i<n;i++){
    arr_copy[i]=arr[i];
  }
  num_comps=0;
  num_moves=0;
  switch (s) {
    case 'b':  printf("Bubblesort is deployed ...\n");bubblesort(n,arr_copy);   break;
    case 'i':   printf("Insertionsort is deployed ...\n");insertionsort(n,arr_copy);  break;
    case 'm':  printf("Mergesort is deployed ...\n");mergesort(n,0,arr_copy);   break;
    case 'q':   printf("Quicksort is deployed ...\n"); quicksort(arr_copy,0,n); break;
  }
  print_info(arr,n, num_comps,num_moves);

}

int main(void){
  // init
  int length;
  char s;
  // get length
  printf("Enter the length of the array: " );
  scanf("%d", &length);

  int integers[length];
  // scan integers to array
  printf("Enter %d integers to be sorted: ",length );
  for(int i=0;i<length;i++){
    scanf("%d", &integers[i]);
  }
  int c;
  do {
      c = getchar();
  } while (c != '\n');

  printf("Select from (a)ll | (b)ubblesort | (i)nsertionsort | (m)ergesort | (q)uicksort: ");
  scanf("%c", &s);
  if (s!='a'&&s!='b'&&s!='i'&&s!='m'&&s!='q'){
    printf("%c\n", c);
    printf("invalid input\n");
  }
  else{
    switch (s) {
      case 'a':  controller(integers,length,'b');controller(integers,length,'i');controller(integers,length,'m');controller(integers,length,'q'); break;
      default:   controller(integers,length,s); break;
    }
  }

  return 0;
}
