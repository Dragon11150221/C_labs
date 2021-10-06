#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void initialization(int n, int matrix[n][n]){
  int index, indexes[n/2];
  srand(time(NULL));   // Initialization

  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      matrix[i][j]=0;
    }
    int j=0;
    while (j<n/2){
      int condition=1;
      index = rand() % n;
      for (int k=0;k<j;k++){
        if (indexes[k]==index){
          condition=0;
        }
      }
      if (condition){ // used to make sure no same index
        indexes[j]=index;
        matrix[i][index]=1;
        j++;
      }
    }
  }
}


void swap(int row,int pos1, int pos2,int n,int matrix[n][n]){
  int temp; //simple swap
  temp = matrix[row][pos1];
  matrix[row][pos1] = matrix[row][pos2];
  matrix[row][pos2] = temp;
}

void balance1(int n,int matrix[n][n]){
  for (int i=0;i<n;i++){
    // count how many 1 we have in a column
    int quantity = 0;
    for (int j=0;j<n;j++){
      if (matrix[j][i]==1){
        quantity++;
      }
    }


    if (quantity>n/2){
      int k=0, j=0;
      // k is a number shows how many number still need to be swaped
      // j is row index
      // i is column index
      while (k!=quantity-n/2){
        if (matrix[j][i] == 1){
          for (int z = i+1;z<n;z++){
            swap(j,i,z,n,matrix);
            if (matrix[j][i]==0){
              k++;
              break;
            }
          }

        }
        j++;

      }
    }
    else if (quantity <n/2){
      // same as above
      int k=0, j=0;
      while (k!=-quantity+n/2){
        if (matrix[j][i] == 0){
          for (int z = i+1;z<n;z++){
            swap(j,i,z,n,matrix);
            if (matrix[j][i]==1){
              k++;
              break;
            }
          }

        }
        j++;
      }
    }
  }

}

int main(void){
  int n;
  char c; // c is used to test the input is valid or invalid
  while(1){
    printf("Enter the size of matrix, a positive even integer: ");
    if (scanf("%d%c", &n, &c)!=2||n<2||n>80||c != '\n'||n%2){  // end loop if invalid
      break;
    }
    int matrix[n][n];

    initialization(n,matrix);
    printf("Initial 4x4 matrix: \n");
    for (int i=0;i<n;i++){
      for (int j=0;j<n;j++){
        printf("%d ", matrix[i][j]);
      }
      printf("\n" );
    }
    balance1(n, matrix);
    printf("Final balanced matrix:\n" );
    for (int i=0;i<n;i++){
      for (int j=0;j<n;j++){
        printf("%d ", matrix[i][j]);
      }
      printf("\n" );
    }
  }
}
