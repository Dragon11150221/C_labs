#ifndef L12_H
#define L12_H


#include <stdio.h>
#include <stdlib.h>

#ifndef INTERFACE
	#define INTERFACE
#endif

#ifndef LENGHT
  #define LENGHT 99
#endif

int cmpfunc (const void * a, const void * b);
int sortGrade (const void * a, const void * b);
int comparatorn(const void *p, const void *q);
int comparatora(const void *p, const void *q);
int comparatorq(const void *p, const void *q);
int comparatorl(const void *p, const void *q);
int comparatorf(const void *p, const void *q);
int comparatort(const void *p, const void *q);
int comparatorg(const void *p, const void *q);

#endif
