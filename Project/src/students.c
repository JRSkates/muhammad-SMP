#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "students.h"

// adds a new student to the linked list of students
// Allocates memory for a new Student
// Allocates memory for the student_name field
// Initializes the new student’s subj_grade_ptr to NULL (no grades yet)
// Adds the new student to the end of the list
void add_student(struct Student **head, char **student_name, char **subj_name, char **grade) {
    struct Student *new_student = malloc(sizeof(struct Student));
    if (new_student == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Allocate memory for student_name
    new_student->student_name = malloc(strlen(*student_name) + 1);
    if (new_student->student_name == NULL) {
        printf("Memory allocation failed\n");
        free(new_student);
        return;
    }
    strcpy(new_student->student_name, *student_name);

    // Initialize subj_grade_ptr
    new_student->subj_grade_ptr = NULL; // No grades yet
    new_student->next = NULL;

    // Add the student to the linked list
    if (*head == NULL) {
        *head = new_student;
    } else {
        struct Student *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_student;
    }

    printf("[DEBUG] Student added: %s\n", new_student->student_name);
}



// Finds a student by their name in the student list
// Traverses the student list and compares student_name with the provided name 
// Returns the matching Student or NULL
struct Student *find_student(struct Student **head, char **student_name)
{
    struct Student *temp = *head;

    while (strncmp(temp->student_name, *student_name, strlen(*student_name)))
    {
        if (temp->next == NULL)
            return NULL;

        temp = temp->next;
    }

    return temp;
}

// Intended to find all students studying a specific subject
// Appears incomplete
// Iterates over the student list and attempts to compare student_name repeatedly
struct Student *find_students_of_subject(struct Student **head, char **student_name)
{
    struct Student *temp = *head;

    while (temp->next != NULL)
    {

        int len = sizeof(temp->student_name);

        temp = temp->next;
    }

    while (strncmp(temp->student_name, *student_name, strlen(*student_name)))
    {
        if (temp->next == NULL)
            return NULL;

        temp = temp->next;
    }

    return temp;
}