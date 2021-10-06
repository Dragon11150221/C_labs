#ifndef  SUBSET_M_H
#define  SUBSET_M_H
#include <stdio.h>
#endif

void best_subset_m(int length, int all_jobs[][2],int num_workers);
#define MIN(a,b) (((a)<(b))?(a):(b))
int get_rejection_cost_m(int array_of_jobs_size, int array_of_jobs[][2]);

int get_completion_time_m(int array_of_jobs_size, int array_of_jobs[][2]);
int print_solution_m(int t,int j, int v,int length,int all_jobs[][2],int accpeted_array[][2],int x);
int find_best_m(int t,int j, int v,int length,int all_jobs[][2]);
