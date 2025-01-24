#include "subjects.h"

#ifndef _STUDENTS_H_
#define _STUDENTS_H_

// This structure represents a Student

// student_name: dynamically allocated string for the name of the student
// subj_grade_ptr: A pointer to a linked list of struct subject_grade (subjects and their grades)
// next: a pointer to the next Student in the linked list
struct Student
{
    char *student_name;
    struct subject_grade *subj_grade_ptr; // ptr to a linked list of subject grade
    struct Student *next;
};

                                                          //, char **subj_name, char **grade
void add_student(struct Student **head, char **student_name                                 );
struct Student *find_student(struct Student **head, char **student_name);
void find_students_of_subject(struct Student **student_head, struct Subject **subject_head, char *subject_name);
void display_all_students(struct Student **head);


#endif // _STUDENTS_H_