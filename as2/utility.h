
#ifndef  UTILITY_H
#define  UTILITY_H
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#endif


struct job * generate_instance(int num_jobs);
struct job *read_instance(char *inputfilename);
void printing(struct job *head);

struct job {
  int completion_time;
  int rejection_cost;
  struct job *next;
};
