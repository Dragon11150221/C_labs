#include "l12.h"
#include "tool.h"


int main(int argc, char *argv[]){
  int sorting = 1;
  if (strcmp(argv[0],"./grading")==0){
    sorting = 0;
  }
  struct student students[LENGHT];
  initialization(LENGHT,students);

  if (sorting){
    char *type;
    type = (char *) malloc(10);
    printf("sort all students : ");
    scanf("%s",type);
    if (strcmp(type,"Name")==0){
      qsort(students, LENGHT, sizeof(struct student), comparatorn);
    }
    else if (strcmp(type,"Assignments")==0){
      qsort(students, LENGHT, sizeof(struct student), comparatora);
    }
    else if (strcmp(type,"Quizzes")==0){
      qsort(students, LENGHT, sizeof(struct student), comparatorq);
    }
    else if (strcmp(type,"Labs")==0){
      qsort(students, LENGHT, sizeof(struct student), comparatorl);
    }
    else if (strcmp(type,"FinalExam")==0){
      qsort(students, LENGHT, sizeof(struct student), comparatorf);
    }
    else if (strcmp(type,"Total")==0){
      qsort(students, LENGHT, sizeof(struct student), comparatort);
    }
    else if (strcmp(type,"Grade")==0){
      qsort(students, LENGHT, sizeof(struct student), comparatorg);
    }
    else{
      printf("invalid input");
      exit(-1);
    }

  }
  else{
    float avrGrade;
    float cutoffList[4];
    printf("enter four cutoffs for grade assignment: ");
    scanf("%f %f %f %f",&cutoffList[0],&cutoffList[1],&cutoffList[2],&cutoffList[3]);
    for (int i =0; i<4;i++){
      if (cutoffList[i]<50||cutoffList[i]>90){
        printf("invalid input");
        exit(-1);
      }
    }
    avrGrade = gradeStudents(LENGHT,students,cutoffList);

    printf("the class average grade point is: %0.2f\n",avrGrade);
    qsort(students, LENGHT, sizeof(struct student), comparatorg);

  }
  printStudents(LENGHT,students);

  return 0;
}
int comparatorn(const void *p, const void *q)
{
    char *l = ((struct student *)p)-> name;
    char *r = ((struct student *)q)-> name;
    return strcmp(l,r);
}
int comparatora(const void *p, const void *q)
{
    float l = ((struct student *)p)-> assignments;
    float r = ((struct student *)q)-> assignments;
    if (l==r){ return comparatorn(p,q);}
    return (l - r);
}

int comparatorq(const void *p, const void *q)
{
    float l = ((struct student *)p)-> quizzes;
    float r = ((struct student *)q)-> quizzes;
    if (l==r){ return comparatorn(p,q);}
    return (l - r);
}
int comparatorl(const void *p, const void *q)
{
    float l = ((struct student *)p)-> labs;
    float r = ((struct student *)q)-> labs;
    if (l==r){ return comparatorn(p,q);}
    return (l - r);
}
int comparatorf(const void *p, const void *q)
{
    float l = ((struct student *)p)-> finalexam;
    float r = ((struct student *)q)-> finalexam;
    if (l==r){ return comparatorn(p,q);}
    return (l - r);
}
int comparatort(const void *p, const void *q)
{
    float l = ((struct student *)p)-> total;
    float r = ((struct student *)q)-> total;
    if (l==r){ return comparatorn(p,q);}
    return (l - r);
}
int comparatorg(const void *p, const void *q)
{
    char l = ((struct student *)p)-> grade;
    char r = ((struct student *)q)-> grade;
    if (l==r){ return comparatorn(p,q);}
    return (l < r);
}
