#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "students.h"
#include "subjects.h"

// adds a new student to the linked list of students
// Allocates memory for a new Student
// Allocates memory for the student_name field
// Initializes the new student’s subj_grade_ptr to NULL (no grades yet)
// Adds the new student to the end of the list
                                                          //, char **subj_name, char **grade
void add_student(struct Student **head, char **student_name                                 ) {
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

    printf("Student added: %s\n", new_student->student_name);
}



// Finds a student by their name in the student list
// Traverses the student list and compares student_name with the provided name 
// Returns the matching Student or NULL
struct Student *find_student(struct Student **head, char **student_name) {
    if (head == NULL || *head == NULL) {
        return NULL; // No students in the list
    }

    struct Student *temp = *head;
    while (temp != NULL) {
        if (strcmp(temp->student_name, *student_name) == 0) { // Compare null-terminated strings
            return temp; // Student found
        }
        temp = temp->next;
    }
    return NULL; // Student not found
}


void display_all_students(struct Student **head) {
    struct Student *temp = *head;

    while (temp != NULL) {
        printf("Student: %s\n", temp->student_name);

        struct subject_grade *grade_temp = temp->subj_grade_ptr;

        // Traverse the subject_grade list for this student
        if (grade_temp == NULL) {
            printf("  No subjects assigned.\n");
        } else {
            while (grade_temp != NULL) {
                printf("  Subject: %s, Teacher: %s, Grade: %s\n", 
                    grade_temp->subj_ptr->subject_name, 
                    grade_temp->subj_ptr->teacher_fullname, 
                    grade_temp->grade);
                grade_temp = grade_temp->next;
            }
        }

        temp = temp->next; // Move to the next student
    }
    printf("\n"); // Print a newline after all students are displayed
}

// Intended to find all students studying a specific subject
// Appears incomplete
// Iterates over the student list and attempts to compare student_name repeatedly

void find_students_of_subject(struct Student **student_head, struct Subject **subject_head, char *subject_name) {
    // Check if the subject exists
    struct Subject *subject = find_subject(subject_head, &subject_name);

    if (subject == NULL) {
        printf("\nSubject '%s' not found.\n", subject_name);
        return;
    }

    printf("\nStudents studying '%s':\n", subject_name);

    // Find students that study this subject
    struct Student *temp = *student_head; // Dereference student_head to get the first student
    int found = 0;
    while (temp != NULL) {
        struct subject_grade *grade_temp = temp->subj_grade_ptr;

        // Traverse the student's subject-grade list
        while (grade_temp != NULL) {
            if (grade_temp->subj_ptr == subject) {
                printf("  %s\n", temp->student_name);
                found = 1;
                break;
            }
            grade_temp = grade_temp->next;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("\nNo students found studying '%s'.\n", subject_name);
    }
}



// void find_students_of_subject(struct Student **head, const char *subject_name) 
// struct Subject *find_subject(Struct Subject **head, char[] subject_name) 