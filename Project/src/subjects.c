#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "subjects.h"

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
    struct Subject *new_subj = malloc(sizeof(struct Subject));
    if (new_subj == NULL) {
        printf("Memory allocation failed for new subject.\n");
        return;
    }

    // Copy subject name and teacher name
    strncpy(new_subj->subject_name, *subject_name, sizeof(new_subj->subject_name) - 1);
    new_subj->subject_name[sizeof(new_subj->subject_name) - 1] = '\0'; // Null-terminate
    strncpy(new_subj->teacher_fullname, *teacher_fullname, sizeof(new_subj->teacher_fullname) - 1);
    new_subj->teacher_fullname[sizeof(new_subj->teacher_fullname) - 1] = '\0'; // Null-terminate

    new_subj->next = NULL; // Initialize the next pointer
    printf("New subject created: %s, Teacher: %s.\n", new_subj->subject_name, new_subj->teacher_fullname);

    if (*head == NULL) {
        *head = new_subj;
        // printf("Subject '%s' added as the first subject.\n", new_subj->subject_name);
        return;
    }

    struct Subject *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_subj;
    // printf("Subject '%s' added to the list.\n", new_subj->subject_name);
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
void find_teacher_of_subject(struct Subject **head, char **subject_name) {
    // Check if the subject exists
    struct Subject *subject = find_subject(head, subject_name);

    if (subject == NULL) {
        printf("\nSubject Not Found.\n");
    } else {
        printf("\nTeacher of '%s' is: %s\n", *subject_name, subject->teacher_fullname);
    }
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