#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "students.h"
#include "subjects.h"

void display_menu() {
    printf("\n--- School Management System ---\n");
    printf("1. Add Student\n");
    printf("2. Add Teacher\n");
    printf("3. Add Subject to Student\n");
    printf("4. Assign a Grade\n");
    printf("5. Find Students by Subject\n");
    printf("6. Find Teacher of Subject\n");
    printf("7. Student Grade by Subject\n");
    printf("8. Students of Teacher?\n");
    printf("9. Exit\n");
    printf("--------------------------------\n");
    printf("Enter your choice: ");
}

int main(void) {
    struct Subject *subject_head = NULL; // Head of subject linked list
    struct Student *student_head = NULL; // Head of student linked list

    int user_choice;
    int running = 1;
    // char running = 1;

    while (running) {
        display_menu();
        scanf("%d", &user_choice);
        switch (user_choice) {
            case 1: { 
                char *student_name = malloc(50);

                if (!student_name) {
                    printf("Memory allocation failed.\n");
                    break;
                }

                printf("\nEnter Student Name: ");
                scanf(" %[^\n]", student_name);

                // Check if the student already exists
                struct Student *student = find_student(&student_head, &student_name); // Pass address of student_name

                if (student == NULL) {
                    // Add the student to the list
                    add_student(&student_head, &student_name); // Pass address of student_name

                    // Display full student list
                    display_all_students(&student_head);
                } else {
                    printf("\nStudent '%s' already exists.\n", student_name);
                }

                // Free allocated memory
                free(student_name);

                break;
            }
            case 2: {
                // Add teacher
                char *subject_name = malloc(50);
                char *teacher_name = malloc(50);

                if (!subject_name ||!teacher_name) {
                    printf("Memory allocation failed.\n");
                    break;
                }
                
                printf("\nEnter Subject Name: ");
                scanf(" %[^\n]", subject_name);
                // printf("[DEBUG] Subject Name Entered: %s\n", subject_name);

                // Check if the subject exists
                struct Subject *subject = find_subject(&subject_head, &subject_name);

                if (subject == NULL) {
                    printf("\nEnter Teacher's Full Name: ");
                    scanf(" %[^\n]", teacher_name);
                    // printf("[DEBUG] Teacher Name Entered: %s\n", teacher_name);

                    add_subject(&subject_head, &subject_name, &teacher_name);
                    // printf("Subject '%s' added with Teacher '%s'.\n", subject_name, teacher_name);

                    subject = find_subject(&subject_head, &subject_name);
                } else {
                    printf("\nSubject '%s' already exists.\n", subject_name);
                }

                printf("\n");
                display_all_subjects(&subject_head);

                free(subject_name);
                free(teacher_name);
                break;
            }
            
            case 3: { 
                // Add subject to student
                char *student_name = malloc(50);
                char *subject_name = malloc(50);
                char *teacher_name = malloc(50);

                if (!student_name || !subject_name || !teacher_name) {
                    printf("Memory allocation failed.\n");
                    break;
                }

                printf("\nEnter Student Name: ");
                scanf(" %[^\n]", student_name);

                // Find the student
                struct Student *student = find_student(&student_head, &student_name);
                if (student == NULL) {
                    printf("\nStudent '%s' does not exist. Please add the student first.\n", student_name);
                    free(student_name);
                    free(subject_name);
                    free(teacher_name);
                    break;
                }

                printf("\nEnter Subject Name: ");
                scanf(" %[^\n]", subject_name);

                // Find the subject
                struct Subject *subject = find_subject(&subject_head, &subject_name);
                if (subject == NULL) {
                    printf("\nSubject '%s' does not exist. Please add a teacher for this subject.\n", subject_name);
                    printf("\nEnter Teacher's Full Name: ");
                    scanf(" %[^\n]", teacher_name);

                    // Add the new subject
                    add_subject(&subject_head, &subject_name, &teacher_name);
                    subject = find_subject(&subject_head, &subject_name);
                }

                // Create a new subject_grade
                struct subject_grade *new_grade = malloc(sizeof(struct subject_grade));
                if (new_grade == NULL) {
                    printf("Memory allocation failed for subject_grade.\n");
                    free(student_name);
                    free(subject_name);
                    free(teacher_name);
                    break;
                }

                new_grade->subj_ptr = subject;
                printf("\nEnter Grade for '%s': ", subject_name);
                scanf(" %[^\n]", new_grade->grade);
                new_grade->next = student->subj_grade_ptr;
                student->subj_grade_ptr = new_grade;

                printf("\nSubject '%s' with Grade '%s' added to Student '%s'.\n", subject_name, new_grade->grade, student_name);

                // Free dynamically allocated memory
                free(student_name);
                free(subject_name);
                free(teacher_name);

                break;
            }
            case 4:
                // Assign a Grade
                // printf("\nEnter Grade: ");
                // scanf(" %[^\n]", grade);
                // printf("[DEBUG] Grade Entered: %s\n", grade);

                // Find the student
                // struct Student *student = find_student(&student_head, &student_name);
                // if (student != NULL) {
                //     struct subject_grade *new_grade = malloc(sizeof(struct subject_grade));
                //     if (new_grade == NULL) {
                //         printf("[DEBUG] Memory allocation failed for subject_grade.\n");
                //         break;
                //     }

                //     // Link the subject and grade to the student
                //     new_grade->subj_ptr = subject;
                //     strcpy(new_grade->grade, grade);
                //     new_grade->next = student->subj_grade_ptr;
                //     student->subj_grade_ptr = new_grade;

                //     printf("[DEBUG] Finished creating subject_grade.\n");
                //     printf("\nSubject '%s' with Grade '%s' added to Student '%s'.\n", subject_name, grade, student_name);
                // } else {
                //     printf("[DEBUG] Error: Student not found after adding.\n");
                // }
                break;
            case 5:
                // Find Student by Subject
                break;
            case 6: {
                // Find Teacher of Subject
                break;
            }
            case 7: {
                // Student Grade by Subject
                break;
            }
            case 8:
                // Student of Teacher?
                break;
            case 9: {
                 // Exit program
                printf("Goodbye!\n");
                running = 0;
                break;
            }
            default:
                printf("Invalid choice. Please try again.\n");

        }
    }
    // Add subjects
    // char *subj_name = "Maths";
    // char *teacher_fullname = "John";
    // add_subject(&subject_head, &subj_name, &teacher_fullname);

    // char *subj_name2 = "English";
    // char *teacher_fullname2 = "Jane";
    // add_subject(&subject_head, &subj_name2, &teacher_fullname2);

    // // Display all subjects
    // printf("Subjects:\n");
    // display_all_subjects(&subject_head);

    // // Find a subject
    // char *search_subject = "Maths";
    // struct Subject *found = find_subject(&subject_head, &search_subject);
    // if (found != NULL) {
    //     printf("Found Subject: %s, Teacher: %s\n", found->subject_name, found->teacher_fullname);
    // } else {
    //     printf("Subject not found\n");
    // }

    // // Add students
    // char *stu_name = "John Doe";
    // char *grade = "A";
    // add_student(&student_head, &stu_name, &subj_name, &grade);

    // // Future: Display students

    return 0;
}
