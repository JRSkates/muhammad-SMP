#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "students.h"
#include "subjects.h"

void display_menu() {
    printf("\n--- School Management System ---\n");
    printf("1. Add Student\n");
    printf("2. Add Subject & Teacher\n");
    printf("3. Add Subject & Grade to Student\n");
    printf("4. Find Students by Subject\n");
    printf("5. Find Teacher of Subject\n");
    printf("6. Student Grade by Subject\n");
    printf("7. Exit\n");
    printf("--------------------------------\n");
    printf("Enter your choice: ");
}
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Discard characters until a newline or EOF is found
}

int validate_number(const char *input) {
    // Check if the input is a valid number
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit(input[i]) && input[i] != '\n') {
            return 0; // Not a valid number
        }
    }
    return 1; // Valid number
}

int main() {
    struct Subject *subject_head = NULL; // Head of subject linked list
    struct Student *student_head = NULL; // Head of student linked list

    int running = 1;
    char buffer[100]; // Buffer to store user input
    int user_choice;

    while (running) {
        display_menu();

        // Read input using fgets
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Error reading input. Exiting.\n");
            break;
        }

        // Validate the input
        if (!validate_number(buffer)) {
            printf("Invalid input. Please enter a number.\n");
            continue; // Prompt the menu again
        }

        // Convert the validated input to an integer
        user_choice = atoi(buffer);
        switch (user_choice) {
            case 1: { 
                // Add Student
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

                clear_input_buffer();
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

                clear_input_buffer();
                break;
            }
            
            case 3: { 
                // Add subject and grade to student
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

                clear_input_buffer();
                break;
            }
            case 4: {
                // Find Students by Subject
                char *subject_name = malloc(50);

                if (!subject_name) {
                    printf("Memory allocation failed.\n");
                    break;
                }

                printf("\nEnter Subject Name: ");
                scanf(" %[^\n]", subject_name);

                find_students_of_subject(&student_head, &subject_head, subject_name);

                free(subject_name);

                clear_input_buffer();
                break;
            }
            case 5: {
                // Find Teacher of Subject
                char *subject_name = malloc(50);

                if (!subject_name) {
                    printf("Memory allocation failed.\n");
                    break;
                }

                printf("\nEnter Subject Name: ");
                scanf(" %[^\n]", subject_name);
                // printf("[DEBUG] Subject Name Entered: %s\n", subject_name);

                find_teacher_of_subject(&subject_head, &subject_name);
                free(subject_name);

                clear_input_buffer();
                break;
            }
            case 6: {
                // Student Grade by Subject
                char *subject_name = malloc(50);
                char *student_name = malloc(50);

                if (!subject_name || !student_name) {
                    printf("Memory allocation failed.\n");
                    break;
                }

                printf("\nEnter Student Name: ");
                scanf(" %[^\n]", student_name);

                printf("\nEnter Subject Name: ");
                scanf(" %[^\n]", subject_name);
                // printf("[DEBUG] Subject Name Entered: %s\n", subject_name);

                find_student_grade(&student_head, student_name, subject_name);

                free(subject_name);
                free(student_name);

                clear_input_buffer();
                break;
            }
            case 7: {
                 // Exit program
                printf("Goodbye!\n");
                running = 0;
                break;
            }
            default:
                printf("Invalid choice. Please try again.\n");

        }
    }

    return 0;
}
