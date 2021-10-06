
#include "tool.h"

void initialization(const int LENGTH, struct student students[]){
  size_t max_size = 100;
  FILE *fp;
  fp = fopen("spreadsheet.txt" , "r");
  if(fp == NULL) {
    perror("Error opening file");
    exit(-1);
  }

  char *garbagec= (char *) malloc(max_size);
  for (int i =0;i<5;i++){
    fscanf(fp,"%s",garbagec);
  }

  for (int i=0; i<LENGTH; i++){
    students[i].lastname = (char *) malloc(max_size); // set 100 byte
    students[i].firstname = (char *) malloc(max_size); // set 100 byte
    fscanf(fp, "%s %s %f %f %f %f", students[i].lastname, students[i].firstname,\
    &students[i].assignments, &students[i].quizzes, &students[i].labs, &students[i].finalexam);

    students[i].total = 20*students[i].assignments/21+20*students[i].quizzes/14\
    +students[i].labs+students[i].finalexam;

    char * name = (char *) malloc(1 + strlen(students[i].firstname)+ strlen( students[i].lastname) );
    strcpy(name, students[i].lastname);
    strcat(name," ");
    strcat(name, students[i].firstname);
    students[i].name = name;
    students[i].grade = 'I';
  }

  fclose(fp);
}

void printStudents(const int LENGTH, struct student students[]){
  printf("%-20s   %s %s %s %s %s %s\n","Name","Assignments","Quizzes","Labs","FinalExam","Total","Grade");
  for (int i = 0; i<LENGTH; i++){
    printf("%-20s   %5.2f   %5.2f   %5.2f    %5.2f    %5.2f    %c\n",students[i].name,students[i].assignments,\
    students[i].quizzes,students[i].labs,students[i].finalexam,students[i].total,students[i].grade);
  }
}


float gradeStudents(const int LENGTH, struct student students[], float cutoffList[]){
  float total = 0 ;

  for (int i =0; i<LENGTH; i++){
    if (students[i].total < cutoffList[0]){
      students[i].grade = 'F';
    }
    if (students[i].total >= cutoffList[0]){
      students[i].grade = 'D';
    }
    if (students[i].total >= cutoffList[1]){
      students[i].grade = 'C';
    }
    if (students[i].total >= cutoffList[2]){
      students[i].grade = 'B';
    }
    if (students[i].total >= cutoffList[3]){
      students[i].grade = 'A';
    }
    switch (students[i].grade) {
      case 'A': total += 4; break;
      case 'B': total += 3; break;
      case 'C': total += 2; break;
      case 'D': total += 1; break;
      case 'F': break;
    }
  }
  return total/99;

}
