#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>

struct student{
  char *nam;
  int num_stu;
  int age_stu;
  float moy;
};
typedef struct student student;
int cmpstring();
void showTabStudent(int,student*);
void clean_stdin(void);
void menu(void);
int nbStudents(void);
void enterDataStudents(student*,int);
void enterDataStudent(student);
#endif //STUDENT.H
