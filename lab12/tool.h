#ifndef TOOL_H
#define TOOL_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

struct student {
    char *lastname;
    char *firstname;
    float assignments; // range [0, 21]
    float quizzes; // range [0, 14]
    float labs; // range [0, 30]
    float finalexam; // range [0, 30]
    float total; // range [0, 100]
    char grade; // range {F, D, C, B, A}
    char *name;
};


void initialization(const int LENGTH, struct student students[]);
void printStudents(const int LENGTH, struct student students[]);
float gradeStudents(const int LENGTH, struct student students[], float cutoffList[]);

#endif
