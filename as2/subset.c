#include "subset.h"


void best_subset(int length, int all_jobs[][2]){

  int accpeted_array[length][2];

  for (int i = 0;i<length;i++){
    accpeted_array[i][0]=0;
    accpeted_array[i][1]=0;
  }
  printf("The accepted jobs processed by the 1 worker is: \n");
  int result = print_solution(0,0,0,length,all_jobs,accpeted_array,0);
  int num_accepted_jobs=0;
  for (int i = 0;i<length;i++){
    if (accpeted_array[i][0] != 0){
      printf("%d %d\n",accpeted_array[i][0],accpeted_array[i][1]);
      num_accepted_jobs+=1;
    }
  }
  int completion_time = get_completion_time(num_accepted_jobs, accpeted_array);
	int rejection_cost = result - completion_time;

	// report results
	printf("\ntotal completion time = %d\n", completion_time);
	printf("total rejection cost = %d\n", rejection_cost);
	printf("objective = %d\n", result);
}


int find_best(int t,int j, int v,int length,int all_jobs[][2]){
  if (t == length){
    return v;
  }

  int choose = find_best(t+1,j+all_jobs[t][0],v+j+all_jobs[t][0],length,all_jobs);

  int not_choose = find_best(t+1,j,v+all_jobs[t][1],length,all_jobs);

  return (MIN(choose,not_choose));
}

int print_solution(int t,int j, int v,int length,int all_jobs[][2],int accpeted_array[][2],int x){
  if (t != length-1){
    int result = find_best(t,j,v,length,all_jobs);
    if (find_best(t+1,j,v+all_jobs[t][1],length,all_jobs) == result){
      print_solution(t+1, j, v+all_jobs[t][1], length, all_jobs, accpeted_array,x);
    }
    else{
      accpeted_array[x][0] = all_jobs[t][0];
      accpeted_array[x][1] = all_jobs[t][1];
      x += 1;
      print_solution(t+1,j+all_jobs[t][0],v+j+all_jobs[t][0],length,all_jobs,accpeted_array,x);
    }
    return result;
  }
  return 0;
}

//get an array of jobs, calculate cost of rejecting them
int get_rejection_cost(int array_of_jobs_size, int array_of_jobs[][2]) {
	int rejection_cost = 0;

	for (int i = 0; i < array_of_jobs_size; i++) {
		rejection_cost = rejection_cost + array_of_jobs[i][1];
	}
	return rejection_cost;
}

//get an array of jobs, calculate completion_time
int get_completion_time(int array_of_jobs_size, int array_of_jobs[][2]) {
	int step_cost = 0;
	int total_cost = 0;

	for (int i = 0; i < array_of_jobs_size; i++) {
		step_cost = step_cost + array_of_jobs[i][0];
		total_cost = total_cost + step_cost;
	}
	return total_cost;
}
