#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getdigit(int number){
  int count = 0;
  do{
    count++;
    number /= 10;
  } while(number != 0);
  return count;
}

struct point {
  char info[100];
  struct point *next; //point to the next point in the same shape
};

void printing (struct point *head) {
  while (head != NULL) {
    printf("%s",head->info);
    head = head->next;
  }
}

int main(int argc, char *argv[]){
  srand((unsigned)time(NULL));

  if(argc != 2){
    printf("Usage: %s input.txt\n",argv[0]);
    exit(-1);
  }

  char *fileName = argv[1];
  FILE *fp1 = fopen(fileName, "r");
  if (fp1 == NULL) {
    printf("No such a file named %s",fileName);
    exit(-1);
  }
  struct point *inFilevalue;
  inFilevalue = (struct point*) calloc (1, sizeof (struct point));
  struct point *head = inFilevalue;

  while (fgets(inFilevalue->info, sizeof(inFilevalue->info), fp1)){
    struct point *a;
    a = (struct point*) calloc (1, sizeof (struct point));
    inFilevalue->next = a;
    inFilevalue = inFilevalue->next;
  }
  fclose(fp1);

  printf("Enter the number of output files: ");
  unsigned int n;
  scanf("%d",&n);
  if (n<=0){
    printf("Must enter a positive numeber!");
    exit(-1);
  }

  int width = getdigit(n);

  for (unsigned int i=1; i<n+1; i++){
    char outputName[100];
    sprintf(outputName, "output%0*d.txt",width,i);
    FILE *fp2 = freopen(outputName, "w+", stdout);
    printf("Content of output%0*d.txt: \n\n", width,i);
    printing(head);
    fclose(fp2);
  }

  return 0;
}
