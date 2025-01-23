#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "students.h"
#include "subjects.h"

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
