#ifndef  MAIN_H
#define  MAIN_H
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "utility.h"
#include "subset.h"
#include "subset_m.h"
#endif

#ifndef INTERFACE
	#define INTERFACE
#endif

// print error when given integers are <0 or >1000
char INVALID_INPUT[] = "Invalid instance";




int find_length(struct job *s) ;

void transfer_data(int length, int all_jobs[][2], struct job *head);


void sort(int length,int list[][2]);

void freedom(struct job *head);
