#ifndef  SUBSET_H
#define  SUBSET_H
#include <stdio.h>
#endif
#define MIN(a,b) (((a)<(b))?(a):(b))

void best_subset(int length, int all_jobs[][2]);

int find_best(int t,int j, int v,int length,int all_jobs[][2]);

int print_solution(int t,int j, int v,int length,int all_jobs[][2],int accpeted_array[][2],int x);

int get_rejection_cost(int array_of_jobs_size, int array_of_jobs[][2]) ;
int get_completion_time(int array_of_jobs_size, int array_of_jobs[][2]) ;
