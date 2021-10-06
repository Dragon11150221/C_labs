
/* Purposes: Solution to Assignment #1
 * Authors: Amir, Rylan, Guohui (minor changes only)
 * Dates: Started on August 27, 2020
          Last modified on September 8, 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef INTERFACE
	#define INTERFACE
#endif

// print error when given integers are <0 or >1000
char INVALID_INPUT[] = "Invalid instance";

void bubblesort2d(int a_size, int a[][2]);
int get_accepted_index(int n, int index[]);
int get_rejection_cost(int array_of_jobs_size, int array_of_jobs[][2]);
int get_completion_time(int array_of_jobs_size, int array_of_jobs[][2]);

int main(void) {
	// seed the random number generator
	srand(time(NULL));
	// number of all jobs, jobs accepted and jobs rejected
	int num_jobs, num_accepted_jobs, num_rejected_jobs;
	// time, cost and objective integers
	int completion_time, rejection_cost, objective;

#ifdef INTERFACE
	printf("Enter the number of jobs: ");
#endif
	if (scanf("%d", &num_jobs) != 1) {
		printf("\n%s\n", INVALID_INPUT);
		return -1;
	}

	// check num jobs valid. Print it, if it is valid.
	if (num_jobs < 1 || num_jobs > 1000) {
		printf("\n%s\n", INVALID_INPUT);
		return -1;
	}

	// make 2D array for jobs using given size
	int all_jobs[num_jobs][2];

	// read text file with jobs and save to all_jobs
	for (int i = 0; i < num_jobs; i++) {
		// for reading the text file integers
		int pTime, rCost;
		// read two integers for each line
#ifdef INTERFACE
		printf("Enter processing time and rejection cost: ");
#endif
		if (scanf("%d %d", &pTime, &rCost) != 2) {
			printf("\n%s\n", INVALID_INPUT);
			return -1;
		}
		//check validity. Answer to part 1
		if (pTime < 1 || pTime > 1000 || rCost < 1 || rCost > 1000) {
			printf("\n%s\n", INVALID_INPUT);
			return -1;
		}
		all_jobs[i][0] = pTime;
		all_jobs[i][1] = rCost;
	}

	//we're done reading from stdin
	//We've saved jobs info in all_jobs and number of jobs in num_jobs

	//print the instance as it was read
	printf("%d\n", num_jobs);
	for (int i = 0; i < num_jobs; i++) {
		printf("%d %d\n", all_jobs[i][0], all_jobs[i][1]);
	}

	// make an index which shows whether a job will be accepted/rejected
	int accepted_index[num_jobs];
	num_accepted_jobs = get_accepted_index(num_jobs, accepted_index);

	// get the number of jobs that are rejected
	num_rejected_jobs = num_jobs - num_accepted_jobs;

	// 2D array for accepted jobs. dimension = num_accepted_jobs * 2
	// 2D array for rejected jobs. dimension = (num_jobs-num_accepted_jobs) * 2
	int accepted_jobs[num_accepted_jobs][2];
	int rejected_jobs[num_rejected_jobs][2];

	// copy accepted jobs from "all jobs" array into "accepted jobs" array
	// i is the index variable for of all_jobs. j_acc is the index variable for accepted_jobs, j_rej for rejected_jobs
	for (int i = 0, j_acc = 0, j_rej = 0; i < num_jobs; i++) {
		if (accepted_index[i] == 1) {
			// job is accepted
			accepted_jobs[j_acc][0] = all_jobs[i][0];
			accepted_jobs[j_acc][1] = all_jobs[i][1];
			j_acc++;
		}
		else {
			rejected_jobs[j_rej][0] = all_jobs[i][0];
			rejected_jobs[j_rej][1] = all_jobs[i][1];
			j_rej++;
		}
	}

	// sort by processing time and print accepted jobs
	bubblesort2d(num_accepted_jobs, accepted_jobs);
	printf("The accepted jobs in SPT order:\n");
	for (int i = 0; i < num_accepted_jobs; i++) {
		printf("%d %d\n", accepted_jobs[i][0], accepted_jobs[i][1]);
	}

	// calculate completion_time, rejection_cost, and objective
	completion_time = get_completion_time(num_accepted_jobs, accepted_jobs);
	rejection_cost = get_rejection_cost(num_rejected_jobs, rejected_jobs);
	objective = completion_time + rejection_cost;

	// report results
	printf("\ntotal completion time = %d\n", completion_time);
	printf("total rejection cost = %d\n", rejection_cost);
	printf("objective = %d\n", objective);

	return 0;
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

//get an array of jobs, calculate cost of rejecting them
int get_rejection_cost(int array_of_jobs_size, int array_of_jobs[][2]) {
	int rejection_cost = 0;

	for (int i = 0; i < array_of_jobs_size; i++) {
		rejection_cost = rejection_cost + array_of_jobs[i][1];
	}
	return rejection_cost;
}

// return index which shows whether a job should be accepted or rejected
// 1xn array where n is the number of all jobs
// 0=rejected, 1=accepted
int get_accepted_index(int n, int index[]) {
	int num_accepted = 0;

	// select num_accepted jobs that have not already been chosen
	for (int i = 0; i < n; i++) {
		int accept = rand() % 2;
		if (accept) {
			index[i] = 1;
			num_accepted += 1;
		}
		else
			index[i] = 0;
	}
	return num_accepted;
}

// sorting our 2d array of jobs using column 0
void bubblesort2d(int a_size, int a[][2]) {
	int row = a_size;
	int x, temp;
	int num_columns = 2;

	for (int i = 0; i < row; i++) {
		for (int j = i + 1; j < row; j++) {
			if (a[i][0] > a[j][0]) {
				for (x = 0; x < num_columns; x++) {
					temp = a[i][x];
					a[i][x] = a[j][x];
					a[j][x] = temp;
				}
			}
		}
	}
	return;
}
