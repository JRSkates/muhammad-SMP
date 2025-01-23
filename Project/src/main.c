#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Subject
{
    // Seg Fault
    // char *subject_name;
    // char *teacher_fullname;
    char subject_name[20];
    char teacher_fullname[20];
    struct Subject *next;
};

struct subject_grade
{
    struct Subject *subj_ptr;
    char grade[1];
    struct subject_grade *next;
};

struct Student
{
    char *student_name;
    struct subject_grade *subj_grade_ptr; // ptr to a linked list of subject grade
    struct Student *next;
};

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
