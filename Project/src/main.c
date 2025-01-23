#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include "students.h"
// #include "subjects.h"

// This structure represents a subject
// subject_name: A fixed-length string for the name of the subject
// teacher_fullname: A fixed-length string for the name of the teacher teaching the subject
// next: A pointer to the next subject in a linked list
struct Subject
{
    // Seg Fault
    // char *subject_name;
    // char *teacher_fullname;
    char subject_name[20];
    char teacher_fullname[20];
    struct Subject *next;
};


// This structure links a subject to a grade for a student

// subj_ptr: A pointer to a struct Subject (the subject being graded)
// grade: A single-character grade
// next: A pointer to the next subject-grade pair in a linked list
struct subject_grade
{
    struct Subject *subj_ptr;
    char grade[1];
    struct subject_grade *next;
};

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

// Creates a new Subject node and initializes it with the given subject_name and teacher_fullname

// Allocates memory for a new Subject
// Copies subject_name and teacher_fullname into the new node.
// Sets the next pointer to NULL
struct Subject *create_subject(char **subject_name, char **teacher_fullname) {
    struct Subject *new_subject = malloc(sizeof(struct Subject));
    if (new_subject == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    // Safely copy the subject name and teacher name
    strncpy(new_subject->subject_name, *subject_name, sizeof(new_subject->subject_name) - 1);
    new_subject->subject_name[sizeof(new_subject->subject_name) - 1] = '\0'; // Null-terminate
    strncpy(new_subject->teacher_fullname, *teacher_fullname, sizeof(new_subject->teacher_fullname) - 1);
    new_subject->teacher_fullname[sizeof(new_subject->teacher_fullname) - 1] = '\0'; // Null-terminate

    new_subject->next = NULL; // Initialize next pointer
    return new_subject;
}

// Adds a new Subject to the linked list of subjects

// Creates a new Subject node using create_subject
// Adds the new node to the end of the linked list
void add_subject(struct Subject **head, char **subject_name, char **teacher_fullname) {
    struct Subject *new_subj = create_subject(subject_name, teacher_fullname);
    if (new_subj == NULL) {
        return; // Memory allocation failed
    }

    if (*head == NULL) {
        *head = new_subj; // First subject in the list
        return;
    }

    struct Subject *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_subj; // Add new subject to the end of the list
}

// searches for a subject in the linked list by name

// Traverses the list of Subject nodes
// Compares the subject_name field of each node to the input
struct Subject *find_subject(struct Subject **head, char **subject_name) {
    if (head == NULL || *head == NULL) {
        return NULL; // No subjects in the list
    }

    struct Subject *temp = *head;
    while (temp != NULL) {
        // Compare subject names
        if (strncmp(temp->subject_name, *subject_name, sizeof(temp->subject_name)) == 0) {
            return temp; // Subject found
        }
        temp = temp->next;
    }
    return NULL; // Subject not found
}

// Finds the first subject taught by a specific teacher

// Traverses the subject list and compares teacher_fullname with teacher_name
// Returns the matching Subject or NULL
struct Subject *find_teacher_of_subject(struct Subject **head, char **teacher_name)
{
    struct Subject *temp = *head;

    while (strncmp(temp->teacher_fullname, *teacher_name, strlen(*teacher_name)))
    {
        if (temp->next == NULL)
            return NULL;

        temp = temp->next;
    }

    return temp;
}

//  prints all the subjects and their corresponding teachers in the linked list
void display_all_subjects(struct Subject **head) {
    if (head == NULL || *head == NULL) {
        printf("No subjects available.\n");
        return;
    }

    struct Subject *temp = *head;
    while (temp != NULL) {
        printf("Subject: %s, Teacher: %s\n", temp->subject_name, temp->teacher_fullname);
        temp = temp->next;
    }
}


// struct Student *create_student(char **student_name, char **subject_name, char **grade)
// {
//     struct Student *new_student = malloc(sizeof(struct Student));

//     if (new_student == NULL)
//     {
//         printf("memory allocation failed\n");
//         return NULL;
//     }

//     strncpy(new_student->student_name, *student_name, strlen(*student_name));

//     return new_student;
// }


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

int main(void) {
    struct Subject *subject_head = NULL; // Head of subject linked list
    struct Student *student_head = NULL; // Head of student linked list

    // Add subjects
    char *subj_name = "Maths";
    char *teacher_fullname = "John";
    add_subject(&subject_head, &subj_name, &teacher_fullname);

    char *subj_name2 = "English";
    char *teacher_fullname2 = "Jane";
    add_subject(&subject_head, &subj_name2, &teacher_fullname2);

    // Display all subjects
    printf("Subjects:\n");
    display_all_subjects(&subject_head);

    // Find a subject
    char *search_subject = "Maths";
    struct Subject *found = find_subject(&subject_head, &search_subject);
    if (found != NULL) {
        printf("Found Subject: %s, Teacher: %s\n", found->subject_name, found->teacher_fullname);
    } else {
        printf("Subject not found\n");
    }

    // Add students
    char *stu_name = "John Doe";
    char *grade = "A";
    add_student(&student_head, &stu_name, &subj_name, &grade);

    // Future: Display students

    return 0;
}
