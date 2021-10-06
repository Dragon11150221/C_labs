#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct point {
  float x;
  float y;
  struct point *next; //point to the next point in the same shape
};

double sample_distance(struct point *shape1, struct point *shape2, int k){

  double distance;
  for (int i = 0; i < k; i++) {
    double number = (shape1->x - shape2->x) * (shape1->x - shape2->x) + (shape1->y - shape2->y) * (shape1->y - shape2->y);
    distance += sqrt(number);
    shape1 = shape1 -> next;
    shape2 = shape2 -> next;
  }
  return distance;

}

struct point *generate(int n){
  struct point *a;
  a = (struct point*) calloc (1, sizeof (struct point));

  a-> x = (rand () % 1000001) / 1000.0; // so that we get numbers in range 0 to 1000
  a-> y = (rand () % 1000001) / 1000.0; // so that we get numbers in range 0 to 1000

  if (n == 0){
    free(a);
    return NULL;
  }
  else{
    a-> next = generate(n-1);
  }
  return a;
}

void printing (struct point *shape) {
  printf("<");
  while (shape != NULL) {
    printf ("(%0.3f, %0.3f)", shape->x, shape->y);
    shape = shape->next;
    if (shape!=NULL){
      printf(", ");
    }
  }
  printf(">\n");
}

int find_length (struct point *s) {
    int i = 0;
    while (s){
        i++;
        s = s->next;
    }
    return i;
}

struct point *find_current(struct point *shape, int k){
  int j = 0;
  while (j<k){
    if (shape->next == NULL) // if we reached the last element, exit loop and return it
        break;
    shape = shape->next;
  }
  return shape;
}

struct point *index_sample(struct point *shape, int k){
  struct point *a = NULL, *b= NULL;
  int n = find_length(shape);

  for (int i = 0; i < k; i++) {
    if (a == NULL) {
      a = (struct point*) calloc (1, sizeof (struct point));
      b = a;
    }
    else {
      b -> next = (struct point*) calloc (1, sizeof (struct point));
      b = b->next;
    }
    struct point *current = find_current(shape,i*n/(k-1));

    b->x = current->x;
    b->y = current->y;
    b->next = NULL;
  }

  return a;
}


void freedom(struct point *shape){
  struct point *a = shape;
  while (shape->next!=NULL){
      shape = shape->next;
      free(a);
      a = shape;
  }
  free(shape);
}

int main(void){
  srand((unsigned)time(NULL));

  int a, b, c;
  printf("Enter two integers in [1, 1000]: ");
  scanf ("%d %d", &a, &b);
  struct point *shape1  = generate (a);
  struct point *shape2  = generate (b);
  printf ("Shape1 with %d points: ", a);
  printing (shape1);
  printf ("Shape2 with %d points: ", b);
  printing (shape2);

  printf ("Enter an integer in [2, 1000]:");
  scanf ("%d", &c);
  struct point *sample1 = index_sample (shape1, c);
  printf ("%d-sample of Shape1: ", c);
  printing (sample1);
  struct point *sample2 = index_sample (shape2, c);
  printf ("%d-sample of Shape2: ", c);
  printing (sample2);

  printf ("The %d-sample distance is: %0.3f", c, sample_distance (sample1, sample2, c));

  freedom(shape1);
  freedom(shape2);
  freedom(sample1);
  freedom(sample2);

  return 0;
}
